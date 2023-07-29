//Autor: Gabriel Fernandes Menoni (github.com/GabrielMenoni)

<<<<<<< HEAD
//Inclusão de Bibliotecas / Headers
=======
//Inclusão de Bibliotecas e Headers
>>>>>>> a5d46790d0377e56aed0eadd1bbb2d67c75088d5
#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

//Função Main
int main(){

    //Criação da lista
    Lista *list1 = criaLista();

    //Inserção na lista
    printf("%d\n",insereIndice(list1, 0, 42));
    printf("%d\n",insereIndice(list1, 1, 43));
    printf("%d\n",insereIndice(list1, 0, 44));
    printf("%d\n",insereIndice(list1, 3, 45));
    printf("%d\n",insereIndice(list1, 5, 45));
    printf("%d\n",insereIndice(list1, -1, 45));
    insereInicio(list1, 88);
    insereFinal(list1, 11);

    printf("\n");

<<<<<<< HEAD
    //Teste da estrutura
=======
    //Teste de funcionalidades
>>>>>>> a5d46790d0377e56aed0eadd1bbb2d67c75088d5
    imprimeLista(list1);
    printf("%d\n", tamanhoLista(list1));

    printf("\n");

    printf("%d\n", removeInicio(list1));
    printf("%d\n", removeFinal(list1));

    printf("\n");

    imprimeLista(list1);
    printf("%d\n", tamanhoLista(list1));

    printf("\n");

    printf("%d\n", removeNum(list1, 44));
    printf("%d\n", removeNum(list1, 972));
    printf("%d\n", removeIndice(list1, 2));
    printf("%d\n", removeIndice(list1, -1));

    printf("\n");

    imprimeLista(list1);
    printf("%d\n", tamanhoLista(list1));

    printf("\n");
    limpaLista(list1);

    imprimeLista(list1);

    return 0;
}