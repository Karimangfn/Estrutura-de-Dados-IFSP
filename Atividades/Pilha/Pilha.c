#include <stdio.h>
#include <stdlib.h>

struct Pilha{

	int topo; 
	int tamanho;
	float *pElem;
};

void criarpilha(struct Pilha *p, int c){

   p->topo = -1;
   p->tamanho = c;
   p->pElem = (float*) malloc (c * sizeof(float));

}
int estavazia (struct Pilha *p){

   if(p-> topo == -1)
      return 1;   
   else
      return 0;   
}

int estacheia (struct Pilha *p){
	
	if (p->topo == p->tamanho - 1)
		return 1;
	else
		return 0;
}

void empilhar (struct Pilha *p, float v){

	p->topo++;
	p->pElem [p->topo] = v;
}

float desempilhar (struct Pilha *p){

   float auxiliar = p->pElem [p->topo];
   p->topo--;
   return auxiliar;
}

float retornatopo (struct Pilha *p){

   return p->pElem [p->topo];
}

int main(){

	struct Pilha Pilha2;
	int tamanho2, op;
	float valor;

	printf("\nTamanho da Pilha: ");
	scanf("%d", &tamanho2);

	criarpilha (&Pilha2, tamanho2);

	while(1){

		printf("\n1- Empilhar (Push)\n");
		printf("2- Desempilhar (Pop)\n");
		printf("3- Mostrar o Topo \n");
		printf("4- Sair\n");
		printf("\nOpcao: ");
		scanf("%d", &op);
		system("cls");

		switch (op){

			case 1: 
				if(estacheia(&Pilha2) == 1)
					printf("\nA Pilha esta cheia\n");
				else{
					printf("\nVALOR? ");
					scanf("%f", &valor);
					empilhar (&Pilha2, valor);
				}
				break;

			case 2: 
				if (estavazia(&Pilha2) == 1)
					printf("\nA Pilha esta vazia\n");
				else{
					valor = desempilhar (&Pilha2);
					printf ("\nNumero %.1f Desempilhado\n", valor);
				}
				break;

			case 3: 
				if (estavazia (&Pilha2) == 1)
					printf("\nA Pilha esta Vazia\n");
				else {
					valor = retornatopo (&Pilha2);
					printf ("\nTopo: %.1f\n", valor);
				}
				break;

			case 4: 
			exit(0);
			default: printf("\nOpcao Invalida\n");
		}
	}
	
}
