//Inclusão de bibliotecas / Headers
#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"

//Função main
int main(){

    int *aux;
    Pilha* pilha = criaPilha();
    //Inserção de elementos
    printf("%d\n", inserePilha(pilha, 5));
    printf("%d\n", inserePilha(pilha, 6));
    printf("%d\n", inserePilha(pilha, 7));
    printf("%d\n", inserePilha(pilha, 8));
    printf("%d\n", inserePilha(pilha, 9));
    printf("%d\n", inserePilha(pilha, 10));
    printf("%d\n", inserePilha(pilha, 11));
    printf("\n");

    //Testes da estrutura
    imprimePilha(pilha);
    printf("%d\n", tamanhoPilha(pilha));
    printf("\n");

    printf("%d\n", removePilha(pilha));
    printf("%d\n", removePilha(pilha));
    printf("\n");
    imprimePilha(pilha);
    printf("%d\n", tamanhoPilha(pilha));
    printf("\n");

    printf("%d\n", consultaPilha(pilha, aux));
    printf("%d\n", *aux);

    liberaPilha(pilha);
    return 0;
}