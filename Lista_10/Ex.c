#include "bib.h"

int main(int argc, char const *argv[]){
	srand(time(NULL));

	int n = Max;
	printf("Digite o valor de n; ");
	//scanf("%i",&n);
	
	int vetor[n];
	int ms[n],qs[n],bs[n],ss[n];
	for(int i = 0; i < n; i++){
		vetor[i] = rand()%100;
		printf("Vetor[%i] = %i\n",i,vetor[i]);
	}
	for(int i = 0;i<n;ms[i]=vetor[i],i++);
	for(int i = 0;i<n;qs[i]=vetor[i],i++);
	for(int i = 0;i<n;bs[i]=vetor[i],i++);
	for(int i = 0;i<n;ss[i]=vetor[i],i++);
	
	mergeSort(ms,0,n-1);
	printf("\n--- Merge Sort ---\n\n");
	for(int i = 0; i < n; i++){
		printf("Vetor[%i] = %i\n",i,ms[i]);
	}
	
	quickSort(qs,n);
	printf("\n--- Quick Sort ---\n\n");
	for(int i = 0; i < n; i++){
		printf("Vetor[%i] = %i\n",i,qs[i]);
	}
	
	return 0;
}