#include "bib.h"

int main(int argc, char const *argv[]){
	char resposta;
	int i = 0;
	LISTA *lista = NULL;
	lista = RESET();
	for (;;){
		limparTela();
		resposta = menu();
		switch (resposta) {
			case '0':
				PUSH(lista,&i);
					break;
			case '1':
				POP(lista,0,&i);
					break;
			case '2':
				POP(lista,1,&i);
					break;
			case '3':
				listar(lista);
					break;
			case '4':
				lista = CLEAR(lista);
				i = 0;
				printf("Pilha Limpa!!!");
				pause();
					break;
			case '5':
				lista = CLEAR(lista);
				free(lista);
				lista = NULL;
				return 0;
					break;
		}
	}
}