#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lpbuffer(void);
void pause(void);
void clear(void);
char menu(void);
int **criarMatriz(int m, int n);
void lerMatriz(int **mat, int m, int n);
int somarMatriz(int **mat, int m, int n);
void imprimirMatriz(int **mat, int m, int n);
int *colunaMatriz(int **mat, int m, int n, int ncoluna);
void imprimirVetor(int *vet, int n);
void liberarMatriz(int **mat, int ncolunas);