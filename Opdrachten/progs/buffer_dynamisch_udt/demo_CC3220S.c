#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <ti/sysbios/BIOS.h>
#include "ti_drivers_config.h"

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

void *main_thread(void *arg)
{
    pthread_mutex_t m1, m2;

    pthread_mutexattr_t ma;
    check( pthread_mutexattr_init(&ma) );
    check( pthread_mutex_init(&m1, &ma) );
    check( pthread_mutex_init(&m2, &ma) );

    args a1;
    a1.b = new_buffer();
    if (a1.b == NULL)
        exit(EXIT_FAILURE);
    a1.m = &m1;

    args a2;
    a2.b = new_buffer();
    if (a2.b == NULL)
        exit(EXIT_FAILURE);
    a2.m = &m2;

    args2 a;
    a.b1 = a1.b;
    a.b2 = a2.b;
    a.m1 = a1.m;
    a.m2 = a2.m;

    pthread_attr_t attrs;
    check( pthread_attr_init(&attrs) );
    check( pthread_attr_setstacksize(&attrs, 2048) );

    pthread_t ptd, ptp, ptc;
    check( pthread_create(&ptp, &attrs, producer, &a1) );
    check( pthread_create(&ptd, &attrs, doubler, &a) );
    check( pthread_create(&ptc, &attrs, consumer, &a2) );

    check( pthread_join(ptp, NULL) );
    check( pthread_join(ptd, NULL) );
    check( pthread_join(ptc, NULL) );

    check( pthread_mutex_destroy(&m1) );
    check( pthread_mutex_destroy(&m2) );
    check( pthread_mutexattr_destroy(&ma) );

    delete_buffer(&a1.b);
    delete_buffer(&a2.b);

    return NULL;
}

int main(void)
{
    Board_init();

    pthread_attr_t pta;
    check( pthread_attr_init(&pta) );
    check( pthread_attr_setdetachstate(&pta, PTHREAD_CREATE_DETACHED) );
    check( pthread_attr_setstacksize(&pta, 2048) );

    struct sched_param sp;
    check( pthread_attr_getschedparam(&pta, &sp) );
    // The main thread must have the highest priority because this thread will start
    // the other threads and we want to study the interaction between those other threads
    sp.sched_priority = 15;
    check( pthread_attr_setschedparam(&pta, &sp) );

    pthread_t pt;
    check( pthread_create(&pt, &pta, main_thread, NULL) );

    printf("\n");
    BIOS_start();

    check( pthread_attr_destroy(&pta) );

    return EXIT_SUCCESS;
}
