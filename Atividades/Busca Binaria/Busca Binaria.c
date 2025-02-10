#include <stdio.h>
#include <stdlib.h>

void LeVetor(int vet[]);
void ImprimeVetor(int vet[]);
void OrdenaVetor(int v[]);
int PesquisaBinaria(int v[], int pesq);
int Menu();

    main(){
    int vet[5];
    int opcao, pos, procura;
    LeVetor(vet);
    OrdenaVetor(vet);

    do{
        opcao=Menu();
        if (opcao==1){
            ImprimeVetor(vet);
            getch();
        }
        else if (opcao==2){
            printf ("\nDigite um valor para pesquisar: ");
            scanf("%d",&procura);
            pos=PesquisaBinaria(vet,procura);
            if (pos==-1){
                printf("\n\nValor nao encontrado no vetor!");
            }
            else{
                printf("\n\nValor encontrado na posicao %d", pos+1);
            }
            getch();
        }
    }
    while (opcao!=0);

    printf("\n\n");
    system("PAUSE>>NULL");
}

void LeVetor(int vet[]){
      int i;
      for (i=0;i<5;i++){
          printf("Informe o valor N%d: ", i+1);
          fflush(stdin);
          scanf("%d", &vet[i]);
      }
}

void ImprimeVetor(int vet[]){
      int i;
      for (i=0;i<5;i++){
          printf("%d ", vet[i]);
      }
}

void OrdenaVetor(int v[]){
      int i,j,aux;

      for (i=0;i<5-1;i++){
          for (j=i+1;j<5;j++){
                  if (v[i] > v[j]){      
                      aux=v[i];
                      v[i]=v[j];
                      v[j]=aux;
                   }
              }
      }     
}


int PesquisaBinaria(int v[], int pesq){
     int comeco = 0; 
     int final = 5-1; 
                            
     int meio;
     while (comeco <= final){
          meio = (comeco + final)/2;
          if (pesq == v[meio])
               return meio;
          else if (pesq < v[meio])
               final = meio-1;
          else
               comeco = meio+1;
     }
     return -1;   
}



int Menu(){
     int opcao;
     system("cls");
     printf("BUSCA BINARIA\n");
     printf("_____________\n\n");
     printf("Digite a opcao desejada:\n\n");
     printf("[1] Ver o vetor ordenado\n");
     printf("[2] Pesquisar um valor\n");
     printf("[0] Sair\n\n");
     printf("Digite a opcao desejada: ");
     fflush(stdin);
     scanf("%d", &opcao);
     return opcao;
}
