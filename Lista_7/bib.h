#include <stdio.h>
#include <stdlib.h>
#define MaxNome 30

typedef struct valor{
	int quantidade;
}LARANJA;

typedef struct nodo{
	LARANJA laranjas;
	struct nodo *direita;
	struct nodo *esquerda;	
}ARVORE;

void lpbuffer(void);
void pause(void);
void limparTela(void);
void lerString(char palavra[]);
ARVORE *RESET(void);
int EMPTY(ARVORE *galho);
void list(ARVORE *laranjeira);
void imprimir(ARVORE *folha);
void PUSH(ARVORE **laranjeira, int quantidade);
int search(ARVORE *laranjeira, int quantidade);
ARVORE *CLEAR(ARVORE *laranjeira);
char menu(void);
ARVORE *POP(ARVORE *laranjeira, int valor);
ARVORE *minimoDireita(ARVORE *folha);