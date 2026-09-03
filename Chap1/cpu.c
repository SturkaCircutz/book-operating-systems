// print hello every 1 second
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "common.h"

int main(int argc, char * argv[])
{
/*
ex: ./cpu hello
argc = 2
argv[0] = "./cpu"
argv[1] = "hello"
if u dont give hello, the program exits
*/
    if (argc != 2)
    {
        fprintf(stderr, "usage: cpu");
        exit(1);
    }
    char *str = argv[1]; // str points to string you give

    while(1)
    {
        Spin(1); // keep cpu for around 10 second, then stop spinning
        printf("%s\n", str); // print the string
        //repeat
    }

}