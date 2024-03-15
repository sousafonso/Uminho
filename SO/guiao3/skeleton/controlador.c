#include <stdio.h>
#include "mysystem.h"

void controller(int N, char** commands) {
	int ret;
	for(int i = 0; i < N; i++) {
		printf("\nCOMANDO %d: a executar mysystem para %s\n", i, commands[i]);
		ret = mysystem(commands[i]);
		printf("COMANDO %d: ret = %d\n", i, ret);
	}
}

int main(int argc, char* argv[]) { 

    char *commands[argc-1];
    int N = 0;
	for(int i=1; i < argc; i++){
		commands[N] = strdup(argv[i]);
		printf("command[%d] = %s\n", N, commands[N]);
        N++;
	}

	controller(N, commands);

	return 0;
}