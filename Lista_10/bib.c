#include "bib.h"

void merge(int vet[], int ini1, int fim1, int ini2, int fim2){
	int temp[50];
	int i = ini1, j = ini2, k = 0;

	while(i <= fim1 && j <= fim2){
		if(vet[i] < vet[j]){
			temp[k++] = vet[i++];
		}else{
			temp[k++] = vet[j++];
		}
	}

	while(i <= fim1){
		temp[k++] = vet[i++];
	}

	while(j <= fim2){
		temp[k++] = vet[j++];
	}

	for(i = ini1, j = 0; i <= fim2; i++, j++){
		vet[i] = temp[j];
	}
}
void mergeSort(int vet[],int m,int n){
	if(m < n){
		int meio = (m+n)/2;
		mergeSort(vet,m,meio);
		mergeSort(vet,meio+1,n);
		merge(vet,m, meio, meio + 1,n);
	}
}

void quickSort(int vet[],int n){
	int i, j, grupo, troca;
    if(n < 2){
        return;
    }else{
    	grupo = vet[n/2];
    }
    for(i = 0, j = n-1;; i++, j--){
        while(vet[i] < grupo){
            i++;
        }
        while(grupo < vet[j]){
            j--;
        }
        if(i >= j){
            break;
        }else{
			troca = vet[i];
			vet[i] = vet[j];
			vet[j] = troca;
        }
    }
    quickSort(vet, i);
    quickSort(vet + i, n - i);
}