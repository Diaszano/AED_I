#include "bib.h"

void lpbuffer(void){
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void pause(void){
	printf("\nClique no enter para continuar\n");
	getchar();
}

void clear(void){
	system("cls || clear");
}

void lerString(char palavra[]){
	int i = 0;
	char c;
	c = getchar();
	while ((c != '\n') && (i < MaxNome)) {
		palavra[i++] = c;
		c = getchar();
	}
	palavra[i] = '\0';
	if (c != '\n') {
		c = getchar();
		while ((c != '\n') && (c != EOF)) {
			c = getchar();
		}
	}
}

LISTA* cria(void){
    LISTA *start;

    if((start=(LISTA *)calloc(1,sizeof(LISTA))) == NULL){
        printf("Não foi passível alocar memoria\n");
        exit(1);
    }

    start->prox = NULL;
    return start;
}

char menu(void){
	clear();
	char resposta = '\0';
		
	do{
		clear();
		printf("-----[ Menu ]-----\n");
        printf("1 - Incluir nome\n");
        printf("2 - Sair        \n");
        printf("Digite: ");
		resposta = getchar();
			
	}while (resposta <= '0' || resposta >= '3');
	pause();		
	return resposta;
}

int vazia(LISTA *le){
	if(le->prox == NULL){
		return 1;
	} 
	else{
		return 0;
	}
}

void insere(LISTA *p,Pessoa x){
	LISTA *novo = (LISTA*)malloc(sizeof(LISTA));
	
	if(!novo){
		printf("Sem memória disponível!\n");
		exit(1);
	}
	novo->informacoes = x;
	if(vazia(p)){
		p->prox = novo;
	} else{
		LISTA *tmp;
		for (tmp = p->prox; tmp->prox != NULL; tmp = tmp->prox);
		tmp->prox = novo;
	}
}

void incluir(LISTA *p){
	Pessoa novo;
	printf("Digite o nome da pessoa: ");
	lerString(novo.nome);
	printf("Digite a idade da pessoa: ");
	scanf("%i",&novo.idade);
	lpbuffer();
	printf("Digite a altura da pessoa: ");
	scanf("%i",&novo.altura);
	lpbuffer();
	insere(p,novo);
}

void imprimir(LISTA *tmp){
	printf("Nome: ");
	for(int i = 0; tmp->informacoes.nome[i] != '\0'; i++){
		printf("%c",tmp->informacoes.nome[i]);
	}
	printf("\nIdade: %i",tmp->informacoes.idade);
	printf("\nAltura: %i",tmp->informacoes.altura);
	printf("\n\n");
}

void listar(LISTA *p){
	if(vazia(p)){
		printf("Lista está vazia!\n\n");
		pause();
		return;
	}
	LISTA *tmp;
	for(tmp = p->prox;tmp != NULL; tmp = tmp->prox){
		imprimir(tmp);
	}
	pause();
}

LISTA *libera(LISTA *le){
    if(!vazia(le)){
		LISTA *proxNo, *atual;
		atual = le->prox;
		while(atual != NULL)
        {
			proxNo = atual->prox;
			free(atual);
			atual = NULL;
			atual = proxNo;
		}
	}
	return le;
}

