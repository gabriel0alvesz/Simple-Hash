#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20
#define VET 43

typedef struct BlockKey{

	int chave;
	struct BlockKey *prox; 

}BlockKey;

typedef struct Lista{

	  BlockKey *first;
	  int tam;
	  int col;

}Lista;

int hash(int chave);
void CriarLista(Lista *l);
void ListaInsert(Lista *l, int chave);
void ImprimirLista(Lista *l);
void CriarHS(Lista t[]);
void InsertHS(Lista t[], int chave);
void ImprimirHash(Lista t[]);
void VetNoRepetions(int *vets);
void ExecHashEF();
void ContColisoes(Lista t[]);