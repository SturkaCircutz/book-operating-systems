#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig){
    printf("I got signal %d\n", sig);
}

int main(){
    signal(SIGUSR1, handler);
    printf("My pid is %d\n", getpid());
    while (1)
    {
        sleep(1);
    }

    return 0;
    
}

/*
run this program
in another terminal use kill SIGUSR1 and the pid number
kill command ask the kernel to send the signal





*/