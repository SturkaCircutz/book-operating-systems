#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <linux/stat.h>
#include <sys/stat.h>
int main(int argc, char * argv[])
{
    int rc = fork();
    if (rc  < 0){
        fprintf(stderr, "this is an error on the fork\n");
        exit(1);
    }
    if (rc == 0){
        printf("this is child (pid : %d)\n", (int)getpid());
        char * minarg[3];
        close(STDOUT_FILENO);
        open("./p4.ouput", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        minarg[0] = strdup("wc");
        minarg[1] = strdup("p4.c");
        minarg[2] = NULL;
        execvp(minarg[0], minarg);
    }
    else{
        int wc = wait(NULL);
        printf("this is parent (pid : %d) of (rc : %d) (wc : %d)\n", (int)getpid(), rc, wc);
    }
    return 0;
}