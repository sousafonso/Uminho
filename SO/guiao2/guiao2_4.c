#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

// execução paralela relativamente à alinea 3
int main() {
    pid_t pids[10]; // Array para armazenar os PIDs dos processos filhos
    int i;

    // Cria 10 processos filhos
    for (i = 0; i < 10; i++) {
        pids[i] = fork();
        if (pids[i] == 0) { // Processo filho
            // Simula um trabalho com sleep
            sleep(1); // Remove ou ajusta este sleep conforme necessário para simular trabalho
            _exit(i+1); // Cada filho termina com um código diferente
        }
    }

    // O processo pai espera por todos os processos filhos
    for (i = 0; i < 10; i++) {
        int status;
        pid_t pid = waitpid(pids[i], &status, 0); // Espera especificamente pelo filho pids[i]
        if (WIFEXITED(status)) {
            printf("Filho %d terminou com código de saída %d\n", pid, WEXITSTATUS(status));
        }
    }

    printf("Pai terminou\n");
    return 0;
}
