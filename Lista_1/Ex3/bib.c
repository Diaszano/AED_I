#include "bib.h"

void clear(void);
void pause();
int menu(void);	
void lerString(char palavra[]);
char *addNome(char *nomesEscritos);
char *rmNome(char *nomesEscritos);
void imprimir(char *nomes);

void clear(void){
	system("cls || clear");
}

void pause(){
	getchar();
}

int menu(void){
	clear();
	int resposta = 0;
		
	do 
		{
			clear();
			printf("-- MENU:\n");
			printf("\t 1. Adicionar nome\n");	
			printf("\t 2. Remover nome\n");
			printf("\t 3. Listar\n");
			printf("\t 4. Sair\n");
			printf("-- Digite sua escolha: ");
			scanf("%i", &resposta);
			
		}while (resposta <= 0 || resposta >= 5);
	pause();		
	return resposta;
}
	
void lerString(char palavra[]){
	int i = 0;
	char c;
	c = getchar();
	while ((c != '\n') && (i < Max)) {
		palavra[i++] = c;
		c = getchar();
	}
	palavra[i] = '\0';
	if (c != '\n') {
		c = getchar();
		while ((c != '\n') && (c != EOF)) {
			c = getchar();
		}
	}
}

char *addNome(char *nomesEscritos){
	int nomesEscritosSize = 0;
	int nomeEscritoSize = 0;
	char nomeEscrito[Max];

	printf("Nome que deseja adicionar; ");
	lerString(nomeEscrito);
	if(strlen(nomeEscrito)<1){
		return nomesEscritos;
	}
	strcat(nomeEscrito,",");
	
	nomeEscritoSize = strlen(nomeEscrito) + 1;
	nomesEscritosSize = strlen(nomesEscritos) + 1;
	
	if((nomesEscritos = (char*)realloc(nomesEscritos, (nomeEscritoSize + nomesEscritosSize) * sizeof(char))) == NULL){
		printf ("** Erro: Memoria Insuficiente **");
		exit(0);
	}
	strcat(nomesEscritos,nomeEscrito);
	pause();
	return nomesEscritos;
}

char *rmNome(char *nomesEscritos){
	char nomeExcluir[Max];
	int nomeExcluirSize;
	
	printf("Nome que deseja excluir; ");
	lerString(nomeExcluir);
	nomeExcluirSize = strlen(nomeExcluir);
	
	int i, j;
	int soma = 0, inicio, fim;

	for(i = 0, j = 0; nomesEscritos[i] != '\0'; i++, j++){
		if(nomesEscritos[i] == ','){
			i++;
			soma = 0;
			j = 0;
		}
		if((nomesEscritos[i] == nomeExcluir[j]) && (nomesEscritos[i] != ',')){
			if(soma == 0){
				inicio = i-1;
			}
			soma++;
			if(((nomesEscritos[i+1] == ',')||nomesEscritos[i+1] == '\0') && (soma == nomeExcluirSize)){
				break;
			}
		}else{
			soma--;
		}
	}
	
	if(soma != nomeExcluirSize){
		return nomesEscritos;
	}
	fim = inicio + nomeExcluirSize;
	char ac[strlen(nomesEscritos)-nomeExcluirSize];
	for(i = 0, j = 0; nomesEscritos[i] != '\0'; i++){
        if((i < inicio || i > fim)){
			ac[j] = nomesEscritos[i];
			j++;
		}
	}
	ac[j] = '\0';
    if(ac[0]==','){
        for(i=0,j=1;ac[j]!='\0';i++,j++){
            ac[i] = ac[j];
        }
        ac[i] = '\0';
    }
	int acSize = strlen(ac);
	if(acSize > 0){
		if((nomesEscritos = (char*)realloc(nomesEscritos, (acSize) * sizeof(char))) == NULL){
			printf ("** Erro: Memoria Insuficiente **");
			exit(0);
		}
        
		strcpy(nomesEscritos, ac);
	}else{
		for (int i = 0; i < strlen(nomesEscritos)+1; i++){
			nomesEscritos[i] = '\0';
		}
		
		free(nomesEscritos);
		if ((nomesEscritos = (char*)calloc(1,sizeof(char))) == NULL) {
			printf ("** Erro: Memoria Insuficiente **");
			exit(0);
		}
        nomesEscritos[0] = '\0';
	}
    pause();
    return nomesEscritos;
}

void imprimir(char *nomes){	
	printf("%s",nomes);
	pause();
}