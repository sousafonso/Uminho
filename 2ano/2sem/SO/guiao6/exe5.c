#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Programa que executa o comando "ls /etc" e conta o número de linhas.
 * O programa executa o comando "ls" num processo filho e o comando "wc -l" num segundo processo filho.
 * O primeiro processo filho escreve a saída no pipe e o segundo processo filho lê do pipe.
 * 
 * O programa é similar ao comando "ls /etc | wc -l" do Unix.
 
*/
int main() {
    int pipefd[2];
    pid_t pid = fork();

    if (pid == -1) {
        perror("Falha ao criar processo filho");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(pipefd[0]);

        dup2(pipefd[1], STDOUT_FILENO);

        close(pipefd[1]);

        execlp("ls", "ls", "/etc", NULL);

        _exit(EXIT_FAILURE);
    }

    close(pipefd[1]);

    pid = fork();

    if (pid == -1) {
        perror("Falha ao criar processo filho");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(pipefd[1]);

        dup2(pipefd[0], STDIN_FILENO);

        close(pipefd[0]);

        execlp("wc", "wc", "-l", NULL);

        _exit(EXIT_FAILURE);
    }

    close(pipefd[0]);

    wait(NULL);

    return 0;
}