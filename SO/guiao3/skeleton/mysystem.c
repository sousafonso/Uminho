#include "mysystem.h"
#include <string.h>

// recebe um comando por argumento
// returna -1 se o fork falhar
// caso contrario retorna o valor do comando executado
int mysystem (const char* command) {

	char* exec_args[20];
	char* token;
	char* cmd;
	int exec_ret, status;
	cmd = strdup(command);
	int i = 0;

	while ((token = strsep(&cmd, " ")) != NULL) {
		exec_args[i++] = token;
	}

	exec_args[i] = NULL;

	int res = -1;

	int fork_ret = fork();
	switch (fork_ret) {
		case -1:
			perror("Erro no fork");
			return -1;
		case 0:
			exec_ret = execvp(exec_args[0], exec_args);
			_exit(exec_ret);
		default:
			wait(&status);
			if (WIFEXITED(status)){
				if (WEXITSTATUS(status) == 255) {
					res = -1;
				}
				else {
					res = WEXITSTATUS(status);
				}
			}

	}
	return res;
}