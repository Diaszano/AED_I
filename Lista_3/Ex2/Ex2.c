#include <stdio.h>
#include <stdlib.h>
#define Max 3


int main(int argc, char *argv[]){
    float matriz[Max][Max] = {0};

    for (int i=0;i<Max;i++){
        for (int j=0;j<Max; j++){
            printf("Posicao:%p\t",&matriz[i][j]);
        }
        printf("\n\n");
    }
    return 0;
}