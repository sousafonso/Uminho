#include <stdio.h>
#include <string.h>

#define MAX_N 100
#define MAX_K 100
#define MAX_NAME_LEN 100

// Função para contar a quantidade de letras em uma cadeia
void count_letters(char *str, int *count) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        count[str[i] - 'A']++;
    }
}

// Função para comparar duas cadeias de caracteres
int compare_names(char *name1, char *name2) {
    int count1[26] = {0};
    int count2[26] = {0};
    count_letters(name1, count1);
    count_letters(name2, count2);
    int i;
    for (i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int i, j, k;
    char villain[MAX_NAME_LEN + 1];
    char candidates[MAX_K][MAX_NAME_LEN + 1];
    int num_candidates;
    for (i = 0; i < n; i++) {
        scanf("%d", &num_candidates);
        scanf(" %[^\n]s", villain);
        int villain_count[26] = {0};
        count_letters(villain, villain_count);
        int found = 0;

        for (j = 0; j < num_candidates; j++) {
            scanf(" %[^\n]s", candidates[j]);
            if (compare_names(villain, candidates[j])) {
                printf("%d ", j + 1);
                found = 1;
            }
        }
        if (!found) {
            printf("-1");
        }
        printf("\n"); // adiciona uma mudança de linha após imprimir o resultado
    }
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkSubstring(char str1[], char str2[]) { // função que compara duas strings
    int i, j, flag;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    for (i = 0; i < len1; i++) {
        flag = 0;
        for (j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, k, i, j, y, comparison, contador_anagramas, results[n][k];
    char vilao[101], anagrama[101];

    if (scanf("%d", &n) != 1){ // leitura do número de casos
        return 1;
    }

    for (i = 0; i < n; i++){ // iteração para o número de casos

        if (scanf ("%d", &k) != 1){ // número de possíveis "anagramas"
            return 1;
        }

        if (scanf("%s", &vilao[101]) != 1){ // nome do vilao
            return 1;
        }

        j = 0;
        for (y = 0; vilao[y] != '\0'; y++){ // eliminar espaços da string
            if (!isspace(vilao[y])) { 
                vilao[j] = vilao[y]; j++;
            }
        }
            vilao[j] = '\0';

        for (int w = 0; w < k; w++){ // "receber os anagramas"
            if (scanf("%s\n", &anagrama[101]) != 1){
                return 1;
            }

            j = 0;

            for (y = 0; anagrama[y] != '\0'; y++){ // eliminar espaços do suposto anagrama

                if (!isspace(anagrama[y])) { 
                    anagrama[j] = anagrama[y]; j++;
                }

            }

            anagrama[j] = '\0';

            comparison = checkSubstring(anagrama, vilao); // 1 para iguais, 0 para diferentes
            
            j = contador_anagramas = 0;

            if (comparison){
                results[i][j] = w; j++;
                contador_anagramas++;
            }
            else {
                results[i][0] = -1;
            }
        }
    }

    printf("\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < contador_anagramas; j++){
            printf ("%d ", results[i][j]);
        }
        printf ("\n");
    }
    return 0;
}
*/