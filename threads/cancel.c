
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *worker(void *arg) {
    int i = 0;

    while (1) {
        printf("Worker: working... %d\n", ++i);
        sleep(1); // cancel point

        // cancel point Check whether cancellation was requested
        pthread_testcancel();
    }

    return NULL;
}

int main(void) {
    pthread_t tid;

    pthread_create(&tid, NULL, worker, NULL);

    sleep(3);

    printf("Main: cancelling the worker!\n");
    pthread_cancel(tid);

    void *result;
    pthread_join(tid, &result);

    if (result == PTHREAD_CANCELED) {
        printf("Main: worker was cancelled.\n");
    }

    return 0;
}
