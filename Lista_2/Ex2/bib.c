#include "bib.h"

void lpbuffer(void){
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void pause(void){
	printf("\n\n");
	printf("\nClique no enter para continuar\n");
	getchar();
}

void clear(void){
	system("cls || clear");
}

char menu(void){
	clear();
	char resposta = '\0';
		
	do{
		clear();
		printf("-----[ Menu ]-----\n");
        printf("1 - Realizar a leitura dos elementos da matriz\n");
        printf("2 - Realizar a impressao dos elementos da matriz\n");
		printf("3 - Realizar a soma dos elementos da matriz\n");
		printf("4 - Realizar a leitura dos elementos de uma coluna x\n");
		printf("5 - Realizar a alteracao do tamanho da matriz\n");
		printf("6 - Sair do programa\n");

        printf("Digite: ");
		resposta = getchar();
			
	}while (resposta <= '0' || resposta >= '7');
	pause();		
	return resposta;
}

int **criarMatriz(int m, int n){
    int **matriz = NULL;
    if((matriz = (int**)calloc(n,sizeof(int*))) == NULL){
        printf("Não foi possivel alocar memoria\n");
        exit(1);
    }
    for (int i = 0; i < n; i++){
        if((matriz[i] = (int*)calloc(m,sizeof(int))) == NULL){
            printf("Não foi possivel alocar memoria\n");
            exit(1);
        }
        for (int j = 0; j < m; j++){
            matriz[i][j] = 0;
        }
    }
    return matriz;
}

void lerMatriz(int **mat, int m, int n){
    for (int i = 0; i < n; i++){
        printf("Linha %i\n", i + 1);
        for (int j = 0; j < m; j++){
            scanf("%i", &mat[i][j]);
        }
    }
	pause();
}

int somarMatriz(int **mat, int m, int n){
    int valor = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            valor += mat[i][j];
        }
    }
    return valor;
}

void imprimirMatriz(int **mat, int m, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%i ", mat[i][j]);
        }
        printf("\n");
    }
	pause();
}

int *colunaMatriz(int **mat, int m, int n, int ncoluna){
    if (ncoluna <= 0){
        printf("Coluna Invalida");
        return NULL;
    }
    int *vetor = NULL;

    if((vetor=(int*)calloc(n,sizeof(int*))) == NULL){
        printf("Não foi possivel alocar memoria\n");
        exit(1);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (j == ncoluna - 1){
                vetor[i] = mat[i][j];
            }
        }
    }
    return vetor;
}

void imprimirVetor(int *vet, int n){
    if (vet == NULL){
        return;
    }
    for (int i = 0; i < n; i++){
        printf("%i", vet[i]);
    }
	pause();
    free(vet);
	vet = NULL;
}

void liberarMatriz(int **mat, int ncolunas){
    for (int i = 0; i < ncolunas;free(mat[i]),mat[i] = NULL, i++);        ;
    free(mat);
    mat = NULL;
}