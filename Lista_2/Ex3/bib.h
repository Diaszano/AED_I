#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxNome 10
#define MaxNumero 12
#define MaxIdade 3

typedef struct {
	char nome[MaxNome];
	char numero[MaxNumero];
	char idade[MaxIdade];		
}Contato;

typedef struct lista{
	Contato Contatos;
	struct lista *prox;
}LISTA;

void pause();
void clear();
void lerString();
LISTA* cria(void);
LISTA* iniciar(void *pbuffer);
char menu(void);
int vazia(LISTA *le);
void insere(void *pBuffer,Contato x);
void incluir(void *pBuffer);
void imprimir(LISTA *tmp);
void listar(void *pbuffer);
char buscarMenu(void);
LISTA* busca(void *pBuffer,Contato x,char opc);
void buscar(void *pbuffer);
void remover(void *pbuffer, Contato x,char opc);
char apagarMenu(void);
void apagar(void *pbuffer);
void libera(void *pbuffer);