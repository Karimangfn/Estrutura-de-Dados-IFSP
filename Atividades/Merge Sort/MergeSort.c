#include <stdio.h>
#include <stdlib.h>

void mergesort(int *v, int n);
void merge(int *v, int *c, int i, int m, int f);
void sort(int *v, int *c, int i, int f);


main () {
  int i;
  int quantidade;
  int v[20];
  
  printf("Quantos Numeros voce quer ordenar?: ");
  scanf("%d",&quantidade);
  
  for(i=0;i<quantidade;i++){
   printf("Digite o N%d: ",i+1);
   scanf("%d",&v[i]);
   }  
   mergesort(v, quantidade);
  
  printf("\n\nValores ordenados\n");
  for (i = 0; i < quantidade; i++) 
  printf("%d ", v[i]);
}


void mergesort(int *v, int quantidade) {
  int *c = malloc(sizeof(int) * quantidade);
  sort(v, c, 0, quantidade - 1);
  free(c);
}

void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  if (v[m] <= v[m + 1]) return;
  merge(v, c, i, m, f);
}

void merge(int *v, int *c, int i, int m, int f) {
  int z;
  int iv = i;
  int ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];
  z = i;
  
  while (iv <= m && ic <= f){
    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }
  
  while (iv <= m) v[z++] = c[iv++];
  while (ic <= f) v[z++] = c[ic++];
}
