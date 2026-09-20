#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig){
    printf("time is up \n");
}

int main(){
    signal(SIGALRM, handler);
    
    printf("You have 3 seconds...\n");

    alarm(3);

    while (1) {
        printf("Waiting...\n");
        sleep(1);
    }

    return 0;
}