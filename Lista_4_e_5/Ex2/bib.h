#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxNome 30

typedef struct {
	char nome[MaxNome];
	int idade;
}Pessoa;

typedef struct lista{
	Pessoa informacoes;
	struct lista *prox;
}LISTA;

void	lpbuffer(void);
void 	pause(void);
void 	limparTela(void);
void 	lerString(char palavra[]);
void 	insere(LISTA *p, Pessoa x, int local,int size);
void 	PUSH(LISTA *p, int *size);
void 	imprimir(LISTA *tmp);
void 	listar(LISTA *p);
void 	POP(LISTA *p,int opc, int *size);
char 	menu(void);
int 	EMPTY(LISTA *le);
int		posicao(void);
LISTA 	*RESET(void);
LISTA 	*CLEAR(LISTA *le);