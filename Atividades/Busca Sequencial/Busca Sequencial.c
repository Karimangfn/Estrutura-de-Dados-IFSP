#include <stdio.h>
#include <stdlib.h>

#define tamanho 5

void LeVetor(int vet[]);
void ImprimeVetor(int vet[]);
int PesquisaSequencial(int v[], int pesq);

main(){ 	
    int vet[tamanho];
    int pos, procura;
    LeVetor(vet);
        
    printf ("\nDigite um valor para pesquisar: ");
    scanf("%d",&procura);
    ImprimeVetor(vet);
    
    pos=PesquisaSequencial(vet,procura);
    if (pos==-1){
        printf("\n\nValor nao encontrado no vetor!");
    }
    else{
        printf("\n\nValor encontrado na posicao %d", pos+1);    
    }
       
    printf("\n\n");  
    system("PAUSE>>NULL");	
    return 0;
}

void LeVetor(int vet[]){
      int i;
      for (i=0;i<tamanho;i++){
          printf("Digite o valor N%d: ", i+1);
          fflush(stdin);
          scanf("%d", &vet[i]);
      }
}

void ImprimeVetor(int vet[]){
      int i;
      for (i=0;i<tamanho;i++){
          printf("%d ", vet[i]);
      }
}

int PesquisaSequencial(int v[], int pesq){
     int i;
     for(i=0;i<tamanho;i++){
          if(v[i]==pesq){
              return i;
          }
     }
     return -1;
}
