#include <stdio.h>

int main(){
    int *p = NULL;
    printf("Before error\n");

    *p = 10;
    printf("After error\n");
}

/*

*p = 10
is invalid memory access
cpu detects exveption and kernel generates SIGSEGV
signal delivered
default disposition, (terminate + core dump) is a default disposition




*/