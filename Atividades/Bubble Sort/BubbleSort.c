#include<stdio.h>

int main(){

   int quantidade, auxiliar, i, j, N[30];

   printf("Quantos Numeros voce quer ordenar?: ");
   scanf("%d",&quantidade);

   for(i=0;i<quantidade;i++){
   printf("Digite o N%d: ",i+1);
   scanf("%d",&N[i]);
   }  

   //BubbleSort
   for(i=quantidade-2;i>=0;i--){
      for(j=0;j<=i;j++){
        if(N[j]>N[j+1]){
           auxiliar=N[j];
           N[j]=N[j+1];
           N[j+1]=auxiliar;
        }
      }
   }

   printf("Numeros Ordenados: ");
   for(i=0;i<quantidade;i++)
   printf("%d",N[i]);
   
}
