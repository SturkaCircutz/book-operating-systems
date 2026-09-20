#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void handler(int sig) {
    printf("I received signal %d\n", sig);
}

int main() {
    // when this process receives sigint, run my handler function
    // this is the int set up, it can happen anywhere in the process
    
    signal(SIGINT, handler);
    // SIGNINT means interrupt, normally ctrl + c sends signint to the running process


    while (1) {
        printf("Running...\n");
        sleep(1);
    }

    return 0;
}