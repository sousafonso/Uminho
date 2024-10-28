#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/teste.h"

extern int qual_query[501];
extern int Contaficheiros;
int x = 0;

void compara_output(char *path3) {

    char filename[64];
    snprintf(filename, sizeof(filename), "Resultados/compara_outputs.txt");

    FILE *file = fopen(filename, "a");

    if (file != NULL){
    for (int i = 1; i <= Contaficheiros && i; ++i) {
        char esperado[100];
        char obtido[100];
        int k = 0, LinhasErradas = 0;

        sprintf(esperado, "%s/command%d_output.txt",path3, i);
        sprintf(obtido, "Resultados/command%d_output.txt", i);

        FILE *expected = fopen(esperado, "r");
        FILE *actual = fopen(obtido, "r");

        if (expected == NULL || actual == NULL) {
            fprintf(file,"Erro ao abrir os ficheiros do comando %d.\n", i);
        }

         char *esperadoLinha = NULL;
        char *obtidoLinha = NULL;
        size_t len = 0;
        ssize_t read, reado;

        int numLinhas = 1;

        while (1) {
            read = getline(&esperadoLinha, &len, expected);
            reado = getline(&obtidoLinha, &len, actual);
            
            if(read == -1 && reado == -1) break;
            if (read == -1) esperadoLinha = NULL;
            else if (reado == -1) obtidoLinha = NULL;

            int VerNull = 1;
            if(esperadoLinha == NULL && obtidoLinha == NULL) break;
            else if((esperadoLinha == NULL && obtidoLinha != NULL) || (esperadoLinha != NULL && obtidoLinha == NULL)) VerNull = 0;

            if (VerNull == 0 || strcmp(esperadoLinha, obtidoLinha) != 0) {
                VerNull = 1;
                if(k != 1){
                    fprintf(file,"\n--------------Comando %d (query%d)--------------\n", i, qual_query[i]);
                    fprintf(file,"O comando %d tem diferenças na linha %d.\n", i, numLinhas);
                    fprintf(file,"%s: %s", esperado, esperadoLinha);
                    fprintf(file,"%s: %s\n", obtido, obtidoLinha);
                    k = 1;
                    x = 1;
                }
                LinhasErradas++;
            }
            numLinhas++;
        }
        if(LinhasErradas > 1) fprintf(file,"A seguir dessa primeira linha errada, existem mais %d linhas erradas.\n", LinhasErradas - 1);
        if (k == 0 ){
            if(x == 1){
                x = 0;
                fprintf(file,"\n");
            }
            fprintf(file,"O comando %d está correto!\n", i);
        }
        fclose(expected);
        fclose(actual);

        free(esperadoLinha);
        free(obtidoLinha);
    }
    fclose(file);
    printf("\nFoi criado um ficheiro na pasta resultados que compara os outputs esperados com os que é suposto obter.\n");

    }
}
