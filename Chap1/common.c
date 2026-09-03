#include <sys/time.h>
#include "common.h"
#include <stddef.h>

void Spin(int seconds)
{
    struct timeval start, now;  // when spin begin, current time while we are spinning

    gettimeofday(&start, NULL);  // get current time and put it inside start

    while (1)
    {
        gettimeofday(&now, NULL);  // get current time

        double elapsed =
            (now.tv_sec - start.tv_sec) +
            (now.tv_usec - start.tv_usec) / 1000000.0;  // time elapsed

        if (elapsed >= seconds)
            break;
    }
}