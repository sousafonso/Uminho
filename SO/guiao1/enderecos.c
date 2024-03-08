#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * Exercício 3 guiao1
*/
int main (int argc, char *argv[]){
    int i = 10;
    int j = 20;
    int h = 0;

    printf ("Endereços: %p %p %p\n", &i, &j, &h);
    printf ("Valores: %d %d %d\n", i, j, h);
    printf ("Tamanhos: %lu %lu %lu\n", sizeof(i), sizeof(j), sizeof(h));

    int fd = open("teste", O_CREAT | O_RDWR, 0600);

    // ao escrever no ficheiro, o nosso ficheiro de teste vai ter 8 bytes
    write(fd, &i, sizeof(i));
    write(fd, &j, sizeof(j));

    // ao ler do ficheiro, o nosso ficheiro de teste vai ter 8 bytes
    /**
     * fseek(fd, off_t offset, whence) - coloca o cursor no início do ficheiro
     * "fd" é o descritor do ficheiro
     * "offset" é o número de bytes que queremos avançar, pode ser negativo para recuar
     * "whence" é o ponto de referência para onde queremos avançar
     * 
     * SEEK_SET - início do ficheiro
     * SEEK_CUR - posição atual do cursor
     * SEEK_END - fim do ficheiro
     * 
     * Relativamente a um destes whences, quantas vezes queremos avançar ou recuar de acordo com o número em offset
     */ 

    ssize_t res = read(fd, &h, sizeof(h));
    printf("Bytes lidos: %ld\n", res); // imprime 4 porque leu 4 bytes

    lseek(fd, 0, SEEK_SET);

    // ou 

    //seek(fd, -sizeof(int)*2, SEEK_SET); // para recuar 8 bytes já que escrevemos dois inteiros de 4 bytes

    res = read(fd, &h, sizeof(h));
    printf("Bytes lidos: %ld\n", res); // imprime 4 porque leu 4 bytes
}