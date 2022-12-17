#include <stdio.h>

void insertionsort(int vetor[20], int tamanho)
{
 int i, j, auxiliar;
  
 for(i = 1; i < tamanho; i++){
  auxiliar = vetor[i];
  for(j = i-1; j >= 0 && auxiliar < vetor[j]; j--){
   vetor[j+1] = vetor[j];
  }
  vetor[j+1] = auxiliar;
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

 insertionsort(vetor,tamanho);
 
  printf("\n\nValores ordenados\n");
  for(i = 0; i < tamanho; i++){
  printf("%d\n", vetor[i]);
  }
}
