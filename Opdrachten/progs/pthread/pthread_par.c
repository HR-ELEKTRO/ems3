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

typedef struct
{
    char *msg;
    long ms;
} par_t;

void *print(void *par)
{
    par_t p = *(par_t *)par;
    for (int i = 0; i < 10; i++)
    {
        check_errno( msleep(p.ms) );
        check_errno( printf(p.msg) );
    }
    return NULL;
}

int main(void)
{
    pthread_t t1, t2;
    par_t p1 = {"print1\n", 250};
    par_t p2 = {"print2\n", 500};
    check( pthread_create(&t1, NULL, &print, &p1) );
    check( pthread_create(&t2, NULL, &print, &p2) );

    check( pthread_join(t1, NULL) );
    check( pthread_join(t2, NULL) );

    return EXIT_SUCCESS;
}
