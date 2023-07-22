//Autor: Gabriel Fernandes Menoni (github.com/GabrielMenoni)

//Inclusão de Bibliotecas e Headers
#include <stdio.h>
#include <stdlib.h>
#include "HashInt.h"

//Função Main
int main(){

    // Define o tamanho da lista
    int Size = 10;
    Hash* has = criaHash(Size);

    //Inserção de elementos na Tabela
    insereElemento(has, 40);
    insereElemento(has, 31);
    insereElemento(has, 50);
    insereElemento(has, 60);
    insereElemento(has, 34);
    insereElemento(has, 35);
    insereElemento(has, 44);
    insereElemento(has, 25);
    insereElemento(has, 1);
    insereElemento(has, 13);
    insereElemento(has, 17);
    insereElemento(has, 18);

    //Testes de funcionalidades
    imprimeHash(has);
    printf("%d\n", qtdElementos(has));

    printf("\n");

    No aux;
    printf("%d\n", buscaElemento(has, 35, &aux));
    printf("%d\n", aux.chave);

    printf("\n");

    printf("%d\n", removeElemento(has, 1));
    printf("%d\n", removeElemento(has, 0));

    printf("\n");

    imprimeHash(has);
    printf("%d\n", qtdElementos(has));
    
    excluiHash(has);

    return 0;
}