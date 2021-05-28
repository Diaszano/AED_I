#include "bib.h"

int main(int argc, char const *argv[]){
    int **matriz;
    int m,n,coluna=0;
    matriz = NULL;
    printf("Insira o numero de colunas: ");
    scanf("%i", &m);
    printf("Insira o numero de linhas: ");
    scanf("%i", &n);
    matriz = criarMatriz(m, n);
    int finish = 0;
    for(;;){
        clear();
		char resposta = menu();
		switch (resposta){
            case '1':
                lerMatriz(matriz,m,n);
                    break;
            case '2':
                imprimirMatriz(matriz,m,n);
                    break;
            case '3':
                printf("Valor Da Soma: %i", somarMatriz(matriz,m,n));
				pause();
                    break;
            case '4':
                
                printf("Insira o numero da coluna a ser impresso: ");
                scanf("%i", &coluna);
                imprimirVetor(colunaMatriz(matriz,m,n,coluna),n);
				pause();
                    break;
            case '5':
                liberarMatriz(matriz,m);
                printf("Insira o numero de colunas: ");
                scanf("%i", &m);
                printf("Insira o numero de linhas: ");
                scanf("%i", &n);
                matriz = criarMatriz(m,n);
                    break;
            case '6':
                liberarMatriz(matriz,m);
                return 0;
        }
    }
}