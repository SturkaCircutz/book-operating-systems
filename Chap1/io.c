#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    assert(fd > -1);

    int rc = write(fd, "hello world\n", 13);
    assert(rc == 13);

    close(fd);
    return 0;
}

/*
the OS is sometimes seen as a standard library

Because from the application's perspective,
the OS provides convenient functions/interfaces that hide all the low-level hardware complexity.

*/