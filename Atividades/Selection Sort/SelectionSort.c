#include <stdio.h>

void SelectionSort(int vetor[], int tamanho) {
	int i;
	int j;
   for(i = 0; i < tamanho - 1; i++) {
      int menor = i;
      for(j = i + 1; j < tamanho; j++) {
         if (vetor[j] < vetor[menor]) menor = j;
      }
      int aux = vetor[i];
      vetor[i] = vetor[menor];
      vetor[menor] = aux;
   }
}

main(){
 int i, vetor[20], tamanho;
 
  printf("Quantos Numeros voce quer ordenar?: ");
  scanf("%d",&tamanho);
 
  for(i = 0; i < tamanho; i++){
  printf("Digite um valor: ");
  scanf("%d", &vetor[i]);
  }

 SelectionSort(vetor,tamanho);
 
  printf("\n\nValores ordenados\n");
  for(i = 0; i < tamanho; i++){
  printf("%d\n", vetor[i]);
  }
  }
