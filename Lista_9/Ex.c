#include "bib.h"

int main(int argc, char const *argv[]){
	srand(time(NULL));

	int n = Max;
	printf("Digite o valor de n; ");
	scanf("%i",&n);
	
	int ss[n],is[n];
	for(int i = 0; i < n; i++){
		ss[i] = rand()%100;
		printf("Vetor[%i] = %i\n",i,ss[i]);
	}
	for(int i = 0;i<n;is[i]=ss[i],i++);
	
	selectSort(ss,n);
	
	printf("\n--- Selection Sort ---\n\n");
	for(int i = 0; i < n; i++){
		printf("Vetor[%i] = %i\n",i,ss[i]);
	}

	insertSort(is,n);
	
	printf("\n--- Insertion Sort ---\n\n");
	for(int i = 0; i < n; i++){
		printf("Vetor[%i] = %i\n",i,is[i]);
	}
	return 0;
}