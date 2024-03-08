#include <stdio.h>

int main(){
    FILE *fp;
    fp = fopen ("testes.txt", "w");

    if (fp == NULL) printf ("file not found!");
    else fputs ("j", fp);
    fclose(fp);
    return 0;
}