#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#include "buffer.h"

void check_errno(int error)
{
    if (error < 0)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
}

void check(int error)
{
    if (error != 0)
    {
        printf("Error: %s\n", strerror(error));
        exit(EXIT_FAILURE);
    }
}

int msleep(long msec) // millisecond sleep
{
    struct timespec ts;
    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;
    return nanosleep(&ts, NULL);
}

typedef struct {
    buffer b;
    pthread_mutex_t *m;
} args;

typedef struct {
    buffer b1, b2;
    pthread_mutex_t *m1, *m2;
} args2;

void *producer(void *arg) // function for producer thread
{
    args a = *(args *)arg;
    int i = 0;
    do
    {
        check( pthread_mutex_lock(a.m) );
        if (!buffer_is_full(a.b))
        {
            buffer_put(a.b, i);
        }
        check( pthread_mutex_unlock(a.m) );
        i++;
        check_errno( msleep(200) );
    } while(i != 10);

    return NULL;
}

void *consumer(void *arg) // function for consumer thread
{
    args a = *(args *)arg;
    int i;
    do
    {
        check( pthread_mutex_lock(a.m) );
        while (buffer_get(a.b, &i))
        {
            check_errno( printf("%d\n", i) );
        }
        check( pthread_mutex_unlock(a.m) );
        check_errno( msleep(600) );
    } while (i != 9);

    return NULL;
}

void *doubler(void *arg2)
{
    args2 a = *(args2 *)arg2;
    int i;
    do
    {
        check( pthread_mutex_lock(a.m1) );
        while (buffer_get(a.b1, &i))
        {
            check( pthread_mutex_lock(a.m2) );
            buffer_put(a.b2, i);
            buffer_put(a.b2, i);
            check( pthread_mutex_unlock(a.m2) );
        }
        check( pthread_mutex_unlock(a.m1) );
        check_errno( msleep(400) );
    } while (i != 9);

    return NULL;
}

int main(void)
{
    pthread_mutex_t m1, m2;

    pthread_mutexattr_t ma;
    check( pthread_mutexattr_init(&ma) );
    check( pthread_mutex_init(&m1, &ma) );
    check( pthread_mutex_init(&m2, &ma) );

    args a1;
    a1.b = new_buffer();
    if (a1.b == NULL) 
        return EXIT_FAILURE;
    a1.m = &m1;

    args a2;
    a2.b = new_buffer();
    if (a2.b == NULL) 
        return EXIT_FAILURE;
    a2.m = &m2;

    args2 a;
    a.b1 = a1.b;
    a.b2 = a2.b;
    a.m1 = a1.m;
    a.m2 = a2.m;

    pthread_t ptd, ptp, ptc;
    check( pthread_create(&ptp, NULL, producer, &a1) );
    check( pthread_create(&ptd, NULL, doubler, &a) );
    check( pthread_create(&ptc, NULL, consumer, &a2) );

    check( pthread_join(ptp, NULL) );
    check( pthread_join(ptd, NULL) );
    check( pthread_join(ptc, NULL) );

    check( pthread_mutex_destroy(&m1) );
    check( pthread_mutex_destroy(&m2) );
    check( pthread_mutexattr_destroy(&ma) );

    delete_buffer(a1.b);
    delete_buffer(a2.b);
    
    return EXIT_SUCCESS;
}
