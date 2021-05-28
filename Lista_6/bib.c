#include "bib.h"

void lpbuffer(void){
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void pause(void){
	printf("\nClique no enter para continuar\n");
	getchar();
}

void limparTela(void){
	system("cls || clear");
}

void lerString(char palavra[]){
	int i = 0;
	char c = '\0';
	c = getchar();
	while ((c != '\n') && (i < MaxNome)){
		palavra[i++] = c;
		c = getchar();
	}
	palavra[i] = '\0';
	if (c != '\n'){
		c = getchar();
		while ((c != '\n') && (c != EOF)){
			c = getchar();
		}
	}
}

void insere(Pessoa x,FILA *index){
	NODO *novo = (NODO*)calloc(1,sizeof(NODO));
	if (!novo){
		printf("Sem memória disponível!\n");
		exit(1);
	}
	novo->informacoes = x;
	if (index->inicio == NULL){
		novo->prox = index->inicio;
		index->inicio = novo;
		index->fim = novo;
	}else{
		NODO *tmp = index->inicio;
		for (; tmp->prox != NULL; tmp = tmp->prox);
		tmp->prox = novo;
		novo->prox = NULL;
		index->fim = novo;
	}
}

void PUSH(FILA *index){
	limparTela();
	Pessoa novo;
	
	printf("Digite o nome da pessoa: ");
	lerString(novo.nome);
	
	printf("Digite a idade da pessoa: ");
	scanf("%i",&novo.idade);
	
	insere(novo,index);
	pause();
}

void imprimir(NODO *tmp){
	printf("Nome: %s",tmp->informacoes.nome);
	printf("\nIdade: %i", tmp->informacoes.idade);
	printf("\n\n");
}

void listar(FILA index){
	limparTela();
	if (index.inicio == NULL){
		printf("Lista está vazia!\n\n");
		pause();
		return;
	}
	NODO *tmp = index.inicio;
	for (;tmp != NULL; tmp = tmp->prox){
		imprimir(tmp);
	}
	pause();
}

void POP(FILA *index){
	limparTela();
	if(index->inicio == NULL){
		printf("Lista está vazia!\n\n");
		pause();
		return;
	}else if(index->inicio == index->fim){
		free(index->inicio);
		*index = RESET();
		return;
	}
	NODO *tmp = index->inicio->prox;
	free(index->inicio);
	index->inicio = NULL;
	index->inicio = tmp;
}

char menu(void){
	limparTela();
	char resposta = '\0';

	do{
		limparTela();
		printf("-----[ Menu ]-----\n");
		printf("0 - Insere pessoa\n");
		printf("1 - Deleta pessoa\n");
		printf("2 - Imprime fila\n");
		printf("3 - Limpa a lista\n");
		printf("4 - Sair do programa\n");
		printf("Digite: ");
		resposta = getchar();
	} while (resposta < '0' || resposta > '4');
	pause();
	return resposta;
}

int EMPTY(NODO *index){
	if (index == NULL){
		return 1;
	}else{
		return 0;
	}
}

FILA RESET(void){
	FILA i;
	i.fim = NULL;
	i.inicio = NULL;
	return i;
}

void CLEAR(FILA *index){
	limparTela();
	if (index->inicio != NULL){
		NODO *tmp = index->inicio;
		NODO *ant = NULL;
		for (;tmp != NULL;ant = tmp,tmp = tmp->prox){
			free(ant);
			ant = NULL;
		}
		free(ant);
	}
	*index = RESET();
}