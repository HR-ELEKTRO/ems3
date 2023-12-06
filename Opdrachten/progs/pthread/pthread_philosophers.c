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
    int id;
    pthread_mutex_t forks[5];
} par_t;

void *philosopher(void *par)
{
    par_t p = *(par_t *)par;
    while (1)
    {
        check_errno( printf("philosopher %d is sleeping\n", p.id) );
        check_errno( msleep(200) );
        check( pthread_mutex_lock(&p.forks[p.id]) );
        check( pthread_mutex_lock(&p.forks[(p.id + 1) % 5]) );
        check_errno( printf("philosopher %d is eating\n", p.id) );
        check( pthread_mutex_unlock(&p.forks[p.id]) );
        check( pthread_mutex_unlock(&p.forks[(p.id + 1) % 5]) );
    }
    return NULL;
}

int main(void)
{
    pthread_mutex_t forks[5];
    par_t p[5];
    
    pthread_mutexattr_t ma;
    check( pthread_mutexattr_init(&ma) );
    for (int i = 0; i < 5; i++)
    {
        check( pthread_mutex_init(&forks[i], &ma) );
    }
    
    // share all forks
    for (int i = 0; i < 5; i++)
    {
        for (int f = 0; f < 5; f++)
        {
            p[i].forks[f] = forks[f];
        }
    }

    pthread_t t[5];
    for (int i = 0; i < 5; i++)
    {
        p[i].id = i;
        check( pthread_create(&t[i], NULL, &philosopher, &p[i]) );
    }

    for (int i = 0; i < 5; i++)
    {
        check( pthread_join(t[i], NULL) );
    }

    for (int i = 0; i < 5; i++)
    {
        check( pthread_mutex_destroy(&forks[i]) );
    }
    check( pthread_mutexattr_destroy(&ma) );

    return EXIT_SUCCESS;
}
