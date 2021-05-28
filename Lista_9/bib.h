#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max 10
typedef struct temporarias{
	int menor;
	int trocar;
}TEMPORARIAS;

void selectSort(int vet[],int n);
void insertSort(int vet[],int n);