/* 
 * File:   uthreads.h
 * Author: jonas
 *
 * Created on April 13, 2013, 7:59 PM
 */

#ifndef UTHREADS_H
#define	UTHREADS_H

#define MAXTHREADS 128

typedef enum
{
    false = 0, true = !(false)
} boolean;

typedef enum
{
    running, able, blocked
} currentstate;

typedef struct
{
    
} ucontext;

typedef struct
{
    int* waitingListPointer;
    boolean isFree;
} umutex_t;

typedef struct
{
    int tid;
    currentstate state;
    ucontext context;
} uthread_t;

int libuthread_init();
int uthread_create(void * (*start_routine)(void*), void * arg);
int uthread_yield(void);
int uthread_join(int tid);
int uthread_lock(umutex_t lock);
int uthread_unlock(umutex_t lock);

#endif	/* UTHREADS_H */

