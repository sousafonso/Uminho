#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int pd[2];
    int ret = pipe(pd);
    int status;

    pid_t pid = fork();

    if (pid == 0) { // filho (consumidor)
        close(pd[1]);
        int res = 0;
        ssize_t read_bytes = read (pd[0], &res, sizeof(res));

        printf ("Filho leu %d bytes cujo valor é %d\n", read_bytes, res);
        close(pd[0]);
    }
    else { // pai (produtor) 
        close(pd[0]);
        int res = 10;

        sleep(5);

        ssize_t write_bytes = write(pd[1], &res, sizeof(res));

        printf ("Pai escreveu o valor %d cujo tamanho é de %d bytes\n", res, write_bytes);
        close(pd[1]);

        pid_t terminated_pid = wait(&status);

        if (WIFEXITED(status))
            printf("O filho terminou com código de saída %d\n", WEXITSTATUS(status));
        else
            printf("O filho terminou de forma anormal\n");

    }
    return 0;
}

/**
 * @def: read (guarda, o quê, que tamanho)
 * @def: write (guarda, o quê, que tamanho)
*/