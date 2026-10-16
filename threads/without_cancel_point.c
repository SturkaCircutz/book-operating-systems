#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *worker(void *arg) {
    long count = 0;

    /* change from deferred (default) to asynchronous */
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    while (1) {
        count++;    /* no cancellation point at all */
    }

    return NULL;
}

int main(void) {
    pthread_t tid;
    void *result;

    pthread_create(&tid, NULL, worker, NULL);
    sleep(2);

    printf("Main: cancelling the worker\n");
    pthread_cancel(tid);
    pthread_join(tid, &result);

    if (result == PTHREAD_CANCELED)
        printf("Main: worker was cancelled\n");

    return 0;
}