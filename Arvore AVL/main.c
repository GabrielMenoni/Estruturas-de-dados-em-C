//Inclusão de bibliotecas / headers
#include <stdlib.h>
#include <stdio.h>
#include "ArvAVL.h"

int main(){

    //Criação da arvore
    ArvAvl *arv = criaArvore();

    //Adição de elementos (recomendação de site: https://www.inf.ufsc.br/~aldo.vw/estruturas/simulador/AVL.html)
    printf("%d\n", insereArv(arv, 50));
    printf("%d\n", insereArv(arv, 40));
    printf("%d\n", insereArv(arv, 35));
    printf("%d\n", insereArv(arv, 30));
    printf("%d\n", insereArv(arv, 32));
    printf("%d\n", insereArv(arv, 38));
    printf("%d\n", insereArv(arv, 60));
    printf("%d\n", insereArv(arv, 55));
    printf("%d\n", insereArv(arv, 70));
    printf("%d\n", insereArv(arv, 70));

    printf("\n");

    //print da raiz, primeiro elemento da dir e primeiro elemento da esq
    printf("%d %d %d\n", (*arv)->chave, (*arv)->dir->chave, (*arv)->esq->chave);
    printf("%d\n", altArv(arv));

    printf("\n");

    //Remoções
    printf("%d\n", removeArv(arv, 30));
    printf("%d\n", removeArv(arv, 70));
    printf("%d\n", removeArv(arv, 80));

    printf("\n");

    //print da raiz, primeiro e segundo elemento da direita
    printf("%d %d %d\n", (*arv)->chave, (*arv)->dir->chave, (*arv)->dir->dir->chave);
    //print da raiz, primeiro e segundo elemento da esquerda
    printf("%d %d %d\n", (*arv)->chave, (*arv)->esq->chave, (*arv)->esq->esq->chave);
    printf("%d\n", altArv(arv));

    printf("\n");

    //Testes de funcionalidades
    printf("%d\n", qtdNo(arv));
    printf("%d\n", consultaElemento(arv, 70));
    printf("%d\n", consultaElemento(arv, 40));
    
    liberaArv(arv);

    return 0;
}