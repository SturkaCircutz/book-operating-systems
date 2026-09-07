#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
    printf("hello world (pid : %d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rc == 0){
        printf("hello, i am child (pid: %d)\n", (int) getpid());
    }
    else {
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc : %d) (pid : %d)\n", rc, wc, (int) getpid());
    }
    return 0;
}

/*
rc       = 29384   → PID of the child, returned by fork()
wc       = 29384   → PID of the child, returned by wait()
getpid() = 29383   → PID of the parent itself

*/