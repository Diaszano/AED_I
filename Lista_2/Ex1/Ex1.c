#include "bib.h"

int main(int argc, char const *argv[]){
	LISTA *pessoas;
	pessoas = cria();
	char resposta;
	for (;;){
		clear();
		resposta = menu();
		switch (resposta) {
			case '1':
				clear();
				incluir(pessoas);
				pause();
					break;
			case '2':
				clear();
				listar(pessoas);
				libera(pessoas);
				free(pessoas);
				pessoas = NULL;
				clear();
				return 0;
					break;
		}
	}
}