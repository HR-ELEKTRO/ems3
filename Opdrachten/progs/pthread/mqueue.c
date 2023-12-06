#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>

void check_errno(int error)
{
    if (error < 0)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
}

void check(int error) {
    if (error != 0)
    {
        printf("Error: %s\n", strerror(error));
        while (1);
    }
}

void *producer(void *p)
{
    mqd_t mq = *(mqd_t *)p;
    for (int i = 0; i < 10; i++)
    {
        check_errno( mq_send(mq, (char *)&i, sizeof(i), 0) );
    }
    return NULL;
}

void *consumer(void *p)
{
    mqd_t mq = *(mqd_t *)p;
    for (int i = 0; i < 10; i++)
    {
        int msg;
        check_errno( mq_receive(mq, (char *)&msg, sizeof(msg), NULL) );
        printf("%d\n", msg);
    }
    return NULL;
}

int main(void) {
    mqd_t mqdes;
    struct mq_attr mqAttrs;
    mqAttrs.mq_maxmsg = 3;
    mqAttrs.mq_msgsize = sizeof(int);
    mqAttrs.mq_flags = 0;
    check_errno((int)( mqdes = mq_open("ints", O_RDWR | O_CREAT, 0666, &mqAttrs) ));

    pthread_t tp, tc;
    check (pthread_create(&tp, NULL, &producer, &mqdes) );
    check (pthread_create(&tc, NULL, &consumer, &mqdes) );

    check( pthread_join(tp, NULL) );
    check( pthread_join(tc, NULL) );

    check_errno( mq_close(mqdes) );
    check_errno( mq_unlink("ints") );

    return EXIT_SUCCESS;
}
