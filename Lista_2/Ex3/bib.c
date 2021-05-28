#include "bib.h"

void pause(){
	printf("\nClique no enter para continuar\n");
	getchar();
}

void clear(){
	system("cls || clear");
}

void lerString(char palavra[], int tamanho){
	int i = 0;
	char c;
	c = getchar();
	while ((c != '\n') && (i < tamanho)) {
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
        printf("Não foi possivel alocar memoria\n");
        exit(1);
    }

    start->prox = NULL;
    return start;
}

LISTA* iniciar(void *pbuffer){
    LISTA *n;
	n = cria();
    return n;
}

char menu(void){
	clear();
	char resposta = '\0';
		
	do{
		clear();
		printf("-----[ Menu ]-----\n");
        printf("1 - Incluir nome\n");
        printf("2 - Apagar nome \n");
        printf("3 - Buscar nome \n");
        printf("4 - Listar      \n");
        printf("5 - Sair        \n");
        printf("Digite: ");
		resposta = getchar();
			
	}while (resposta <= '0' || resposta >= '6');
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

void insere(void *pBuffer,Contato x)
{
	LISTA *novo = (LISTA*)malloc(sizeof(LISTA));
	LISTA *p;
	p = pBuffer;
	if(!novo)
    {
		printf("Sem memória disponível!\n");
		exit(1);
	}
	novo->Contatos = x;
	if(vazia(p))
    {
		p->prox = novo;
	} else
    {
		LISTA *tmp;

		for (tmp = p->prox; tmp->prox != NULL; tmp = tmp->prox);

		tmp->prox = novo;
	}
}

void incluir(void *pBuffer){
	Contato novo;
	
	printf("Digite o nome da pessoa: ");
	lerString(novo.nome,MaxNome);
	printf("Digite a idade da pessoa: ");
	lerString(novo.idade,MaxIdade);
	printf("Digite o numero da pessoa: ");
	lerString(novo.numero,MaxNumero);
	insere(pBuffer,novo);
}

void imprimir(LISTA *tmp){
	printf("Nome: ");
	for(int i = 0; tmp->Contatos.nome[i] != '\0'; i++){
		printf("%c",tmp->Contatos.nome[i]);
	}
	printf("\nIdade: ");
	for(int i = 0; tmp->Contatos.idade[i] != '\0'; i++){
		printf("%c",tmp->Contatos.idade[i]);
	}
	printf("\nNumero: ");
	for(int i = 0; tmp->Contatos.numero[i] != '\0'; i++){
		printf("%c",tmp->Contatos.numero[i]);
	}
	printf("\n\n");
}

void listar(void *pbuffer){
	LISTA *p;
	p = pbuffer;
	if(vazia(p))
    {
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
char buscarMenu(void){
	clear();
	char resposta = '\0';
		
	do{
		clear();
		printf("-----[ Menu ]-----\n");
        printf("1 - Buscar por nome\n");
        printf("2 - Burcar por idade\n");
        printf("3 - Buscar por numero\n");
        printf("4 - Buscar com todas informacoes\n");
		resposta = getchar();
			
	}while (resposta <= '0' || resposta >= '5');
	pause();		
	return resposta;
}

LISTA* busca(void *pBuffer,Contato x,char opc){
	LISTA *ini;
	ini = pBuffer;
	LISTA *p;
	p = ini->prox;

	switch (opc){
		case '1':
			while ((p != NULL) && (strcmp(p->Contatos.nome,x.nome) != 0)){
				p = p->prox;
			}
			if((p != NULL) && (strcmp(p->Contatos.nome,x.nome) != 0)){
				p = NULL;
			}
				break;
		case '2':
			while ((p != NULL) && (strcmp(p->Contatos.idade,x.idade) != 0)){
				p = p->prox;
			}
			if((p != NULL) && (strcmp(p->Contatos.idade,x.idade)) != 0){
				p = NULL;
			}
				break;
		case '3':
			while ((p != NULL) && (strcmp(p->Contatos.numero,x.numero)) != 0){
				p = p->prox;
			}
			if((p != NULL) && (strcmp(p->Contatos.numero,x.numero)) != 0){
				p = NULL;
			}
				break;
		case '4':
			while ((p != NULL) && ((strcmp(p->Contatos.idade,x.idade) != 0)&&(strcmp(p->Contatos.nome,x.nome) != 0)&&(strcmp(p->Contatos.numero,x.numero) != 0))){
				p = p->prox;
			}
			if((p != NULL) && ((strcmp(p->Contatos.idade,x.idade) != 0)&&(strcmp(p->Contatos.nome,x.nome) != 0)&&(strcmp(p->Contatos.numero,x.numero) != 0))){
				p = NULL;
			}
			break;
	
	}
		
	return p;
}

void buscar(void *pbuffer){
	char opc = '\0';
	LISTA *p;
	p = pbuffer;
	if(vazia(p)){
		printf("Lista está vazia!\n\n");
		pause();
		return;
	}
	opc = buscarMenu();
	Contato novo;

	switch (opc){
		case '1':
			printf("Digite o nome: ");
			lerString(novo.nome,MaxNome);
			clear();
			imprimir(busca(pbuffer,novo,opc));
			pause();
				break;
		case '2':
			printf("Digite a idade: ");
			lerString(novo.idade,MaxIdade);
			clear();
			imprimir(busca(pbuffer,novo, opc));
			pause();
				break;
		case '3':
			printf("Digite o numero: ");
			lerString(novo.numero,MaxNumero);
			clear();
			imprimir(busca(pbuffer,novo,opc));
			pause();
				break;
		case '4':
			printf("Digite o nome: ");
			lerString(novo.nome,MaxNome);
			printf("Digite a idade: ");
			lerString(novo.idade,MaxIdade);
			printf("Digite o numero: ");
			lerString(novo.numero,MaxNumero);
			clear();
			imprimir(busca(pbuffer,novo,opc));
			pause();
				break;
	}
}

void remover(void *pbuffer, Contato x,char opc){
	LISTA *ini, *p, *q;
	ini = pbuffer;
	if(vazia(ini)){
		printf("Lista está vazia!\n\n");
		pause();
		return;
	}
	p = ini;
	q = ini->prox;
	switch (opc){
		case '1':
			while ((q != NULL) && (strcmp(q->Contatos.nome,x.nome) != 0)){
				p = q;
				q = q->prox;
			}
				break;
		case '2':
			while ((q != NULL) && (strcmp(q->Contatos.idade,x.idade) != 0)){
				p = q;
				q = q->prox;
			}
				break;
		case '3':
			while ((q != NULL) && (strcmp(q->Contatos.numero,x.numero)) != 0){
				p = q;
				q = q->prox;
			}
				break;
		case '4':
			while ((q != NULL) && ((strcmp(q->Contatos.idade,x.idade) != 0)&&(strcmp(q->Contatos.nome,x.nome) != 0)&&(strcmp(q->Contatos.numero,x.numero) != 0))){
				p = q;
				q = q->prox;
			}
			break;
	
	}
	if (q != NULL) {
		p->prox = q->prox;
		free(q);
		q = NULL;
	}
}

char apagarMenu(void){
	clear();
	char resposta = '\0';
		
	do{
		clear();
		printf("-----[ Menu ]-----\n");
        printf("1 - Apagar por nome\n");
        printf("2 - Apagar por idade\n");
        printf("3 - Apagar por numero\n");
        printf("4 - Apagar com todas informacoes\n");
		resposta = getchar();
			
	}while (resposta <= '0' || resposta >= '5');
	pause();		
	return resposta;
}

void apagar(void *pbuffer){
	Contato novo;
	char opc;
	LISTA *p;
	p = pbuffer;
	if(vazia(p)){
		printf("Lista está vazia!\n\n");
		pause();
		return;
	}
	opc = apagarMenu();
	
	switch (opc){
		case '1':
			printf("Digite o nome: ");
			lerString(novo.nome,MaxNome);
			remover(pbuffer,novo,opc);
				break;
		case '2':
			printf("Digite a idade: ");
			lerString(novo.idade,MaxIdade);
			remover(pbuffer,novo, opc);
				break;
		case '3':
			printf("Digite o numero: ");
			lerString(novo.numero,MaxNumero);
			remover(pbuffer,novo,opc);
				break;
		case '4':
			printf("Digite o nome: ");
			lerString(novo.nome,MaxNome);
			printf("Digite a idade: ");
			lerString(novo.idade,MaxIdade);
			printf("Digite o numero: ");
			lerString(novo.numero,MaxNumero);
			remover(pbuffer,novo,opc);
				break;
	}
}

void libera(void *pbuffer){
	LISTA *le;
    le = pbuffer;
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
}

