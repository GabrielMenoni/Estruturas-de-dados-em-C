//22:08


//Inclusão de bibliotecas / headers
#include <stdlib.h>
#include <stdio.h>
#include "ArvBin.h"


//Função principal
int main() {

    //Criação da arvore
    ArvBin *arv = criaArvore();

    //Adição de elementos
    printf("%d\n", insereArv(arv, 30));
    printf("%d\n", insereArv(arv, 20));
    printf("%d\n", insereArv(arv, 10));
    printf("%d\n", insereArv(arv, 25));
    printf("%d\n", insereArv(arv, 40));
    printf("%d\n", insereArv(arv, 50));
    printf("%d\n", insereArv(arv, 35));
    printf("%d\n", insereArv(arv, 35));

    printf("\n");

    //Testes de funcionalidades
    printf("%d\n", removeArv(arv, 20));
    printf("%d\n", (*arv)->esq->chave);
    printf("%d\n", altArv(arv));
    printf("%d\n", qtdNo(arv));
    printf("%d\n", consultaElemento(arv, 40));
    printf("%d\n", consultaElemento(arv, 20));
    liberaArv(arv);


    return 0;
}