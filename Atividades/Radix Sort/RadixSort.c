#include <stdio.h>

void radixsort(int vetor[], int tamanho) {
  int i;
  int b[tamanho];
  int maior = vetor[0];
  int exp = 1;

  for (i = 0; i < tamanho; i++) {
  if (vetor[i] > maior)
  maior = vetor[i];
}

  while (maior/exp > 0) {
  int bucket[10] = { 0 };
  for (i = 0; i < tamanho; i++)
  bucket[(vetor[i] / exp) % 10]++; 
  for (i = 1; i < 10; i++)
  bucket[i] += bucket[i - 1]; 
  for (i = tamanho - 1; i >= 0; i--)
  b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
  for (i = 0; i < tamanho; i++)
  vetor[i] = b[i];
  exp *= 10;
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

 radixsort(vetor,tamanho);
 
  printf("\n\nValores ordenados\n");
  for(i = 0; i < tamanho; i++){
  printf("%d\n", vetor[i]);
  }
}
