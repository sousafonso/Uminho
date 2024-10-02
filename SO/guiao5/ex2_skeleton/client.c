#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "defs.h"
#include "vector.h"
#include <string.h>

#define SERVER_PIPE "server_pipe"
#define CLIENT_PIPE "client_pipe_%d"
#define MAX_BUFFER_SIZE 1024

int main (int argc, char * argv[]){
    if (argc < 2) {
        printf("Missing argument.\n");
        _exit(1);
    }

    Msg m;
    m.needle = atoi(argv[1]);
    m.pid = getpid();
    m.occurrences = 0;

    char fifoclient[MAX_BUFFER_SIZE];
    sprintf(fifoclient, CLIENT "%d", m.pid);

    if(mkfifo(fifoclient, 0666) == -1){
        perror("mkfifo");
        exit(2);
    }

    int fds = open(SERVER, O_WRONLY);

    if(fds == -1){
        perror("open");
        exit(3);
    }

    write(fds, &m, sizeof(Msg));

    close(fds);

    int fdc = open(fifoclient, O_RDONLY);
    if(fdc == -1){
        perror("open");
        exit(4);
    }

    if(read(fdc, &m, sizeof(Msg)) > 0){
        printf("Número de ocorrências: %d\n", m.occurrences);
    }

    close(fdc);

    unlink(fifoclient);

    return 0;
}

/**
 * O cliente recebe um argumento que é o número a procurar no vetor.
 * O cliente cria um named pipe com o seu pid porque o servidor precisa de saber o nome do named pipe do cliente para lhe enviar a resposta.
 * O cliente envia uma mensagem ao servidor com o número a procurar e o seu pid.
 * O cliente abre o named pipe do servidor para escrita e escreve a mensagem.
 * O cliente abre o named pipe do servidor para leitura e lê a resposta.
 * O cliente imprime o número de ocorrências.
 * O cliente remove o named pipe.
 * O cliente termina.
*/
