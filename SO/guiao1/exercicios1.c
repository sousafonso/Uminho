#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdlib.h>
#include <time.h>

int mycat(){
    char* buffer = malloc (sizeof(char)*1024);
    ssize_t readen;
    
    while ((readen = read (0, buffer, 1024)) != 0) write (1, buffer, read);
}

// Gera um ficheiro com 1MB de tamanho
int generator (char* file1, char* file2){
    int fd = open(file2, O_WRONLY | O_CREAT, 0644);
    
    for (int i = 0; i < 1024*1024; i++){        
        while (fd, "a", 1);
    }

    close(fd);

    return 0;
}

int mycp(char* file1, char* file2, int buffer_size) {
    int fd1 = open(file1, O_RDONLY);
    int fd2 = open(file2, O_WRONLY | O_CREAT, 0644);
    char* buffer = malloc(sizeof(char) * buffer_size);
    ssize_t readen;
    clock_t start_time, end_time;
    double total_time;

    start_time = clock();

    while ((readen = read(fd1, buffer, buffer_size)) != 0) {
        write(fd2, buffer, readen);
    }

    end_time = clock();
    total_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", total_time);

    close(fd1);
    close(fd2);

    return 0;
}
