#include <stdio.h>
#include <stdlib.h>
#include "simple.h"

/**
 * "argc" is the number of arguments passed to the program
 * "argv" is an array of strings containing the arguments
 * "argv[0]" is the name of the program
 * "argv[1]" is the first argument
 * "argv[2]" is the second argument
 * 
 * char ocupa 1 byte
*/

int main (int argc, char *argv[]) {

    printf ("Argumento 1: %s\n", argv[1]);
    printf ("Argumento 2: %s\n", argv[2]);

    // int ocupa 4 bytes
    int i = atoi(argv[1]);
    int* ptr = &i; // se o comando fosse ./nome 10 20, o valor de ptr é o valor da posição de memória de i

    printf("Tamanho de i: %lu\n", sizeof(i));
    printf("Tamanho de ptr: %lu\n", sizeof(ptr));
    printf("Valor de i: %d\n", i);
    printf("Endereço de i: %p\n", &i);
    printf("Valor de ptr: %p\n", ptr);
    printf("Endereço de ptr: %p\n\n\n", &ptr);

    int res1 = inc1(i);
    int res2 = inc2(ptr);

    printf("Resultado de inc1: %d\n", res1);
    printf("Resultado de inc2: %d\n\n\n", res2);

    // arrays
    int arr[2]; // não preciso de dar free porque é um array estático (não foi alocado dinamicamente) e é automaticamente libertado
    int* arr = malloc(2 * sizeof(int)); // preciso de dar free
    arr[0] = atoi(argv[1]);
    arr[1] = atoi(argv[2]);

    printf("arr[0]: %d\n", arr[0]);
    printf("&arr[0]: %p\n", &arr[0]);

    free(arr);
}

/**
 * #ref é o número de processos que estão a trabalhar num "ficheiro"
 * r - red que se passa a designar O_RDONLY
 * w - write que se passa a designar O_WRONLY
 * rw - read and write que se passa a designar O_RDWR
*/

/* CHAMADAS AO SISTEMA
 *
 * int open(const char *pathname, int oflags[, mode_t mode]);
 * "pathname" é o nome do ficheiro
 * "oflags" é o modo de abertura do ficheiro
 * "open" retorna o descritor do ficheiro
 * "mode" é o modo de acesso ao ficheiro. Para permissoes de leitura e escrita, o valor é 0666. Para permissoes de leitura, escrita e execução, o valor é 0777
 * é possível saber os códigos através do site https://chmod-calculator.com
 * 
 * 
 * ssize_t read(int fildes, void *buf, size_t nbyte);
 * "fildes" é o descritor do ficheiro
 * "buf" é o buffer onde os dados lidos vão ser guardados
 * "nbyte" é o número de bytes a ler
 * 
 * 
 * ssize_t write(int fildes, const void *buf, size_t nbyte);
 * "fildes" é o descritor do ficheiro
 * "buf" é o buffer onde os dados a escrever estão guardados
 * "nbyte" é o número de bytes a escrever
 * 
 * int close(int fildes);
 * "fildes" é o descritor do ficheiro
 * devolve 0 se fechar o ficheiro com sucesso
*/