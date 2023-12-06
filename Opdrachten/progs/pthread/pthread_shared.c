#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>

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

int aantal = 0;

void *teller(void *par)
{
    (void) par;
    for (int i = 0; i < 1000000; i++)
    {
        aantal++;
    }
    return NULL;
}

int main(void)
{
    pthread_t t1, t2, t3;
    check( pthread_create(&t1, NULL, &teller, NULL) );
    check( pthread_create(&t2, NULL, &teller, NULL) );
    check( pthread_create(&t3, NULL, &teller, NULL) );

    check( pthread_join(t1, NULL) );
    check( pthread_join(t2, NULL) );
    check( pthread_join(t3, NULL) );

    check_errno( printf("aantal = %d\n", aantal) );
    
    return EXIT_SUCCESS;
}
