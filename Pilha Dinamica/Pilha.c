//Autor: Gabriel Fernandes Menoni (github.com/GabrielMenoni)

//Inclusão de bibliotecas / Headers
#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"


/* Função criaPilha (Gabriel Fernandes Menoni)
Entrada: Não possui
Retorno: Ponteiro para Pilha
Objetivo: Função utilizada para criar uma nova Pilha */
Pilha* criaPilha(){
    Pilha* new = malloc(sizeof(Pilha));
    *new = NULL;

    return new; 
}

/* Função inserePilha (Gabriel Fernandes Menoni)
Entrada: Uma pilha e um inteiro
Retorno: True or false (1 ou 0)
Objetivo: Inserir um elemento na pilha */
int inserePilha(Pilha* pilha, int chave){
    if(pilha == NULL)
        return 0;

    elemento *new = malloc(sizeof(elemento));
    new->chave = chave;

    if(*pilha == NULL){
        new->ant = NULL;
        *pilha = new;
        return 1;
    }

    new->ant = *pilha;
    *pilha = new;
    return 1;
}

/* Função removePilha (Gabriel Fernandes Menoni)
Entrada: Uma pilha
Retorno: True or false (1 ou 0)
Objetivo: Remover um elemento da pilha */
int removePilha(Pilha* pilha){
    if(pilha == NULL || *pilha == NULL)
        return 0;

    elemento *aux;

    aux = *pilha;
    *pilha = aux->ant;
    free(aux);
    return 1;
}

/* Função consultaPilha (Gabriel Fernandes Menoni)
Entrada: Uma pilha e um ponteiro para retorno do elemento
Retorno: True or false (1 ou 0)
Objetivo: Retornar o elemento do topo da pilha em (*ret) */
int consultaPilha(Pilha* pilha, int *ret){
    if(pilha == NULL || *pilha == NULL)
        return 0;

    *ret = (*pilha)->chave;
    return 1;
}

/* Função tamanhoPilha (Gabriel Fernandes Menoni)
Entrada: Uma pilha
Retorno: A qtd de elementos na pilha ou -1 caso não seja possivel verificar
Objetivo: - */
int tamanhoPilha(Pilha* pilha){
    if(pilha == NULL)
        return -1;

    if(*pilha == NULL)
        return 0;

    elemento *aux;
    aux = *pilha;
    int count = 1;

    while(aux->ant != NULL){
        aux = aux->ant;
        count++;
    }

    return count;
}

/* Função pilhaVazia (Gabriel Fernandes Menoni)
Entrada: Uma pilha
Retorno: True or false (1 ou 0)
Objetivo: Verificar se a pilha está vazia */
int pilhaVazia(Pilha* pilha){
    if(*pilha == NULL){
        return 1;
    }

    return 0;
}

/* Função imprimePilha (Gabriel Fernandes Menoni)
Entrada: Uma pilha
Retorno: Não possui
Objetivo: Imprimir todos os elementos da Pilha */
void imprimePilha(Pilha* pilha){
    if (*pilha == NULL){
        printf("Pilha vazia!\n");
        return;
    }

    elemento *aux = *pilha;

    while(aux->ant != NULL){
        printf("%d, ", aux->chave);
        aux = aux->ant;
    }

    printf("%d\n", aux->chave);
    return;
}

/* Função liberaPilha (Gabriel Fernandes Menoni)
Entrada: Uma pilha
Retorno: Não possui
Objetivo: Libera toda a memoria ocupada pela Pilha 
Obs: Não é recomendado utilizar a pilha após esse comando */
void liberaPilha(Pilha* pilha){
    if(pilha == NULL)
        return;

    elemento *aux;

    while(*pilha != NULL){
        aux = *pilha;
        *pilha = (*pilha)->ant;
        free(aux);
    }

    free(*pilha);
    free(pilha);
    return;
}