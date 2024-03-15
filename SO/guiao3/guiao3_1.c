#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf ("Mensagem 1\n");

    pid_t pid = fork(); // cria um processo filho

    if (pid < 0) {
        perror("Erro no fork");
        return 1;
    }
    if (pid > 0) {
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Filho terminou com %d\n", WEXITSTATUS(status));
        }
    }
    else {
        int res = execl ("/bin/ls", "ls", "-l", NULL); // se o path estiver incorreto ou a flag (-l neste caso) ou o comando, a mensagem 2 é impressa
        // ou execlp ("ls", "ls", "-l", NULL);
        _exit (res);
    }
    printf ("Mensagem 2\n"); // nao aparece porque o processo (pid) foi substituido pelo ls. Podemos usar um fork para evitar isto
    return 0;
}