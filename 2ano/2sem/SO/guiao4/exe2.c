#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    int fd[2], status;
    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) { // Processo Filho : prdutor
        close(fd[0]); 

        for (int i = 0; i < 10000; i++) {
            write(fd[1], &i, sizeof(int)); 
            printf ("Filho escreveu o valor %d\n", i);
        }

        close(fd[1]); 
        _exit(0);
    } else { // Processo pai : consumidor
        close(fd[1]); 

        int received_data;

        sleep(2);
        // for (int i = 0; i < 10000; i++) {
        //     read(fd[0], &received_data, sizeof(received_data));
        //     printf("Received data: %d\n", received_data);
        // }

        while (read(fd[0], &received_data, sizeof(received_data)) > 0) {
            printf("Received data: %d\n", received_data);
        }

        close(fd[0]);

        pid_t terminated_pid = wait(&status);
        printf ("Pai: O filho %d terminou com código de saída %d\n", terminated_pid, WEXITSTATUS(status));
        WEXITSTATUS(status);
    }

    return 0;
}
