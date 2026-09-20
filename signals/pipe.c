#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void handler(){
    printf("it sends the signal of SIGPIPE");
}
int main(){
    int fd[2];
    signal(SIGPIPE, handler);
    pipe(fd);

    close(fd[0]);
    write(fd[1], "hello", 5);
    printf("DONE");
    return 0;
}