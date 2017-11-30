#ifndef __SCHED_CONFIG_H__
#define __SCHED_CONFIG_H__

#define EOK       0		/* No error */
#define EINVAL    1		/* Invalid argument */
#define EBUSY     2		/* Busy (example: mutex already locked) */
#define EUNINIT   3		/* Not initialised */
#define EERROR    4		/* Generic error */
#define ESRCH     5		/* Cannot find specified parameter */
#define ENORES    6		/* Not enought resources */
#define EFAULT    7		/* Invalid pointer */
#define EAGAIN    8		/* Try again. */

#define LOCKED  1
#define FREE    0

#ifndef TOTAL_CORES
#define TOTAL_CORES 1 /* Pls make sure this numer are equal to the real booted core number */
#endif

#define SCHEDULER_IPI 0
#define MAX_THREADS 32
#define THREAD_STACK_SIZE 0x2000
#define TIMESLICE (1000*500)

/*internal api */
int arm_read_thread_id(void);
void arm_write_thread_id(long);
/*end of internal api*/

#endif
