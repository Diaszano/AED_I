#include "bib.h"

int main(int argc, char *argv[]){
    int tamanho = 0,posicao = 0;
    int *memoria = NULL;  

    printf("Digite o tamanho da memoria: ");
    scanf("%i",&tamanho);
    for (;tamanho%sizeof(int);){
        tamanho++;
    }
    tamanho = tamanho/sizeof(int);
    
    if((memoria=(int*)calloc(tamanho,sizeof(int)))==NULL){
        printf("Não foi possível alocar memoria\n");
        exit(1);
    }

    for (;;){
		clear();
		int resposta = menu();
		switch (resposta) {
			case 1:
				printf("Digite a posicao a qual tu queres inserir: ");
                scanf("%i",&posicao);
                if(posicao < tamanho){
                    memoria = insere(memoria,posicao);
                }else{
                    printf("Nao foi possível ir a essa localização");
                    pause();
                    clear();
                }
					break;
			case 2:
				printf("Digite a posicao a qual tu queres ver: ");
                scanf("%i",&posicao);
                if(posicao < tamanho){
                    verifica(memoria,posicao);
                }else{
                    printf("Nao foi possível ir a essa localização");
                    pause();
                    clear();
                }
				    break;
            case 3:
                free(memoria);
				memoria = NULL;
				clear();
				return 0;
					break;
		}
	}
}

