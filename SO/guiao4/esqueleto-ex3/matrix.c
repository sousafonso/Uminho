#include "matrix.h"
#include <unistd.h>
#include <sys/wait.h>

int **createMatrix() {

    // seed random numbers
    srand(time(NULL));

    // Allocate and populate matrix with random numbers.
    printf("Generating numbers from 0 to %d...", MAX_RAND);
    int **matrix = (int **) malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = (int*) malloc(sizeof(int) * COLUMNS);
        for (int j = 0; j < COLUMNS; j++) {
            matrix[i][j] = rand() % MAX_RAND;
        }
    }
    printf("Done.\n");

    return matrix;
}

void printMatrix(int **matrix) {

    for (int i = 0; i < ROWS; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < COLUMNS; j++) {
            printf("%7d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void lookupNumber(int** matrix, int value, int* vector){
    int status;
    int pd[2];
    pipe(pd);

    for (int i = 0; i < ROWS; i++) {
        pid_t pid = fork();
        if (pid == 0) { // filho
            close(pd[0]);
            int counter = 0;
            for (int j = 0; j < COLUMNS; j++) {
                if (matrix[i][j] == value) {
                    counter++;
                }
            }
            write(pd[1], &counter, sizeof(counter));
            close(pd[1]);
            _exit(0);
        }
    }

    for (int i = 0; i < ROWS; i++) {
        int received_data;
        read(pd[0], &received_data, sizeof(received_data));
        vector[i] = received_data;
    }
    close(pd[0]);

    for (int i = 0; i < ROWS; i++) {
        wait(&status);
    }
}