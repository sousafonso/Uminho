#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

#define MAX_LINE_SIZE 1024

int main (int argc, char *argv[]){
    int fd;
    char buf[MAX_LINE_SIZE];
    ssize_t n; // bytes readed

    if ((fd = open("myfifo", O_RDONLY)) < 0){
        perror("open");
        return 1;
    }

    printf ("Reading from FIFO...\n");

    while ((n = read(fd, &buf, MAX_LINE_SIZE)) > 0){
        if (write(1, &buf, n) != n){
            perror("write");
            return 1;
        }
    }

    close(fd);
    //unlink("myfifo");
    return 0;
}