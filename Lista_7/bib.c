#include "bib.h"
//Iniciar ED (RESET)
//Inserir elemento (PUSH)
//Remover elemento (POP)
//Testa se ED está vazia (EMPTY)
//Apaga todos os elementos (CLEAR)

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

ARVORE *RESET(void){
	ARVORE *raiz = NULL;
	return raiz;
}

int EMPTY(ARVORE *galho){
	if(galho == NULL){
		return 1;
		printf("O galho nao tem folha skjhskjskjskjkjsj");
	}else{
		return 0;
		printf("O galho tem folha e se pah pode ter umas laranjas skjhskjskjskjkjsj");
	}
	//obs eu sei q nn vai printar, ok!!!!
}

void list(ARVORE *laranjeira){
	if(!EMPTY(laranjeira)){
		printf("<");
		imprimir(laranjeira);
		list(laranjeira->esquerda);
		list(laranjeira->direita);
		printf(">");
	}
}

void imprimir(ARVORE *folha){
	printf("%i",folha->laranjas.quantidade);
}

void PUSH(ARVORE **laranjeira, int quantidade){
	if(*laranjeira == NULL){
		if((*laranjeira = (ARVORE*)calloc(1,sizeof(ARVORE))) == NULL){
			printf("Não foi passível alocar memoria\n");
			exit(1);
		}
		(*laranjeira)->direita = NULL;
		(*laranjeira)->esquerda = NULL;
		(*laranjeira)->laranjas.quantidade = quantidade;
	}else{
		if(quantidade < (*laranjeira)->laranjas.quantidade){
			PUSH(&(*laranjeira)->esquerda,quantidade);
		}else if(quantidade > (*laranjeira)->laranjas.quantidade){
			PUSH(&(*laranjeira)->direita,quantidade);
		}else{
			printf("Valor ja existente!!!!!");
			pause();
			return;
		}
	}
}

int search(ARVORE *laranjeira, int quantidade){
	if(EMPTY(laranjeira)){
		return 0;
	}
	return laranjeira->laranjas.quantidade == quantidade || search(laranjeira->direita,quantidade) || search(laranjeira->esquerda,quantidade);
}

ARVORE *CLEAR(ARVORE *laranjeira){
	ARVORE *direita = NULL, *esquerda = NULL;
	if(EMPTY(laranjeira)){
		return NULL;
	}
	direita = laranjeira->direita;
	esquerda = laranjeira->esquerda;
	free(laranjeira);
	laranjeira = NULL;
	laranjeira = CLEAR(direita);
	laranjeira = CLEAR(esquerda);
	
	return laranjeira;
}

char menu(void){
	limparTela();
	char resposta = '\0';

	do{
		limparTela();
		printf("-----[ Menu ]-----\n");
		printf("0 - Insere valor\n");
		printf("1 - Deleta valor\n");
		printf("2 - Imprime árvore\n");
		printf("3 - Limpa a árvore\n");
		printf("4 - Verifica valor na árvore\n");
		printf("5 - Sair do programa\n");
		printf("Digite: ");
		resposta = getchar();
	} while (resposta < '0' || resposta > '5');
	pause();
	return resposta;
}

ARVORE *POP(ARVORE *laranjeira, int valor){
	if(!EMPTY(laranjeira)){
		if(valor > laranjeira->laranjas.quantidade ){
			laranjeira->direita = POP(laranjeira->direita,valor);
		}else if(valor < laranjeira->laranjas.quantidade){
			laranjeira->esquerda = POP(laranjeira->esquerda,valor);
		}else{
			if((EMPTY(laranjeira->esquerda))&&(EMPTY(laranjeira->direita))){
				free(laranjeira);
				laranjeira = NULL;
				return NULL;
			}else if((EMPTY(laranjeira->esquerda))&&(!EMPTY(laranjeira->direita))){
				ARVORE *tmp = laranjeira->esquerda;
				free(laranjeira);
				laranjeira = NULL;
				return tmp;
			}else if((!EMPTY(laranjeira->esquerda))&&(EMPTY(laranjeira->direita))){
				ARVORE *tmp = laranjeira->direita;
				free(laranjeira);
				laranjeira = NULL;
				return tmp;
			}else{
				ARVORE *tmp = minimoDireita(laranjeira->direita);
				laranjeira = POP(laranjeira,tmp->laranjas.quantidade);
				laranjeira->laranjas = tmp->laranjas;
			}
		}
		return laranjeira;
	}
	return NULL;
}

ARVORE *minimoDireita(ARVORE *folha){
	ARVORE *tmp = folha;
	while (!EMPTY(tmp->esquerda)){
		tmp = tmp->esquerda;
	}
	return tmp;
}