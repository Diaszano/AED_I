#include "bib.h"

int menu(void){
	clear();
	int resposta = -1;
		
	do{
		clear();
		printf("-----[ Menu ]-----\n");
        printf("1 - Incluir valor\n");
        printf("2 - Verificar valor\n");
        printf("3 - Sair        \n");
        printf("Digite: ");
		scanf("%i",&resposta);	
	}while (resposta <= 0 || resposta >= 4);		
	return resposta;
}


int *insere(int *m,int p){
    int valor = 0;
    printf("Digite o valor que tu queres inserir: ");
    scanf("%i",&valor);

    m[p] = valor;
    return m;
}

void verifica(int *m,int p){
    printf("Informação da localização: %i\n",m[p]);
    pause();
}

void pause(void){
	lpbuffer();
    getchar();
}

void clear(void){
	system("cls || clear");
}

void lpbuffer(void){
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}