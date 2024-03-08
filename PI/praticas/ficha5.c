typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

void swap(int a[], int i, int j) { int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

int nota (Aluno a){
    int classificacao, soma = 0, media;
    
    for (int i = 0; i < 6; i++){
        soma += Aluno.miniT[i];
    }

    media = soma/6;

    classificacao = media * 0.20 + Aluno.teste * 0.80;
    
    if (classificacao < 9.5) return 0;
    else return 1;
}

int procuraNum (int num, Aluno t[], int N){
    for (int i = 0; i < N; i++){
        if (t[i].numero == num){
            return i
        }
        else return -1;
    }
}

void ordenaPorNum (Aluno t [], int N){
int i, j, min_idx;
Aluno temp;
   for (i = 0; i < n-1; i++) {
      min_idx = i;
      for (j = i+1; j < n; j++) {
         if (t[j].numero < t[min_idx].numero) {
            min_idx = j;
         }
      }
      int temp = t[min_idx];
      t[min_idx] = t[i];
      t[i] = temp;
   }
}

void criaIndPorNum (Aluno t [], int N, int ind[]){
 
}