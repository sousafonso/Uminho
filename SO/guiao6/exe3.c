#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main (){
    int fd_in = open("input.txt", O_RDONLY);
    int fd_out = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    dup2(fd_in, STDIN_FILENO);
    dup2(fd_out, STDOUT_FILENO);

    close(fd_in);
    close(fd_out);

    execlp("wc", "wc", NULL);
}