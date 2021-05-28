#include "bib.h"

int main(int argc, char const *argv[]){
	char resposta;
	PILHA *pilha;
	pilha = RESET();
	for (;;){
		limparTela();
		resposta = menu();
		switch (resposta) {
			case '0':
				PUSH(pilha);
					break;
			case '1':
				POP(pilha);
					break;
			case '2':
				listar(pilha);
					break;
			case '3':
				pilha = CLEAR(pilha);
				printf("Pilha Limpa!!!");
				pause();
					break;
			case '4':
				pilha = CLEAR(pilha);
				free(pilha);
				pilha = NULL;
				return 0;
					break;
		}
	}
}