#include "bib.h"

int main(int argc, char *argv[]){
    int vet[Max] = {0},num = 2;
    
    array(vet,num);
    for (int i = 0;i<Max; i++){
        printf("%i\t",vet[i]);
    }
    printf("\n");
    return 0;
}

