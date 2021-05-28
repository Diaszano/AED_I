#include "bib.h"

void ordem(int vetor[]){
    int tmp = 0;
    for(int i = 0;i < Max; i++){
        for(int j=i+1;j<Max;j++){
            if (vetor[i]>vetor[j]){
                tmp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = tmp;
            }
        }
    }
}
