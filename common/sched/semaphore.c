#include <arm_acle.h>

#include "semaphore.h"
#include "config.h"
#include "spinlock.h"

int sem_init(sem_t * sem, unsigned int value)
{
	if (sem == NULL)
		return EINVAL;

	sem->initialized = TRUE;
	sem->counter = value;
	sem->sem_lock.lock = 0;

	return EOK;
}

int sem_destroy(sem_t * sem)
{
	if (sem == NULL)
		return EINVAL;

	if (sem->counter < 0)
		return EBUSY;

	sem->counter = 0;
	sem->initialized = FALSE;
	sem->sem_lock.lock = 0;

	return EOK;
}

static void sem_wait_s(sem_t * sem, volatile signed int *counter)
{
	spin_lock(&(sem->sem_lock));
	(*counter)--;
	spin_unlock(&(sem->sem_lock));

	while (*counter < 0)
		__asm("wfe\n");
}

static void sem_post_s(sem_t * sem, volatile signed int *counter)
{
	spin_lock(&(sem->sem_lock));
	(*counter)++;
	spin_unlock(&(sem->sem_lock));
	__asm("sev\n");
}

int sem_wait(sem_t * sem)
{
	if ((sem == NULL) || (sem->initialized == FALSE))
		return EINVAL;

	sem_wait_s(sem, &sem->counter);
	dsb();

	return EOK;
}

int sem_post(sem_t * sem)
{
	if ((sem == NULL) || (sem->initialized == FALSE))
		return EINVAL;
	dsb();

	sem_post_s(sem, &sem->counter);
	return EOK;
}

int sem_getvalue(sem_t * sem, WORD32 * sval)
{
	if ((sem == NULL) || (sem->initialized == FALSE) || (sval == NULL))
		return EINVAL;

	*sval = sem->counter;

	return EOK;
}
