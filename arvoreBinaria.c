#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct NO{
	int dado;
	struct NO *esq;
	struct NO *dir;
	struct NO *pai;
} NO;

typedef struct ARVORE{
	NO *raiz;
}ARVORE;

ARVORE a;

void iniciaArvore(ARVORE arv);
void iniciaNo(NO* n, int val);
void insereNoArvoreOrdenada(int valor);
void preOrdem(NO* raiz);

void inicializaArvore(ARVORE arv){
	arv.raiz = NULL;
}

void inicializaNo(NO* n, int val){
	if(!n){
		printf("Falha de alocação.\n");
		return;
	}
	n->pai = NULL;
	n->esq = NULL;
	n->dir = NULL;
	n->dado = val;
}

void insereNoArvoreOrdenada(int valor){
	NO* corrente = a.raiz;
	NO* pai;

	NO* novoNo = (NO*) malloc(sizeof(NO));
	inicializaNo(novoNo, valor);
	printf("\nInserindo no %d. \n", novoNo->dado);

	if(corrente == NULL){
		a.raiz = novoNo;
		printf("\nNo inserido na raiz. \n");
		return;
	}

	while(corrente){
		pai = corrente;
		if(novoNo->dado < corrente->dado){
			corrente = corrente->esq;
			if(!corrente){
				printf("\nNo inserido a esquerda do no %d. \n", pai->dado);
				pai->esq = novoNo;
				return;
			}
		}
		else{
			corrente = corrente->dir;
			if(!corrente){
				printf("\nNo inserido a direita do no %d. \n", pai->dado);
				pai->dir = novoNo;
				return;
			}
		}
	}
}

void preOrdem(NO* raiz){
	if(raiz){
		printf("%d \t", raiz->dado);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);

	}
}

int main(){

	setlocale(LC_ALL, "Portuguese");
	printf("***Atividade Mapa***\n");
	printf("Nome: Poliana Rodrigues da Silva\n");
	printf("RA: 21011038-5\n\n");

	inicializaArvore(a);

	insereNoArvoreOrdenada(2);
	insereNoArvoreOrdenada(1);
	insereNoArvoreOrdenada(0);
	insereNoArvoreOrdenada(1);
	insereNoArvoreOrdenada(1);
	insereNoArvoreOrdenada(0);
	insereNoArvoreOrdenada(3);
	insereNoArvoreOrdenada(8);
  	insereNoArvoreOrdenada(5);


	printf("\nBusca pre ordem: \n");
	preOrdem(a.raiz);
}
