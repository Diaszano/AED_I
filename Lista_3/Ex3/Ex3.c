#include "bib.h"

int main(int argc, char *argv[]){
    int loteria[Max],bilete[Max];
    int *vet = NULL;
    
    printf("Digite os 6 numeros da loteria\n");
    for (int i = 0; i < Max; i++){
        printf("Digite o %iº: ",i+1);
        scanf("%i",&loteria[i]);
    }
    
    printf("\n\nDigite os 6 numeros do seu bilete\n");
    for (int i = 0; i < Max; i++){
        printf("Digite o %iº: ",i+1);
        scanf("%i",&bilete[i]);
    }
   
    ordem(loteria);
    ordem(bilete);

    int contador = 0;
    int tmp[Max];

    for(int i = 0;i < Max; i++){
        for(int j = 0;j < Max; j++){
            if (loteria[i] == bilete[j]){
                tmp[contador] = loteria[i];
                contador++;
            }
        }
    }
   
    if((vet=(int*)calloc(contador,sizeof(int)))==NULL){
        printf("Não foi possivel alocar memoria\n");
        exit(1);
    }
    for (int i = 0; i < contador;vet[i] = tmp[i], i++);
    for (int i = 0; i < contador; i++){
       printf("%i\t",vet[i]);
    }

    free(vet);
    vet = NULL;
    return 0;
}