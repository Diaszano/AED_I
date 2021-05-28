#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 15

void clear(void);
void pause();
int menu(void);	
void lerString(char palavra[]);
char *addNome(char *nomesEscritos);
char *rmNome(char *nomesEscritos);
void imprimir(char *nomes);