#include <stdio.h>
#include <unistd.h>
#include <signal.h>
/*
union sigval{
    int sival_int;
    void *sival_ptr;
}

*/
int main(){
    union sigval value;

    value.sival_int = 42;

    sigqueue(getpid(), SIGUSR1, value);
    return 0;
}