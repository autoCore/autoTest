#include <stdlib.h>
#include <string.h>
#if !(defined __CMAKE_SYSTEM__)
#include <arm_acle.h>
#endif

#include "plat_basic_api.h"
#include "int_api.h"
#include "asr_chip_regs.h"

#include "sched.h"
#include "config.h"
#include "semaphore.h"
#include "archtimer_api.h"
#include "arch_helpers.h"
#include "mmu_api.h"
#include "cci_api.h"

//#define DDBUG
extern volatile unsigned long pholding_pen;

//external
extern void save_stack_current_sched(unsigned long _tmp);
extern unsigned long get_stack_current_sched(void);

static long min_timer_value = 0;
static sem_t ready_secondary_cpus_semaphore;
static unsigned int numThreads = 0;
static volatile int runningThreadsID[] = {
	NO_THREAD, NO_THREAD, NO_THREAD, NO_THREAD, NO_THREAD,
	NO_THREAD, NO_THREAD, NO_THREAD, NO_THREAD, NO_THREAD,
	NO_THREAD, NO_THREAD, NO_THREAD, NO_THREAD, NO_THREAD,	/*Allow 15 sched core */
};


static PCB_t *pendingPCB[MAX_THREADS + TOTAL_CORES] = {0};
static PCB_t threadsPCBs[MAX_THREADS + TOTAL_CORES] = {0};

static unsigned int tailPCB = 0;
static unsigned int headPCB = 0;

static sched_mutex_t queue_mux;
static unsigned int pendingPCBempty = TRUE;
static unsigned int pendingPCBfull = FALSE;

/* Spare thread handlers for threads already on CPUs */
static sched_t current_threads_handlers[TOTAL_CORES]= {0};

/*Define threads(number, stacks) for the platform*/
#define _NUMNUM_THREADS_	(MAX_THREADS + TOTAL_CORES)

static unsigned char threads_stack_space[_NUMNUM_THREADS_][THREAD_STACK_SIZE] __attribute__ ((aligned(16)));
static char *const threads_stack_bottom = (char *const)((&threads_stack_space[0][0] +
	      (THREAD_STACK_SIZE * _NUMNUM_THREADS_)));

static unsigned long get_thread_stack(int id)
{
	unsigned long addr = 0x0;

	if (id + 1 > _NUMNUM_THREADS_)
		while (1) ;

	addr = (long)threads_stack_bottom - id * THREAD_STACK_SIZE;
	return addr;
}

static __inline void acquire_spinlock(volatile spinlock_t * plock)
{
	spin_lock(plock);
	dsb();
}

static __inline unsigned int acquire_trylock(volatile spinlock_t * plock)
{
	unsigned int lock_state;

	lock_state = spin_try_lock(plock);
	dsb();
	return lock_state;
}

static __inline void release_spinlock(volatile spinlock_t * plock)
{
	dsb();
	spin_unlock(plock);
}


static __inline void __sched_save(unsigned long stack_addr, unsigned long dst)
{
	memcpy((void *)dst, (void *)stack_addr, _CTX_SIZE);
#ifdef DDBUG
	trace("__sched_save stack_addr new = 0x%x\n",stack_addr);
#endif
}

static __inline void __sched_restore(unsigned long stack_addr,
				     unsigned long src)
{
	memcpy((void *)stack_addr, (void *)src, _CTX_SIZE);
#ifdef DDBUG
	trace("__sched_restore stack_addr new = 0x%x\n",stack_addr);
#endif
}

int sched_mutex_init(sched_mutex_t * mutex, void *attr)
{
	if (mutex == NULL)
		return EINVAL;

	mutex->lock.lock = FREE;
	mutex->initialized = TRUE;

	return 0;
}

int sched_mutex_destroy(sched_mutex_t * mutex)
{
	if (mutex == NULL)
		return EINVAL;

	if (mutex->lock.lock != FREE)
		return 2;

	mutex->initialized = FALSE;

	return 0;
}

int sched_mutex_lock(sched_mutex_t * mutex)
{
	if ((mutex == NULL) || (mutex->initialized == FALSE))
		return EINVAL;

	acquire_spinlock(&mutex->lock);

	return 0;
}

int sched_mutex_unlock(sched_mutex_t * mutex)
{
	if ((mutex == NULL) || (mutex->initialized == FALSE))
		return EINVAL;

	release_spinlock(&mutex->lock);

	return 0;
}

int sched_mutex_trylock(sched_mutex_t * mutex)
{
	if ((mutex == NULL) || (mutex->initialized == FALSE))
		return EINVAL;

	if (acquire_trylock((void *)&mutex->lock) == FREE)
		return 0;
	else
		return 2;
}

int sched_cond_init(sched_cond_t * cond, const void * attr)
{
	if (cond == NULL)
		return EINVAL;

	cond->cond = FREE;
	cond->blockedThreadsID = NULL;
	cond->blockedThreadsNum = 0;
	sched_mutex_init(&cond->blockedMutex, NULL);

	cond->initialized = TRUE;

	return 0;
}

int sched_cond_signal(sched_cond_t * cond)
{
	if ((cond == NULL) || (cond->initialized == FALSE))
		return EINVAL;

	sched_mutex_lock(&cond->blockedMutex);

	if (cond->blockedThreadsNum == 0) {
		sched_mutex_unlock(&cond->blockedMutex);
		return 0;
	}

	/* Wake up one of the blocked threads */
	threadsPCBs[cond->blockedThreadsID[0]].handler->sleeping = FALSE;

	memmove(cond->blockedThreadsID,
		cond->blockedThreadsID + sizeof(unsigned int),
		(cond->blockedThreadsNum - 1) * sizeof(unsigned int));

	cond->blockedThreadsID =
	    realloc(cond->blockedThreadsID,
		    (cond->blockedThreadsNum - 1) * sizeof(unsigned int));

	if (--cond->blockedThreadsNum == 0)
		cond->cond = FREE;

	sched_mutex_unlock(&cond->blockedMutex);

	return 0;
}

int sched_cond_broadcast(sched_cond_t * cond)
{
	unsigned int i;

	if ((cond == NULL) || (cond->initialized == FALSE))
		return EINVAL;

	sched_mutex_lock(&cond->blockedMutex);

	if (cond->blockedThreadsNum == 0) {
		sched_mutex_unlock(&cond->blockedMutex);
		return 0;
	}

	/* Wake up one of the blocked threads */
	for (i = 0; i < cond->blockedThreadsNum; i++) {
		threadsPCBs[cond->blockedThreadsID[i]].handler->sleeping =
		    FALSE;
	}

	cond->blockedThreadsNum = 0;

	cond->cond = FREE;

	free(cond->blockedThreadsID);

	sched_mutex_unlock(&cond->blockedMutex);

	return 0;
}

int sched_cond_wait(sched_cond_t * cond, sched_mutex_t * mutex)
{
	unsigned int calling_thread_ID, flags;

	if (cond == NULL || mutex == NULL)
		return EINVAL;

	if (mutex->lock.lock == FREE)
		return EINVAL;

	flags = local_irq_save();

	calling_thread_ID = arm_read_thread_id();

	sched_mutex_lock(&cond->blockedMutex);

	/* Add calling thread to list of threads blocked on this condition variable */
	cond->blockedThreadsID =
	    realloc(cond->blockedThreadsID,
		    (cond->blockedThreadsNum + 1) * sizeof(unsigned int));

	if (cond->blockedThreadsID == NULL) {
		sched_mutex_unlock(&cond->blockedMutex);
		return EERROR;
	}

	cond->blockedThreadsID[cond->blockedThreadsNum] = calling_thread_ID;

	cond->blockedThreadsNum++;

	/* Set the calling thread as SLEEPING for scheduling purposes */
	threadsPCBs[calling_thread_ID].handler->sleeping = TRUE;

	dsb();

	sched_mutex_unlock(mutex);

	/* Set the condition variable to LOCKED state */
	cond->cond = LOCKED;

	sched_mutex_unlock(&cond->blockedMutex);

	local_irq_restore(flags);

	/* Do nothing until timeslice expires. We must ensure that until this
	   thread is awoken, we are not going any further than here */
	while (threadsPCBs[calling_thread_ID].handler->sleeping == TRUE) {
		wfi();
	}

	sched_mutex_lock(mutex);

	return 0;
}

int sched_cond_destroy(sched_cond_t * cond)
{
	if (cond == NULL)
		return EINVAL;

	if (cond->cond != FREE)
		return 2;

	cond->initialized = FALSE;

	sched_mutex_lock(&cond->blockedMutex);

	free(cond->blockedThreadsID);

	cond->blockedThreadsNum = 0;

	sched_mutex_unlock(&cond->blockedMutex);

	sched_mutex_destroy(&cond->blockedMutex);

	return 0;
}

static void scheduler(void)
{
	unsigned int cpuid, parserPCB, currentThreadID;
	int i;
	PCB_t *tempPendingPCB[MAX_THREADS + TOTAL_CORES];
	unsigned int ptempPendingPCB = 0;
	unsigned long stack_addr = 0;
	long _tmp_time = 0;

	cpuid = arm_get_coreid();

	if (sched_mutex_trylock(&queue_mux) == 2)
		return;

#ifdef DDBUG
	trace("scheduler inlock: coreid = 0x%x, pendingPCBempty = %d\r\n", cpuid, pendingPCBempty);
#endif

	if (min_timer_value == 0) {
		_tmp_time = getPhysicalCount();
	}
	if (!pendingPCBempty) {

		currentThreadID = arm_read_thread_id();
		stack_addr = get_stack_current_sched();

		__sched_save(stack_addr, (long)(&threadsPCBs[currentThreadID]));

#ifdef DDBUG
		trace("current cpu stack_addr = 0x%x, currentThreadID =%d, elr= 0x%x,x30=0x%x\r\n", stack_addr, currentThreadID, threadsPCBs[currentThreadID].elr_el3, threadsPCBs[currentThreadID].x30);
#endif
		/* Add current context to waiting queue */
		pendingPCB[headPCB] = &(threadsPCBs[currentThreadID]);
		headPCB = (headPCB + 1) % (MAX_THREADS + TOTAL_CORES);
#ifdef DDBUG
		trace("headpcb = %d, tailpcb = %d, pendingPCB[0] = 0x%x\n\r",headPCB,tailPCB,pendingPCB[0]);
#endif
		/* Remove joined and cancelled threads */
		parserPCB = tailPCB;

		do {
			if (pendingPCB[parserPCB]->active == FALSE) {	/* Discard (de-schedule) */
				dsb();
				sem_post(&(pendingPCB[parserPCB]->handler->descheduled_semaphore));
				pendingPCB[parserPCB]->handler = NULL;

				numThreads--;
				if (numThreads == 0)
					pendingPCBempty = TRUE;
			} else { /* Keep */
				tempPendingPCB[ptempPendingPCB] = pendingPCB[parserPCB];
				ptempPendingPCB++;
			}

			parserPCB = (parserPCB + 1) % (MAX_THREADS + TOTAL_CORES);
		} while (parserPCB != headPCB);

		/* Reset headPCB to what will be the 'new' next available entry in pendingPCB[] */
		headPCB = (tailPCB + ptempPendingPCB) % (MAX_THREADS + TOTAL_CORES);
#ifdef DDBUG
		trace("Reset headPCB to what, headPCB= %d\n\r",headPCB);
#endif
		parserPCB = (tailPCB + ptempPendingPCB - 1) % (MAX_THREADS + TOTAL_CORES);

		/* Sleeping threads with lowest priority */
		for (i = ptempPendingPCB - 1; i >= 0; i--) {
			if (tempPendingPCB[i]->handler->sleeping == TRUE) {
				pendingPCB[parserPCB] = tempPendingPCB[i];
				tempPendingPCB[i] = NULL;

				if (parserPCB > 0)
					parserPCB--;
				else
					parserPCB = (MAX_THREADS + TOTAL_CORES - 1);
			}
		}

		/* Then dummy threads */
		for (i = ptempPendingPCB - 1; i >= 0; i--) {
			if (tempPendingPCB[i] != NULL)	/* Test since we might have NULLed some entries in the previous iteration */
				if (tempPendingPCB[i]->handler->dummy_thread == TRUE) {
					pendingPCB[parserPCB] = tempPendingPCB[i];
					tempPendingPCB[i] = NULL;

					if (parserPCB > 0)
						parserPCB--;
					else
						parserPCB = (MAX_THREADS + TOTAL_CORES - 1);
				}
		}

		/* Finally the rest (valid work items) */
		for (i = ptempPendingPCB - 1; i >= 0; i--) {
			if (tempPendingPCB[i] != NULL) {	/* Test since we might have NULLed some entries in the previous iterations */
				pendingPCB[parserPCB] = tempPendingPCB[i];
				tempPendingPCB[i] = NULL;

				if (parserPCB > 0)
					parserPCB--;
				else
					parserPCB = (MAX_THREADS + TOTAL_CORES - 1);
			}
		}

		/* Install next context in place of the ones we just scheduled out */
		save_stack_current_sched(pendingPCB[tailPCB]->sp);
		__sched_restore((long)(pendingPCB[tailPCB]->sp), (long)(pendingPCB[tailPCB]));
		runningThreadsID[cpuid] = pendingPCB[tailPCB]->handler->ID;	/* Keep track of current thread on CPUs */
#ifdef DDBUG
		trace("arm_write_thread_id id =%d, tailPCB=%d\n\r", pendingPCB[tailPCB]->handler->ID,tailPCB);
#endif
		arm_write_thread_id(pendingPCB[tailPCB]->handler->ID);

		pendingPCB[tailPCB] = NULL;
		tailPCB = (tailPCB + 1) % (MAX_THREADS + TOTAL_CORES);
	}
#ifdef DDBUG
	trace("scheduler:exit, core = 0x%x\r\n", cpuid);
#endif

	if (min_timer_value == 0) {
		min_timer_value = getPhysicalCount() - _tmp_time;
	}
	sched_mutex_unlock(&queue_mux);
}

/*
 * Thread wrapper.
 *
 */
#if !(defined __CMAKE_SYSTEM__)
static __declspec(noreturn) void thread_wrapper(void *(*start_routine) (void *), void *arg, sched_t * thread)
#else
static void thread_wrapper(void *(*start_routine) (void *), void *arg,
		    sched_t * thread) __attribute__ ((noreturn));
static void thread_wrapper(void *(*start_routine) (void *), void *arg, sched_t * thread)
#endif
{
	if (start_routine != NULL)
		thread->return_value = (start_routine) (arg);

	if (thread->detach_state == PTHREAD_CREATE_JOINABLE) {
		sem_post(&(thread->finished_semaphore));
	} else {		/* PTHREAD_CREATE_DETACHED */

		sem_destroy(&(thread->finished_semaphore));

		sched_mutex_lock(&queue_mux);

		if (pendingPCBfull == TRUE)
			pendingPCBfull = FALSE;

		/* Mark as not-active */
		threadsPCBs[thread->ID].active = FALSE;

		sched_mutex_unlock(&queue_mux);

		sem_wait(&(thread->descheduled_semaphore));
		sem_destroy(&(thread->descheduled_semaphore));
	}
	while (1)
#ifdef FORCE_RESCHEDULE
		ipi_broadcast_self(SCHEDULER_IPI)	/* Force reschedule */
#endif
	;
}

int sched_create(sched_t * thread, const sched_attr_t * attr,
		 void *(*start_routine) (void *), void *arg)
{
	sched_mutex_lock(&queue_mux);

	/* Initialize the next available PCB in the queue with the new thread */
	if (numThreads >= MAX_THREADS) {
		sched_mutex_unlock(&queue_mux);
		return -1;
	} else {
		unsigned int i = 0;
		while (i < MAX_THREADS) {
			if (threadsPCBs[i].handler == NULL)
				break;
			i++;
		}

		threadsPCBs[i].handler = thread;

		if (attr != NULL) {
			thread->detach_state = attr->detach_state;
		} else {
			thread->detach_state = PTHREAD_CREATE_JOINABLE;	/* Default */

			/* Initialize scheduler's thread-handling semaphore */
			if (sem_init(&(threadsPCBs[i].handler->finished_semaphore), 0) != 0)
				trace("\nError: initializing semaphore (threadsPCBs[i].handler->finished_semaphore");
		}

		/* Initialize scheduler's thread-handling semaphore */
		if (sem_init(&(threadsPCBs[i].handler->descheduled_semaphore), 0) != 0)
			trace("\nError: initializing semaphore (threadsPCBs[i].handler->descheduled_semaphore");

		threadsPCBs[i].x0 = (unsigned int)start_routine;
		threadsPCBs[i].x1 = (unsigned int)arg;
		threadsPCBs[i].x2 = (unsigned int)(threadsPCBs[i].handler);
		threadsPCBs[i].x3 = (unsigned int)3;
		threadsPCBs[i].x4 = (unsigned int)4;
		threadsPCBs[i].x5 = (unsigned int)5;
		threadsPCBs[i].x6 = (unsigned int)6;
		threadsPCBs[i].x7 = (unsigned int)7;
		threadsPCBs[i].x8 = (unsigned int)8;
		threadsPCBs[i].x9 = (unsigned int)9;
		threadsPCBs[i].x10 = (unsigned int)0x10;
		threadsPCBs[i].x11 = (unsigned int)0x11;
		threadsPCBs[i].x12 = (unsigned int)0x12;
		threadsPCBs[i].x13 = (unsigned int)0x13;
		threadsPCBs[i].x14 = (unsigned int)0x14;
		threadsPCBs[i].x15 = (unsigned int)0x15;
		threadsPCBs[i].x16 = (unsigned int)0x16;
		threadsPCBs[i].x17 = (unsigned int)0x17;
		threadsPCBs[i].x18 = (unsigned int)0x18;
		threadsPCBs[i].x19 = (unsigned int)0x19;
		threadsPCBs[i].x20 = (unsigned int)0x20;
		threadsPCBs[i].x21 = (unsigned int)0x21;
		threadsPCBs[i].x22 = (unsigned int)0x22;
		threadsPCBs[i].x23 = (unsigned int)0x23;
		threadsPCBs[i].x24 = (unsigned int)0x24;
		threadsPCBs[i].x25 = (unsigned int)0x25;
		threadsPCBs[i].x26 = (unsigned int)0x26;
		threadsPCBs[i].x27 = (unsigned int)0x27;
		threadsPCBs[i].x28 = (unsigned int)0x28;
		threadsPCBs[i].x29 = (unsigned int)0x29 + i;

		threadsPCBs[i].x30 = (unsigned int)thread_wrapper;
		threadsPCBs[i].elr_el3 = (unsigned int)thread_wrapper;
		threadsPCBs[i].bak = (unsigned int)thread_wrapper;

		threadsPCBs[i].sp = get_thread_stack(i) -0x130;
		threadsPCBs[i].SPSR_EL3 = 0x6000000d;
		threadsPCBs[i].scr_el3 = 0xc0e;
		threadsPCBs[i].DAIF = 0;
		threadsPCBs[i].SPSel = 0x1;

		threadsPCBs[i].active = TRUE;
		threadsPCBs[i].handler->ID = i;
		threadsPCBs[i].handler->start_routine = (void *)start_routine;
		threadsPCBs[i].handler->sleeping = FALSE;

		/* Initialize the thread not to be a dummy thread: this is valuable information when scheduling */
		threadsPCBs[i].handler->dummy_thread = FALSE;

		/* Add the thread to the waiting list */
		pendingPCB[headPCB] = &(threadsPCBs[i]);

		headPCB = (headPCB + 1) % (MAX_THREADS + TOTAL_CORES);

		numThreads++;

		if (pendingPCBempty == TRUE)
			pendingPCBempty = FALSE;

		if (numThreads == MAX_THREADS)
			pendingPCBfull = TRUE;
#ifdef DDBUG
		trace("sched_create: Now numThreads = %d, headPCB = %d\n",numThreads, headPCB);
#endif
		sched_mutex_unlock(&queue_mux);
	}

	return 0;
}

int sched_join_f(sched_t * thread, void **value_ptr)
{
	/* Wait on semaphore until thread terminates */
	sem_wait(&(thread->finished_semaphore));

	/* Making the thread-joining a Critical Section */
	sched_mutex_lock(&queue_mux);

	if (pendingPCBfull == TRUE)
		pendingPCBfull = FALSE;

	sem_destroy(&(thread->finished_semaphore));

	/* If we want to catch the return value */
	if (value_ptr != NULL)
		*value_ptr = thread->return_value;

	/* Mark as not-active */
	threadsPCBs[thread->ID].active = FALSE;

	sched_mutex_unlock(&queue_mux);

	sem_wait(&(thread->descheduled_semaphore));
	sem_destroy(&(thread->descheduled_semaphore));

	return 0;
}

int sched_get_sp();
static void __timer_isr(int IntNum, int IntSrc)
{
	int cpuid = arm_get_coreid();

	setNSEL1PhysicalTimerCtrl(0);

	scheduler();

	setNSEL1PhysicalTimerCtrl((1 << 0));
	setNSEL1PhysicalCompValue(getPhysicalCount() + TIMESLICE + min_timer_value);
//	if (min_timer_value >= TIMESLICE)
//		trace("Please adjust your sched timer slice min_timer_value = 0x%x\n\r", min_timer_value);
}

//#define BOOT_CORES (BIT_WAKEUP_CORE0 | BIT_WAKEUP_CORE1 | BIT_WAKEUP_CORE2 | BIT_WAKEUP_CORE3 | BIT_WAKEUP_CORE4 |	\
//		BIT_WAKEUP_CORE5 | BIT_WAKEUP_CORE6 | BIT_WAKEUP_CORE7 | BIT_WAKEUP_CORE8 | BIT_WAKEUP_CORE9)
#ifndef BOOT_CORES
#define BOOT_CORES ((1 << (TOTAL_CORES)) -1)/*transltate it to cpu msk*/
#endif

static int long core_boot_msk = 0;
static void __cores_boot(unsigned int cpu_id_msk, unsigned long boot_addr_low_32, unsigned long boot_addr_high_32)
{
	trace("boot_secondary_cpu: boot cpu id msk is 0x%x\n\r",cpu_id_msk);

	if (cpu_id_msk <= ((1<<10)-1)) {/*Only support boot AP's core now*/
		REG32(REG_CIU_RST_VEC_BASE_ADDRESS) = boot_addr_low_32;
		REG32(REG_CIU_RST_VEC_BASE_ADDRESS_HIGH) = boot_addr_high_32;
		CHIP_REG_OR(REG_PMU_PMU_CAP_COREx_WAKEUP0,cpu_id_msk);
	}
	core_boot_msk = cpu_id_msk;
}

void sched_threads_init(void)
{
	unsigned int i, j = 0;
	unsigned int cpuid;

	unsigned int slave_if[] = {
		1,		/*Cluster 0 */
		2,		/*Cluster 1 */
		3,		/*Cluster 2 */
	};

	cpuid = arm_get_coreid();

	__cores_boot(BOOT_CORES, 0, 0);

	arm_write_thread_id(cpuid + MAX_THREADS);

	sched_mutex_init(&queue_mux, NULL);

	sem_init(&ready_secondary_cpus_semaphore, 0);

	for (i = 0; i < MAX_THREADS; i++) {
		memset(&threadsPCBs[i], 0x00, sizeof(PCB_t));
		threadsPCBs[i].active = FALSE;
		threadsPCBs[i].handler = NULL;
	}

	for (i = 0; i < MAX_THREADS; i++) {
		pendingPCB[i] = NULL;
	}

	runningThreadsID[cpuid] = arm_read_thread_id();

	for (j = 0, i = MAX_THREADS; i < (MAX_THREADS + TOTAL_CORES); i++, j++) {
		threadsPCBs[i].handler = &current_threads_handlers[j];
		threadsPCBs[i].handler->ID = i;
		threadsPCBs[i].active = TRUE;
		threadsPCBs[i].handler->sleeping = FALSE;
	}

	/* Mark the dummy threads */
	for (i = 0; i < MAX_THREADS; i++) {	/* All threads */
//		threadsPCBs[i].handler->dummy_thread = FALSE;
	}

	for (i = 0; i < TOTAL_CORES; i++) {	/* All threads on secondary CPUs */
		if (i == cpuid)
			threadsPCBs[i + MAX_THREADS].handler->dummy_thread = FALSE;	/* Primary CPU */
		else
			threadsPCBs[i + MAX_THREADS].handler->dummy_thread = TRUE;	/* Secondary */
	}

	numThreads = 0;

	pendingPCBempty = TRUE;
	pendingPCBfull = FALSE;
	tailPCB = 0;
	headPCB = 0;

	arch_timer_init();
	archtimer_setup_irq_secure(0, __timer_isr, cpuid);

	plat_enable_cacheable();

	arm_enable_snoop_interface(1);

	if (core_boot_msk & 0xf)
		cci_enable_snoop_dvm_reqs_aux(0);
	if (core_boot_msk & 0xf0)
		cci_enable_snoop_dvm_reqs_aux(1);
	if (core_boot_msk & 0xff0)
		cci_enable_snoop_dvm_reqs_aux(2);

	pholding_pen = 0xef;
	dsb();
	flush_dcache_range((unsigned long)&pholding_pen, sizeof(pholding_pen));

#if 0//FIXME: we can not wait it, because don't know how many cores are there. And because We have put the holding pen so later.
	/* Wait for secondary CPUs to signal they are ready. */
	for (i = 0; i < TOTAL_CORES - 1; i++)
		sem_wait(&ready_secondary_cpus_semaphore);
#endif
	dsb();

	pholding_pen = 0x00;
	/* Kick off the scheduler */
	setNSEL1PhysicalCompValue(getPhysicalCount() + 1);
	setNSEL1PhysicalTimerCtrl((1 << 0));
	trace("sched_threads_init\n\r");
}

#if !(defined __CMAKE_SYSTEM__)
void __declspec(noreturn) __sched_idle(void)
#else
/*Make it global that can replace the weak function */
void __sched_idle(void) __attribute__ ((noreturn));
void __sched_idle(void)
#endif
{
	unsigned int cpuid, tmp;

	cpuid = arm_get_coreid();
	trace("-> CPU%d up...\n\r", cpuid);

	init_and_install_gic(cpuid);

	plat_enable_cacheable();
	arm_write_thread_id(cpuid + MAX_THREADS);

	runningThreadsID[cpuid] = arm_read_thread_id();

	arch_timer_init();
	archtimer_setup_irq_secure(0, __timer_isr, cpuid);

	tmp = getPhysicalCount(); /*Counter up */
	while (getPhysicalCount() - tmp <= 0);

	sem_post(&ready_secondary_cpus_semaphore);
	flush_dcache_range(0x0, 0xf00000);

	dsb();
	trace("-> CPU%d running...\n\r", cpuid);

	/* Kick off the scheduler */
	setNSEL1PhysicalCompValue(getPhysicalCount() + 1);
	setNSEL1PhysicalTimerCtrl((1 << 0));

	while (1)
		wfi();
	/* if the scheduling TIMESLICE is big, we could call ipi_broadcast_self(SCHEDULER_IPI) in order to force rescheduling */
}

void sched_kill_thread(int thread_id)
{
	if (thread_id >= 0 && thread_id < MAX_THREADS)
		if (threadsPCBs[thread_id].active == TRUE) {
			threadsPCBs[thread_id].active = FALSE;

			/* This will allow for the thread to be placed in the queue by the scheduler
			   and then disposed of, in case we have threads <= CPUs */
			threadsPCBs[thread_id].handler->sleeping = TRUE;
		}
#ifdef FORCE_RESCHEDULE
	ipi_broadcast_self(SCHEDULER_IPI);
	dsb();
#endif
}

int sched_sched_stats(scheduler_stats_t * scheduler_stats)
{
	unsigned int i, j;

	if (scheduler_stats == NULL)
		return -1;

	sched_mutex_lock(&queue_mux);

	for (i = 0; i < TOTAL_CORES; i++) {	/* Threads currently running */
		scheduler_stats[i].tid = runningThreadsID[i];
		scheduler_stats[i].cpuid = i;
		scheduler_stats[i].sleeping =
		    threadsPCBs[runningThreadsID[i]].handler->sleeping;
		scheduler_stats[i].detached =
		    threadsPCBs[runningThreadsID[i]].handler->detach_state;
		scheduler_stats[i].descheduled =
		    threadsPCBs[runningThreadsID[i]].handler->
		    descheduled_semaphore.counter;
		scheduler_stats[i].start_routine =
		    threadsPCBs[runningThreadsID[i]].handler->start_routine;
	}

	j = tailPCB;
	while (j != headPCB) {
		scheduler_stats[i].tid = pendingPCB[j]->handler->ID;
		scheduler_stats[i].cpuid = -1;
        scheduler_stats[i].sleeping = pendingPCB[j]->handler->sleeping;
        scheduler_stats[i].detached = pendingPCB[j]->handler->detach_state;
        scheduler_stats[i].descheduled = pendingPCB[j]->handler->descheduled_semaphore.counter;
        scheduler_stats[i].start_routine = pendingPCB[j]->handler->start_routine;
        j = (j + 1) % (MAX_THREADS + TOTAL_CORES);
		i++;
	}

	sched_mutex_unlock(&queue_mux);

	return i;
}

void sched_kick(void)
{
	unsigned long flags = local_irq_save();
	setNSEL1PhysicalTimerCtrl(0);
	setNSEL1PhysicalTimerCtrl((1 << 0));
	setNSEL1PhysicalCompValue(getPhysicalCount() - 1);//Only raise sched isr to giveup the remainder sched time
	local_irq_restore(flags);
}

void sched_cancel(void)
{
	sched_t *handler;
	unsigned int calling_thread_ID;

	calling_thread_ID = arm_read_thread_id();
	threadsPCBs[calling_thread_ID].active = FALSE;
#ifdef FORCE_RESCHEDULE
	ipi_broadcast_self(SCHEDULER_IPI);
#endif
	sched_kick();
	while(1);
}

static sched_t cmd_threads0, cmd_threads1, cmd_threads2;
static sched_attr_t cmd_attr0, cmd_attr1, cmd_attr2;

#define _TEST_SCHED_LOOP	(0xf0000)
static void *__test_thread_a(void *d)
{
	volatile int i = 0, j = 0;
	unsigned int cpuid = arm_get_coreid();
	unsigned int cnt = 0;

	while (1) {
		i = j = 0;
		trace_without_prefix("[%d:a cnt= %d] ", cpuid, cnt++);
		for (i = 0; i < (_TEST_SCHED_LOOP); ++i) {
			*(&j) = i;
		}
	}
	return 0;
}

static void *__test_thread_b(void *d)
{
	volatile int i = 0, j = 0;
	unsigned int cpuid = arm_get_coreid();
	unsigned int cnt = 0;

	while (1) {
		i = j = 0;
		trace_without_prefix("[%d:b cnt= %d] ", cpuid, cnt++);
		for (i = 0; i < (_TEST_SCHED_LOOP * 4); ++i) {
			*(&j) = i;
		}
	}
	return 0;
}

static void *__test_thread_c(void *d)
{
	volatile int i = 0, j = 0;
	unsigned int cpuid = arm_get_coreid();
	unsigned int cnt = 0;

	while (1) {
		i = j = 0;
		trace_without_prefix("[%d:c cnt= %d] ", cpuid, cnt++);
		for (i = 0; i < (_TEST_SCHED_LOOP * 16); ++i) {
			*(&j) = i;
		}
	}
	return 0;
}

static void __test_sched(void)
{
	sched_create(&cmd_threads0, &cmd_attr0, __test_thread_a, 0);
	sched_create(&cmd_threads1, &cmd_attr1, __test_thread_b, 0);
	sched_create(&cmd_threads2, &cmd_attr2, __test_thread_c, 0);
}

void test_sched(void)
{
	__test_sched();
}

