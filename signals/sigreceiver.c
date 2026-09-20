#include <stdio.h>
#include <signal.h>


void handler(int sig, siginfo_t *info, void * context){
    printf("Signal received : %d \n", sig);
    printf("Data received : %d \n", info->si_value.sival_int);
}

int main(){
    struct sigaction sa = {0};
    sa.sa_sigaction  = handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);

    printf("Waiting ... \n");
    pause();
    return 0;
}