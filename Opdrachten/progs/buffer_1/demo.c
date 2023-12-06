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
    pthread_mutex_t m;
} args;

void *producer(void *arg) // function for producer thread
{
    args a = *(args *)arg;
    int i = 0;
    do
    {
        check( pthread_mutex_lock(&a.m) );
        if (!buffer_is_full())
        {
            buffer_put(i);
        }
        check( pthread_mutex_unlock(&a.m) );
        i++;
        check_errno( msleep(1000) );
    } while(i != 10);

    return NULL;
}

void *consumer(void *arg) // function for consumer thread
{
    args a = *(args *)arg;
    int i;
    do
    {
        check( pthread_mutex_lock(&a.m) );
        while (buffer_get(&i))
        {
            check_errno( printf("%d\n", i) );
        }
        check( pthread_mutex_unlock(&a.m) );
        check_errno( msleep(500) );
    } while (i != 9);

    return NULL;
}

int main(void)
{
    args a;

    pthread_mutexattr_t ma;
    check( pthread_mutexattr_init(&ma) );
    check( pthread_mutex_init(&a.m, &ma) );

    pthread_t ptc, ptp;
    check( pthread_create(&ptc, NULL, consumer, &a) );
    check( pthread_create(&ptp, NULL, producer, &a) );

    check( pthread_join(ptc, NULL) );
    check( pthread_join(ptp, NULL) );

    check( pthread_mutex_destroy(&a.m) );
    check( pthread_mutexattr_destroy(&ma) );

    return EXIT_SUCCESS;
}
