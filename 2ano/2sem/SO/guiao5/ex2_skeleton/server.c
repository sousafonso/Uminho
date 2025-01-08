#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "defs.h"
#include "vector.h"
#include <string.h>

//FIFO criado pelo servidor
//Cliente pode receber um sigpipe (concorrência!)

#define PIPE_NAME "server_pipe"
#define CLIENT_PIPE "client_pipe_%d"
#define MAX_BUFFER_SIZE 1024

int main (int argc, char * argv[]){

    init_vector();
    print_vector();

    int fds_read, fds_write;

    if (fds_read = mkfifo(PIPE_NAME, 0666) == -1){
        perror("mkfifo");
        exit(1);
    }

    if (fds_read = open(PIPE_NAME, O_RDONLY) == -1){
        perror("open");
        exit(2);
    }

    if (fds_write = open(PIPE_NAME, O_WRONLY) == -1){
        perror("open");
        exit(3);
    }

    Msg m;

    while(1){
        if(read(fds_read, &m, sizeof(Msg)) > 0){
            m.occurrences = count_needle(m.needle);
            int fdc;
            char fifoclient[MAX_BUFFER_SIZE];
            sprintf(fifoclient, CLIENT_PIPE, m.pid);
            if(fdc = open(fifoclient, O_WRONLY) == -1){
                perror("open");
                exit(4);
            }
            write(fdc, &m, sizeof(Msg));
            close(fdc);
        }
    }
}

/**
 * int server_fd, dummy_fd, client_fd;
    char client_pipe_name[MAX_BUFFER_SIZE];
    char read_buffer[MAX_BUFFER_SIZE];
    int numbers[10]; // Vetor de exemplo
    int num, i, occurrences;

	init_vector();
	print_vector();

	unlink(PIPE_NAME); // Remove o pipe se já existir
    if (mkfifo(PIPE_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }

    // Abrir o named pipe para leitura e escrita (para evitar o bloqueio)
    server_fd = open(PIPE_NAME, O_RDONLY | O_NONBLOCK);
    dummy_fd = open(PIPE_NAME, O_WRONLY);
    
    if (server_fd == -1 || dummy_fd == -1) {
        perror("open");
        exit(2);
    }

    printf("Servidor iniciado. Aguardando por clientes...\n");

    while (1) {
        // Ler o número a procurar enviado pelo cliente
        if (read(server_fd, read_buffer, MAX_BUFFER_SIZE) > 0) {
            sscanf(read_buffer, "%d %s", &num, client_pipe_name);
            occurrences = 0;
            
            // Procurar o número no vetor
            for (i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
                if (numbers[i] == num) {
                    occurrences++;
                }
            }

            // Abrir o pipe do cliente para enviar a resposta
            client_fd = open(client_pipe_name, O_WRONLY);
            if (client_fd != -1) {
                sprintf(read_buffer, "%d", occurrences);
                write(client_fd, read_buffer, strlen(read_buffer) + 1);
                close(client_fd);
            }
        }
        sleep(1); // Para evitar uso excessivo da CPU
    }

    close(server_fd);
    close(dummy_fd);
    unlink(PIPE_NAME);

    return 0;
*/
