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
	char c;
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

void insere(PILHA *p, Pessoa x){
	PILHA *novo = (PILHA *)calloc(1,sizeof(PILHA));

	if (!novo){
		printf("Sem memória disponível!\n");
		exit(1);
	}
	novo->informacoes = x;
	if (EMPTY(p)){
		p->prox = novo;
	}
	else{
		novo->prox = p->prox;
		p->prox = novo;
	}
}

void PUSH(PILHA *p){
	limparTela();
	Pessoa novo;
	printf("Digite o nome da pessoa: ");
	lerString(novo.nome);
	printf("Digite a idade da pessoa: ");
	scanf("%i",&novo.idade);
	lpbuffer();
	insere(p, novo);
	pause();
}

void imprimir(PILHA *tmp){
	printf("Nome: %s",tmp->informacoes.nome);
	printf("\nIdade: %i", tmp->informacoes.idade);
	printf("\n\n");
}

void listar(PILHA *p){
	limparTela();
	if (EMPTY(p)){
		printf("PILHA está vazia!\n\n");
		pause();
		return;
	}
	PILHA *tmp;
	for (tmp = p->prox; tmp != NULL; tmp = tmp->prox){
		imprimir(tmp);
	}
	pause();
}

void POP(PILHA *p){
	limparTela();
	if(!(EMPTY(p))){
		PILHA *tmp = NULL;
		tmp = p->prox;
		p->prox = p->prox->prox;
		free(tmp);
		tmp = NULL;
	}
}

char menu(void){
	limparTela();
	char resposta = '\0';

	do{
		limparTela();
		printf("-----[ Menu ]-----\n");
		printf("0 - Insere pessoa\n");
		printf("1 - Deleta pessoa do topo\n");
		printf("2 - Lista pilha\n");
		printf("3 - Limpa a pilha\n");
		printf("4 - Sair do programa\n");
		printf("Digite: ");
		resposta = getchar();

	} while (resposta < '0' || resposta > '4');
	pause();
	return resposta;
}

int EMPTY(PILHA *le){
	if (le->prox == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

PILHA *RESET(void){
	PILHA *start;

	if ((start = (PILHA *)calloc(1, sizeof(PILHA))) == NULL){
		printf("Não foi possível alocar memoria\n");
		exit(1);
	}

	start->prox = NULL;
	return start;
}

PILHA *CLEAR(PILHA *le){
	limparTela();
	if (!EMPTY(le)){
		PILHA *proxNo, *atual;
		atual = le->prox;
		while (atual != NULL){
			proxNo = atual->prox;
			free(atual);
			atual = NULL;
			atual = proxNo;
		}
		le->prox = atual;
	}
	return le;
}