#include "../lib/uthreads.h"
#include <stdio.h>
#include <stdlib.h>

int libuthread_init()
{
    return 0;
}

int uthread_create(void * (*start_routine)(void*), void * arg)
{
    int tid;
    return tid;
}

int uthread_yield(void)
{
    return 0;
}

int uthread_join(int tid)
{
    return 0;
}

int uthread_lock(umutex_t lock)
{
    return 0;
}

int uthread_unlock(umutex_t lock)
{
    return 0;
}
