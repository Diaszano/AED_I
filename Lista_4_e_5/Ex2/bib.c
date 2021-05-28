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

void insere(LISTA *p, Pessoa x, int local,int size){
	LISTA *novo = (LISTA *)calloc(1,sizeof(LISTA));

	if (!novo){
		printf("Sem memória disponível!\n");
		exit(1);
	}
	novo->informacoes = x;
	if (EMPTY(p) || (local == 0)){
		novo->prox = p->prox;
		p->prox = novo;
	}else{
		LISTA *tmp = p->prox;
		if(local < size){
			for(int i=1; i != local;i++,tmp = tmp->prox);
			novo->prox = tmp->prox;
			tmp->prox = novo;
		}else{
			for (tmp = p->prox; tmp->prox != NULL; tmp = tmp->prox);
			tmp->prox = novo;
			novo->prox = NULL;
		}
		
	}
}

void PUSH(LISTA *p,int *size){
	limparTela();
	Pessoa novo;
	printf("Digite o nome da pessoa: ");
	lerString(novo.nome);
	printf("Digite a idade da pessoa: ");
	scanf("%i",&novo.idade);
	int local = 0;
	do{
		local = posicao();
	}while((local > *size)||(local < 0));
	insere(p, novo,local,*size);
	*size = *size + 1;
	pause();
}

void imprimir(LISTA *tmp){
	printf("Nome: %s",tmp->informacoes.nome);
	printf("\nIdade: %i", tmp->informacoes.idade);
	printf("\n\n");
}

void listar(LISTA *p){
	limparTela();
	if (EMPTY(p)){
		printf("Lista está vazia!\n\n");
		pause();
		return;
	}
	LISTA *tmp = NULL;
	int i = 0;
	for (tmp = p->prox; tmp != NULL; tmp = tmp->prox){
		printf("Índice: %i\n",i);
		i++;
		imprimir(tmp);
	}
	pause();
}

void POP(LISTA *p,int opc,int *size){
	limparTela();
	LISTA *ini = NULL,*ant = NULL;
	ant = p;
	ini = p->prox;
	if (EMPTY(p)){
		printf("Lista está vazia!\n\n");
		pause();
		return;
	}
	if(opc){
		char nome[MaxNome];
		printf("Digite o nome da pessoa: ");
		lerString(nome);
		while ((ini != NULL) && (strcmp(ini->informacoes.nome,nome) != 0)){
			ant = ini;
			ini = ini->prox;
		}
	}else{
		int pozeDoRodo = 0;
		printf("Digite a posição da pessoa: ");
		scanf("%i",&pozeDoRodo);
		
		if(pozeDoRodo > *size-1 || pozeDoRodo < 0){
			printf("Índice inválido!\n\n");
			pause();
			return;
		}
		int i = 0;
		while ((ini != NULL) && (pozeDoRodo != i)){
			ant = ini;
			ini = ini->prox;
			i++;
		}
		
	}
	if (ini != NULL) {
		ant->prox = ini->prox;
		free(ini);
		ini = NULL;
		*size = *size - 1;
	}
}

char menu(void){
	limparTela();
	char resposta = '\0';

	do{
		limparTela();
		printf("-----[ Menu ]-----\n");
		printf("0 - Insere pessoa\n");
		printf("1 - Deleta pessoa (informando posição)\n");
		printf("2 - Deleta pessoa por nome\n");
		printf("3 - Imprime toda a lista\n");
		printf("4 - Limpa a lista\n");
		printf("5 - Sair do programa\n");
		printf("Digite: ");
		resposta = getchar();

	} while (resposta < '0' || resposta > '5');
	pause();
	return resposta;
}

int EMPTY(LISTA *le){
	if (le->prox == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

int posicao(){
	int posicao = 0;
	printf("Digite a posicao: ");
	scanf("%i",&posicao);

	return posicao;
}

LISTA *RESET(void){
	LISTA *start = NULL;

	if ((start = (LISTA *)calloc(1, sizeof(LISTA))) == NULL){
		printf("Não foi possível alocar memoria\n");
		exit(1);
	}

	start->prox = NULL;
	return start;
}

LISTA *CLEAR(LISTA *le){
	limparTela();
	if (!EMPTY(le)){
		LISTA *proxNo = NULL, *atual = NULL;
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