#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define SIZE 8

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

char buffer[SIZE]; // buffer which can store SIZE elements of type char
int indexGet = 0; // index where the next element will be read
int indexPut = 0; // index where the next element will be written
sem_t semMutualExclusive; // binary semaphore: used for mutual exclusive use of the buffer
sem_t semEmpty; // counting semaphore: counts the number of empty places
sem_t semFilled; // counting semaphore: count the number of filled places
sem_t semPrintf; // binary semaphore: used for mutual exclusive use of printf

void put(char c)
{
    check_errno( sem_wait(&semEmpty) ); // lower the number of empty places, WAIT if there are no free places left!
    check_errno( sem_wait(&semMutualExclusive) ); // enter critical region
    buffer[indexPut] = c;
    indexPut++;
    if (indexPut == SIZE)
    {
        indexPut = 0;
    }
    check_errno( sem_post(&semMutualExclusive) ); // leave critical region
    check_errno( sem_post(&semFilled) ); // increase the number of filled places
}

char get(void)
{
    check_errno( sem_wait(&semFilled) ); // lower the number of filled places, WAIT if there are no filled places left!
    check_errno( sem_wait(&semMutualExclusive) ); // enter critical region
    char c = buffer[indexGet];
    indexGet++;
    if (indexGet == SIZE)
    {
        indexGet = 0;
    }
    check_errno( sem_post(&semMutualExclusive) ); // leave critical region
    check_errno( sem_post(&semEmpty) ); // increase the number of empty places
    return c;
}

void *producer(void *arg) // function for producer thread
{
    char c = *(char *)arg;
    check_errno( sem_wait(&semPrintf) );
    check_errno( printf("Thread: producer with argument %c starts\n", c) );
    check_errno( sem_post(&semPrintf) );
    for (int i = 0; i < 100; ++i)
    {
        put(c);
    }
    check_errno( sem_wait(&semPrintf) );
    check_errno( printf("Thread: producer with argument %c stops\n", c) );
    check_errno( sem_post(&semPrintf) );
    return NULL;
}

void *consumer(void *arg) // function for consumer thread
{
    (void) arg;
    check_errno( sem_wait(&semPrintf) );
    check_errno( printf("Thread: consumer starts\n") );
    check_errno( sem_post(&semPrintf) );
    for (int i = 0; i < 200; ++i)
    {
        char c = get();
        check_errno( sem_wait(&semPrintf) );
        check_errno( printf("%c", c) );
        check_errno( sem_post(&semPrintf) );
    }
    check_errno( sem_wait(&semPrintf) );
    check_errno( printf("Thread: consumer stops\n") );
    check_errno( sem_post(&semPrintf) );
    return NULL;
}

int read_prio(char *process_name)
{
    int prio;
    do
    {
        check_errno( printf("Enter priority for process %s [1..15]: ", process_name) );
    }
    while (scanf("%d", &prio) != 1 || prio < 1 || prio > 15);
    return prio;
}

int main(void)
{
    int prioc = read_prio("Consumer");
    int priop1 = read_prio("Frikandel Producer");
    int priop2 = read_prio("Kroket Producer");

    check_errno( printf("Output for Consumer priority = %d ", prioc) );
    check_errno( printf("frikandel Producer priority = %d ", priop1) );
    check_errno( printf("Kroket Producer priority = %d\n", priop2) );

    check_errno( sem_init(&semMutualExclusive, 0, 1) ); // allow one thread exclusively in critical section
    check_errno( sem_init(&semEmpty, 0, SIZE) ); // there are SIZE empty places
    check_errno( sem_init(&semFilled, 0, 0) ); // there are 0 filled places
    check_errno( sem_init(&semPrintf, 0, 1) ); // allow one thread exclusively to use printf

    pthread_attr_t ptac, ptap1, ptap2;
    check( pthread_attr_init(&ptac) );
    check( pthread_attr_init(&ptap1) );
    check( pthread_attr_init(&ptap2) );

    struct sched_param spc, spp1, spp2;
    check( pthread_attr_getschedparam(&ptac, &spc) );
    check( pthread_attr_getschedparam(&ptap1, &spp1) );
    check( pthread_attr_getschedparam(&ptap2, &spp2) );

    spc.sched_priority = prioc;
    spp1.sched_priority = priop1;
    spp2.sched_priority = priop2;

    check( pthread_attr_setschedparam(&ptac, &spc) );
    check( pthread_attr_setschedparam(&ptap1, &spp1) );
    check( pthread_attr_setschedparam(&ptap2, &spp2) );

    pthread_t ptc, ptp1, ptp2;
    char frikandel = 'F', kroket = 'K';
    check( pthread_create(&ptc, &ptac, consumer, NULL) );
    check( pthread_create(&ptp1, &ptap1, producer, &frikandel) );
    check( pthread_create(&ptp2, &ptap2, producer, &kroket) );

    check( pthread_join(ptc, NULL) );
    check( pthread_join(ptp1, NULL) );
    check( pthread_join(ptp2, NULL) );

    check_errno( sem_destroy(&semPrintf) );
    check_errno( sem_destroy(&semMutualExclusive) );
    check_errno( sem_destroy(&semEmpty) );
    check_errno( sem_destroy(&semFilled) );

    check( pthread_attr_destroy(&ptac) );
    check( pthread_attr_destroy(&ptap1) );
    check( pthread_attr_destroy(&ptap2) );

    return EXIT_SUCCESS;
}
