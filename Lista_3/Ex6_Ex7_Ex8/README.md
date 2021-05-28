# Exercício 6
Trecho 1
~~~C
main(){ 
    int mat[2][2] = {{1,2},{3,4}};
    int i,j;
    for (i=0;i<2;i++)
        for (j=0;j<2;j++)
            printf("%d\n",mat[i][j]);
    system("pause");
} 
~~~
Trecho 2 
~~~C
main(){
    int mat[2][2] = {{1,2},{3,4}};
    int *p = &mat[0][0];
    int i;
    for (i=0;i<4;i++)
        printf("%d\n",*(p+i));
    system("pause");
}
~~~

Ambos mostram (1,2,3,4), mas só que um percorre por um vetor bidimensional e o outro percorre um vetor unidimensional e usando ponteiro.

# Exercício 7
~~~C
main(){
    int i=3,j=5;
    int *p, *q;
    p = &i;
    q = &j;
    ...
}
~~~

Qual é o valor das seguintes expressões?
~~~C
a) p = &i
b) *p -*q
c) **&p
d) 3* -*p/(*q)+7
~~~
a) Localização da memória do i que contém 3 como informação.
b) 3 - 5 == -2
c) ponteiro de p 
d) indefinido

# Exercício 8
### Assumindo que pulo[] é um vetor do tipo int, quais das seguintes expressões referenciam o valor do terceiro elemento da vetor?
~~~c
a) *(pulo + 2)
b) *(pulo + 4)
c) pulo + 4
d) pulo + 2
~~~
Resposta A.