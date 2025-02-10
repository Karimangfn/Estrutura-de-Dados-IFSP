#include <stdio.h>
#include <stdlib.h>

typedef struct Estrutura{
    int valor;
    struct Estrutura *proximo;
}Lista;

void inserir_no_inicio(Lista **lista, int num){
    Lista *novo = malloc(sizeof(Lista));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
        printf("Erro\n");
}

void inserir_no_fim(Lista **lista, int num){
    Lista *aux, *novo = malloc(sizeof(Lista));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if(*lista == NULL)
            *lista = novo;
        else{
            aux = *lista;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro\n");
}

void inserir_no_meio(Lista **lista, int num, int ant){
    Lista *aux, *novo = malloc(sizeof(Lista));

    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->valor != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro\n");
}

void inserir_ordenado(Lista **lista, int num){
    Lista *aux, *novo = malloc(sizeof(Lista));

    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }
        else if(novo->valor < (*lista)->valor){
            novo->proximo = *lista;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro\n");
}

void imprimir(Lista *no){
    printf("\n\tLista: ");
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

main(){

    int opcao, valor, anterior;
    Lista *lista = NULL;

    do{
        printf("1 - Inserir no Inicio\n");
        printf("2 - inserir no Final\n");
        printf("3 - Inserir no Meio\n");
        printf("4 - Inserir Ordenada\n");
        printf("5 - Mostrar Lista\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            system("cls");
            printf("O Numero %d foi inserido com sucesso\n\n",valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);
            system("cls");
            printf("O Numero %d foi inserido com sucesso\n\n",valor);
            break;
        case 3:
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d%d", &valor, &anterior);
            inserir_no_meio(&lista, valor, anterior);
            system("cls");
            printf("O Numero %d foi inserido com sucesso\n\n",valor);
            break;
        case 4:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            system("cls");
            printf("O Numero %d foi inserido com sucesso\n\n",valor);
            break;
        case 5:
        	system("cls");
            imprimir(lista);
            break;
        default:
            if(opcao != 0);
            system("cls");
            printf("Opcao invalida!\n\n");
        }

    }while(opcao != 0);
}
