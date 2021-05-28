#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxNome 30

typedef struct {
	char nome[MaxNome];
	int idade;
}Pessoa;

typedef struct nodo{
	Pessoa informacoes;
	struct nodo *prox;
}NODO;

typedef struct fila{
	NODO *inicio;
	NODO *fim;
}FILA;


void	lpbuffer(void);
void 	pause(void);
void 	limparTela(void);
void 	lerString(char palavra[]);
void 	insere(Pessoa x,FILA *index);
void 	PUSH(FILA *index);
void 	imprimir(NODO *tmp);
void 	listar(FILA index);
void	POP(FILA *index);
char	menu(void);
int 	EMPTY(NODO *index);
FILA 	RESET(void);
void 	CLEAR(FILA *index);