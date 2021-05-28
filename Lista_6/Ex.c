#include "bib.h"

int main(int argc, char const *argv[]){
	char resposta;
	FILA fila;
	fila = RESET();
	for (;;){
		limparTela();
		resposta = menu();
		switch (resposta) {
			case '0':
				PUSH(&fila);
					break;
			case '1':
				POP(&fila);
					break;
			case '2':
				listar(fila);
					break;
			case '3':
				CLEAR(&fila);
				printf("Fila Limpa!!!");
				pause();
					break;
			case '4':
				CLEAR(&fila);
				return 0;
					break;
		}
	}
}