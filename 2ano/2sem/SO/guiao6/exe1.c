#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd_in = open ("/etc/passwd", O_RDONLY);
    int fd_out = open ("saida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int fd_err = open ("erros.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    dup2(fd_in, 0);
    dup2(fd_out, 1);
    dup2(fd_err, 2);

    close (fd_in);
    close (fd_out);
    close (fd_err); 
    
    ssize_t bytes_read = 0;

    char buffer[4096];

    while ((bytes_read = read(0, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytes_read);
        write(2, buffer, bytes_read);
    }

    dup2(fd_in, 0);
    dup2(fd_out, 1);
    dup2(fd_err, 2);

    close (fd_in);
    close (fd_out);
    close (fd_err); 

    write(1, "terminei\n", 9);

    return 0;
}