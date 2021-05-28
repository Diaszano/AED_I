#include "bib.h"

void selectSort(int vet[],int n){
	TEMPORARIAS aux;
	for (int i = 0; i < n-1; i++){
		aux.menor = i;
		for (int j = i+1; j < n; j++){
			if(vet[j] < vet[aux.menor]){
				aux.menor = j;
			}
		}
		if (i != aux.menor){
			aux.trocar = vet[i];
			vet[i] = vet[aux.menor];
			vet[aux.menor] = aux.trocar;
		}
	}
}

void insertSort(int vet[],int n){
	TEMPORARIAS aux;
	for (int i = 1; i < n; i++){
		aux.menor = i;
		for (;(aux.menor != 0) && (vet[aux.menor] < vet[aux.menor-1]); aux.menor--){
			aux.trocar = vet[aux.menor];
			vet[aux.menor] = vet[aux.menor-1];
			vet[aux.menor-1] = aux.trocar;
		}
	}
}