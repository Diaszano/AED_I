#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int a = 0, *b=NULL;
    float c = 0, *d=NULL;
    char e = '0', *f=NULL;

    b = &a;
    d = &c;
    f = &e;

    printf("Inteiro antes da modificacao: %i\n",a);
    printf("Real antes da modificacao: %f\n",c);
    printf("Char antes da modificacao: %c\n",e);
    
    *b = 3;
    *d = 3.141592;
    *f = 'P';

    printf("Inteiro depois da modificacao: %i\n",a);
    printf("Real depois da modificacao: %f\n",c);
    printf("Char depois da modificacao: %c\n",e);
	
	return 0;
}