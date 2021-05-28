#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxNome 30

typedef struct {
	char nome[MaxNome];
	int idade;
}Pessoa;

typedef struct pilha{
	Pessoa informacoes;
	struct pilha *prox;
}PILHA;

void	lpbuffer(void);
void 	pause(void);
void 	limparTela(void);
void 	lerString(char palavra[]);
void 	insere(PILHA *p, Pessoa x);
void 	PUSH(PILHA *p);
void 	imprimir(PILHA *tmp);
void 	listar(PILHA *p);
void 	POP(PILHA *p);
char 	menu(void);
int 	EMPTY(PILHA *le);
PILHA 	*RESET(void);
PILHA 	*CLEAR(PILHA *le);