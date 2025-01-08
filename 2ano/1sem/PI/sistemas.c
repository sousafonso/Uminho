#include<stdio.h>
int array[100], sum=0;
int main () {
    int i;
    for (i=0; i<100; i++)
        scanf("%d", &array[i]);
    for (i=0; i<100 && array[i]>0; i++)
    sum += array[i];
}