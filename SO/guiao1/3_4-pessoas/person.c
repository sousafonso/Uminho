#include "person.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int new_person(char* name, int age) {
    int fd = open(FILENAME, O_WRONLY | O_APPEND | O_CREAT, 0644);

    /**
     * O_WRONLY - abre o ficheiro para escrita
     * O_APPEND - acrescenta no final do ficheiro
     * O_CREAT - cria o ficheiro se não existir
    */

    // se nao usasse O_APPEND, estaria a escrever por cima do ficheiro. Podia eventualmente usar fseek para ir para o fim do ficheiro
    // fseek(fd, 0, SEEK_END);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    Person p;
    strcpy(p.name, name);
    p.age = age;

    int ret = write(fd, &p, sizeof(Person));
    if (ret == -1) { 
        perror("write");
        return 1;
    }

    close(fd);
    return 0;
}

// está a listar as pessoas todas
int list_persons(int N) {
    int fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("open error");
        return -1;
    }

    Person p;
    char output[100];
    int output_size = 0;
    int i = 0;

    // read returns 0 when it reaches the end of the file
    while ((read(fd, &p, sizeof(Person))) > 0 && i < N) {
        output_size = sprintf(output, "Name: %s, Age: %d\n", p.name, p.age);
        write(1, output, output_size);
        i++;
    }

    close(fd);
    return 0;
}

int change_age(char* name, int age) {
    int fd = open(FILENAME, O_RDWR, 0600);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    Person p;
    int ret;
    while ((ret = read(fd, &p, sizeof(Person))) > 0) {
        if (ret == -1) {
            perror("read");
            return 1;
        }

        if (strcmp(p.name, name) == 0) {
            p.age = age;
            lseek(fd, -sizeof(Person), SEEK_CUR);
            ret = write(fd, &p, sizeof(Person));
            if (ret == -1) {
                perror("write");
                return 1;
            }
        }
    }

    close(fd);
    return 0;
}

int change_age_v2(int position, int age) {
    int fd = open(FILENAME, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    Person p;
    int ret;
    lseek(fd, position * sizeof(Person), SEEK_SET);
    ret = read(fd, &p, sizeof(Person));
    if (ret == -1) {
        perror("read");
        return 1;
    }

    p.age = age;
    lseek(fd, -sizeof(Person), SEEK_CUR);
    ret = write(fd, &p, sizeof(Person));
    if (ret == -1) {
        perror("write");
        return 1;
    }

    close(fd);
    return 0;
}