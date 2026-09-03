#!/bin/bash


# ./cpu A &
# ./cpu B &
# ./cpu C &
# ./cpu D &
gcc -Wall -Wextra -ggdb -o mem common.c mem.c
./mem & ./mem
#[1] 7353 [2] 7354 [3] 7355 [4] 7356

# close the processes by killall cpu
#check them by ps aux | grep "./cpu"