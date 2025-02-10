#include <stdio.h>
#include <stdlib.h>

struct Fila{

	int tamanho;
	float *valores;
	int primeiro;
	int ultimo;
	int quantidade; 
};

void criarFila( struct Fila *x, int c ){ 
	x->tamanho = c;
	x->valores = (float*) malloc (x->tamanho * sizeof(float));
	x->primeiro = 0;
	x->ultimo = -1;
	x->quantidade = 0; 

}

void inserir(struct Fila *x, int v){

	if(x->ultimo == x->tamanho-1)
		x->ultimo = -1;

	x->ultimo++;
	x->valores[x->ultimo] = v; 
	x->quantidade++; 
}

int remover( struct Fila *x ){ 
	int temp = x->valores[x->primeiro++];

	if(x->primeiro == x->tamanho)
		x->primeiro = 0;

	x->quantidade--;  
	return temp;
}

int estaVazia( struct Fila *x ){ 
	return (x->quantidade==0);
}

int estaCheia( struct Fila *x ){ 
	return (x->quantidade == x->tamanho);
}

void mostrarFila(struct Fila *x){
	int cont, i;

	for ( cont=0, i= x->primeiro; cont < x->quantidade; cont++){
		printf("%.2f\t",x->valores[i++]);
		if (i == x->tamanho)
			i=0;
	}
	printf("\n\n");
}

main (){

	int opcao, tamanho2;
	float valor;
	struct Fila Fila2;

	printf("\nTamanho da fila: ");
	scanf("%d",&tamanho2);
	criarFila(&Fila2, tamanho2);

	while(1){

		printf("\n1 - Inserir elemento\n");
		printf("2 - Remover elemento\n");
		printf("3 - Mostrar Fila\n");
		printf("0 - Sair\n");
		printf("Opcao: ");
		scanf("%d", &opcao);

		switch(opcao){

			case 0: exit(0);

			case 1: 
				if(estaCheia(&Fila2)){
					system("cls");
					printf("\nA Fila esta cheia\n\n");
				}
				else{
					printf("\nQual numero quer inserir? ");
					scanf("%f", &valor);
					inserir(&Fila2,valor);
					system("cls");
					printf("O Numero %1.2f foi inserido com sucesso\n",valor);	
				}
				break;

			case 2: 
				if(estaVazia(&Fila2)){
					system("cls");
					printf("\nA Fila esta vazia\n\n");
				}
				else{
					system("cls");
					valor = remover(&Fila2);
					printf("\n%1.2f removido com sucesso\n\n", valor) ; 
				}
				break;

				case 3:
				if(estaVazia(&Fila2)){
					system("cls");
					printf("\nA Fila esta vazia\n\n");
				}
				else{
					system("cls");
					printf("\nFila => ");
					mostrarFila(&Fila2);
					
				}
				break;

				default:
				system("cls");
				printf("\nOpcao Invalida\n\n");

		}
	}
}
