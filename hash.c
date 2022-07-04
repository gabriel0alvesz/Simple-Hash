#include <stdio.h>
#include "hash.h"

int Hash(int chave){

	return chave % TAM;
}

void CriarLista(Lista *l){
    l->first = NULL;
    l->tam = 0;
}

void ListaInsert(Lista *l, int chave){
	
	BlockKey *novo = malloc(sizeof(BlockKey));

	novo->chave = chave;
    novo->prox = l->first;
    l->first = novo;
    l->tam++;

}

void ImprimirLista(Lista *l){

	BlockKey *aux = l->first;

	while(!(aux == NULL)){

		printf("%d ", aux->chave);
		aux = aux->prox;

	}

	printf("[%d]",l->tam);

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

	int num, i = 0;
	int control; // Variavel de controle
	srand(time(0));

	while(i < TAM){

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

	for(int j = 0; j < TAM; j++){

		printf("%d ", vet[j]);

	}

	printf("\n");

}















