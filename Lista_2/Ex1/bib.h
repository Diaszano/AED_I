#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxNome 30


typedef struct {
	char nome[MaxNome];
	int idade;
	int altura;
}Pessoa;

typedef struct lista{
	Pessoa informacoes;
	struct lista *prox;
}LISTA;

void lpbuffer(void);
void pause(void);
void clear(void);
void lerString(char palavra[]);
LISTA *cria(void);
char menu(void);
int vazia(LISTA *le);
void insere(LISTA *p,Pessoa x);
void incluir(LISTA *p);
void imprimir(LISTA *tmp);
void listar(LISTA *p);
LISTA *libera(LISTA *le);