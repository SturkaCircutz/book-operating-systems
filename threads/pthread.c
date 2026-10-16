#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *athread (void *arg){
    int i;
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self(); // obtain the handle of the calling thread
    printf("Process ID: %d, thread ID: %u, arg: %s\n",
    (unsigned int) pid, (unsigned int) tid, (char *) arg);
    return;
}

int main(int arg, char * argv[]) {
    int i, rval;
    pthread_t tid;
    for (i = 1; i < arg; ++i){
        rval = pthread_create(&tid, NULL, athread, (void *) argv[i]);
        if (rval) perror("thread creation failed!");
    }
    pthread_exit(0);  // the main thread gets clean up
}