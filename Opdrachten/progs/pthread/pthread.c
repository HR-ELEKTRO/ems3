#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

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

void *print1(void *par)
{
    (void) par;
    for (int i = 0; i < 10; i++)
    {
        check_errno( msleep(250) );
        check_errno( printf("print1\n") );
    }
    return NULL;
}

void *print2(void *par)
{
    (void) par;
    for (int i = 0; i < 10; i++)
    {
        check_errno( msleep(500) );
        check_errno( printf("print2\n") );
    }
    return NULL;
}

int main(void) 
{
    pthread_t t1, t2;
    check( pthread_create(&t1, NULL, &print1, NULL) );
    check( pthread_create(&t2, NULL, &print2, NULL) );

    check( pthread_join(t1, NULL) );
    check( pthread_join(t2, NULL) );

    return EXIT_SUCCESS;
}
