#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256

/**
 * Programa que lê linhas de texto do standard input e conta o número de linhas, palavras e caracteres.
 * O programa executa o comando wc para realizar a contagem.
 * 
 * O programa cria um pipe anônimo e executa o comando wc num processo filho.
 * O processo pai lê linhas de texto do standard input e escreve no pipe.
 * O processo filho lê do pipe e executa o comando wc.
 * 
 * O programa é similar ao comando "wc" do Unix.
*/
int main(int argc, char** argv[]) {
    int pipefd[2];
    int pipe = pipefd[2];

    pid_t pid = fork();

    if (pid == -1) {
        perror("Falha ao criar processo filho");
        exit(EXIT_FAILURE);
    }

    if (pid == 0){
        close(pipefd[1]);

        dup2(pipefd[0], STDIN_FILENO);

        close(pipefd[0]);

        execlp("wc", "wc", NULL);

        _exit(EXIT_FAILURE);
    }

    close(pipefd[0]);

    char buffer[BUFFER_SIZE];

    ssize_t bytes_read = 0;

    while ((bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
        write(pipefd[1], buffer, bytes_read);
    }

    close(pipefd[1]);
    wait(NULL);

    return 0;
}