#include "bib.h"

int main(int argc, char const *argv[]){
	void *pBuffer = NULL;
	char resposta;

	pBuffer = iniciar(pBuffer);

	for (;;){
		clear();
		resposta = menu();
		switch (resposta) {
			case '1':
				clear();
				incluir(pBuffer);
				pause();
					break;
			case '2':
				clear();
				apagar(pBuffer);
					break;
			case '3':
				clear();
				buscar(pBuffer);
					break;
			case '4':
				clear();
				listar(pBuffer);
					break;
			case '5':
				libera(pBuffer);
				free(pBuffer);
				pBuffer = NULL;
				clear();
				return 0;
		}
	}
}