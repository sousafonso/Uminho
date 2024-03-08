#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

// execução sequencial
int main(){
    pid_t pid; // process id
    int status; // estado de terminação do processo
    for (int i = 0; i < 10; i++){
        if((pid = fork()) == 0){ // filho
        printf("Filho: %d\n", getpid());
        sleep(1); // espera 1 segundo
        _exit(i); // termina o processo filho
        }
        else{ // pai
            pid_t terminated_pid = wait(&status); // espera que o filho termine

            if(WIFEXITED(status)){ // verifica se o filho terminou normalmente
                printf("Pai: %d\n", getpid());
                printf("Filho terminou: %d\n", terminated_pid);
                printf("Código de saída: %d\n", WEXITSTATUS(status));
            }
        }
    }

    printf("Fim\n");
    return 0;
}