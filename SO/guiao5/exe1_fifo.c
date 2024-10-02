#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define FIFO_NAME "myfifo"

int main (int argc, char *argv[]){
    int fd;
    char buf[PIPE_BUF];
    int n;

    if (mkfifo(FIFO_NAME, 0666) < 0){
        perror("mkfifo");
        return 1;
    }

    if ((fd = open(FIFO_NAME, O_WRONLY)) < 0){
        perror("open");
        return 1;
    }

    while ((n = read(0, buf, PIPE_BUF)) > 0){
        if (write(fd, buf, n) != n){
            perror("write");
            return 1;
        }
    }

    close(fd);
    return 0;
}