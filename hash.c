#include <stdio.h>
#include "hash.h"

int Hash(int chave){

	return chave % TAM;
}

void CriarLista(Lista *l){
    
    l->first = NULL;
    l->tam = 0;
    l->col = 0;

}

void ListaInsert(Lista *l, int chave){
	
	BlockKey *novo = malloc(sizeof(BlockKey));

	novo->chave = chave;
    novo->prox = l->first;

	if(l->first == NULL){

    	l->first = novo;
    	l->tam++;

	}else{

		l->first = novo;
    	l->tam++;
    	l->col++;
	}

	/*novo->chave = chave;
    novo->prox = l->first;
    l->first = novo;
    l->tam++;
	*/
}

void ImprimirLista(Lista *l){

	BlockKey *aux = l->first;

	while(!(aux == NULL)){

		printf("%d ", aux->chave);
		aux = aux->prox;

	}

	printf("----->[%d]",l->tam);

}

void CriarHS(Lista t[]){

	for(int i = 0; i < TAM; i++) {

		CriarLista(&t[i]);

	}
}

void InsertHS(Lista t[], int chave){

	int p = Hash(chave);
	ListaInsert(&t[p],chave);

}

void ImprimirHash(Lista t[]){

	for(int i = 0; i < TAM; i++){

		printf("(%d)--> ", i);
		ImprimirLista(&t[i]);
		printf("\n");
	}
}

void VetNoRepetions(int *vet){

	int i = 0;
	int control; // Variavel de controle
	srand(time(0));

	while(i < VET){

		vet[i] = rand() % 100;
		control = 0;

		for(int j = 0; j < i; j++){

			if(vet[j] == vet[i]){

				control = 1;
			}

		}

		if(control == 0){

				i++;
		}
	}

	//Inteiros nao repetidos.
	printf("\n\nVetor de inteiros => ");

	for(int j = 0; j < VET; j++){

		printf("%d ", vet[j]);

	}

	printf("\n");

}

void ContColisoes(Lista t[]){

	int soma = 0;

	for(int i = 0; i < TAM; i++){

		soma += t[i].col;
		
	}

	printf("\nQuantidade de colisões = %d\n\n", soma);
}


void ExecHashEF(){

	int vet[VET];
	Lista HashTable[TAM];

	VetNoRepetions(vet);
	printf("\n");

	CriarHS(HashTable);

	for(int i = 0; i < VET; i++){

		InsertHS(HashTable,vet[i]);

	}

	printf("\n");

	printf("-------------- TABELA --------------\n\n");

	ImprimirHash(HashTable);

	ContColisoes(HashTable);

}















