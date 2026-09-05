#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include <pthread.h>

volatile int counter = 0;
int loops;

void *worker(void * arg){
    int i ;
    for (i = 0 ; i < loops; i++){
        counter ++;
    }
    return NULL;

}

int main(int argc, char * argv[]){
    if(argc != 2){
        fprintf(stderr, "usage: threads <value> \n");
        exit(1);
    }
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("initial value : %d\n", counter);

    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("final value : %d\n", counter);
    return 0;

}

/*
prompt> ./thread 100000
Initial value : 0
Final value : 143012 // huh??
prompt> ./thread 100000
Initial value : 0
Final value : 137298 // what the??


counter = 5
T1: "I'll read it" → 5
T2: "I'll read it too" → 5
T1: "5 + 1 = 6"
T2: "5 + 1 = 6"
T1: writes 6
T2: writes 6
data race
*/