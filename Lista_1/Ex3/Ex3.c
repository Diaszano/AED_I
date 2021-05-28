//Criador: Lucas Dias dos Santos
//Curso: Eng de Comp
//Matricula: 19101571

#include "bib.h"

int main(int argc, char *argv[]){
	
	int resposta = 0;
	char *nomes;
	if ((nomes = (char*)calloc(1,sizeof(char))) == NULL){
		printf ("** Erro: Memoria Insuficiente **");
		exit(0);
	}
	nomes[0] = '\0';
	for (;;){
		clear();
		resposta = menu();
		switch (resposta) {
			case 1:
				clear();
				nomes = addNome(nomes);
					break;
			case 2:
				clear();
				nomes = rmNome(nomes);
					break;
			case 3:
				clear();
				imprimir(nomes);
					break;
			case 4:
				free(nomes);
				nomes = NULL;
				exit(0);
					break;
					}
	}
	return 0;
}