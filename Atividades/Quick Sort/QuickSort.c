#include <stdio.h>
#include <stdlib.h>

void quick_sort(int a[20], int esquerda, int direita);

main(){
 int i, vetor[20], quantidade;
 
  printf("Quantos Numeros voce quer ordenar?: ");
  scanf("%d",&quantidade);
 
  for(i = 0; i < quantidade; i++){
  printf("Digite um valor: ");
  scanf("%d", &vetor[i]);
  }

 quick_sort(vetor, 0, quantidade - 1);
 
  printf("\n\nValores ordenados\n");
  for(i = 0; i < quantidade; i++){
  printf("%d\n", vetor[i]);
  }
  }
 

void quick_sort(int a[20], int esquerda, int direita) {
    int i, j, pivot, auxiliar;
     
    i = esquerda;
    j = direita;
    pivot = a[(esquerda + direita) / 2];
     
    while(i <= j) {
        while(a[i] < pivot && i < direita) {
            i++;
        }
        while(a[j] > pivot && j > esquerda) {
            j--;
        }
        if(i <= j) {
            auxiliar = a[i];
            a[i] = a[j];
            a[j] = auxiliar;
            i++;
            j--;
        }
    }
     
    if(j > esquerda) {
        quick_sort(a, esquerda, j);
    }
    if(i < direita) {
        quick_sort(a, i, direita);
    }
}
