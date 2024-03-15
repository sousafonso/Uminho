#include <unistd.h>     /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h>   /* chamadas wait*() e macros relacionadas */
#include <stdio.h>
#include <stdlib.h>

/**
 * THEORY
*/

/**
 * @brief troca o programa em execução pelo executável definido pelos
argumentos da função

    * @param path: caminho para o executável
    * @param arg0: nome do executável
    * @param ...: argumentos para o executável
    * @return int: -1 em caso de erro
*/
int execl(const char *path, const char *arg0, ..., NULL); 

/**
 * @brief Semelhante à chamada anterior mas recorre aos
caminhos registados na variável de ambiente PATH

    * @param file: nome do executável
    * @param arg0: nome do executável
    * @param ...: argumentos para o executável
    * @return int: -1 em caso de erro
    
    Exemplo: em vez de “/bin/ls” o argumento file poderia
ser apenas “ls”.
*/
int execlp(const char *file, const char *arg0, ..., NULL); 
int execv(const char *path, char *const argv[]); 
int execvp(const char *file, char *const argv[]);