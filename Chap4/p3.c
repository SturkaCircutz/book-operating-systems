#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char * argv[])
{
    printf("hello world, this is (pid : %d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "this is not allowed for the fork\n");
        exit(1);
    }
    else if (rc == 0){
        printf("hello, im child at pid : %d\n", (int)getpid());
        char * minpro[3];
        minpro[0] = strdup("wc");   // strdup makes u can modify the wc later
        minpro[1] = strdup("p3.c");
        minpro[2] = NULL;
        execvp(minpro[0], minpro);
        printf("this shouldn't print out\n");
    }
    else {
        int wc = wait(NULL);
        printf("this is parent at pid : %d, (wc : %d)\n", (int)getpid(), wc);
    }
    return 0;
}