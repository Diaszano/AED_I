#include "bib.h"

int main(int argc, char const *argv[]){
	char resposta;
	ARVORE *arvore = RESET();
	int i = 0;
	for (;;){
		limparTela();
		resposta = menu();
		switch (resposta) {
			case '0':
				limparTela();
				printf("Digite um valor: ");
				scanf("%i",&i);
				PUSH(&arvore,i);
				pause();
					break;
			case '1':
				limparTela();
				printf("Digite o valor a ser excluído: ");
				scanf("%i",&i);
				if(search(arvore,i)){
					arvore = POP(arvore,i);
				}else{
					printf("Valor invalido!!!!");
					lpbuffer();
					pause();
				}
				
					break;
			case '2':
				limparTela();
				list(arvore);
				pause();
					break;
			case '3':
				limparTela();
				arvore = CLEAR(arvore);
				printf("Arvore Limpa!!!");
				pause();
					break;
			case '4':
				limparTela();
				printf("Digite um valor: ");
				scanf("%i",&i);
				if(search(arvore,i)){
					printf("\nO valor está na árvore\n");
				}else{
					printf("\nO valor não está na árvore\n");
				}
				lpbuffer();
				pause();
					break;
			case '5':
				limparTela();
				arvore = CLEAR(arvore);
				return 0;
					break;
		}
	}
}