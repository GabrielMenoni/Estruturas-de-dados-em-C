//Autor: Gabriel Fernandes Menoni (github.com/GabrielMenoni)

//Inclusão de Bibliotecas e Headers
#include <stdlib.h>
#include <stdio.h>
#include "HashInt.h"

/* Função criaHash (Gabriel Fernandes Menoni)
Entrada: Tamanho da tabela
Retorno: Ponteiro para Tabela Hash
Objetivo: Função utilizada para criar uma nova tabela hash */
Hash* criaHash(int size){
    if (size <= 0){
        return NULL;
    }

    Hash *new = malloc(sizeof(Hash));
    new->qtd = 0;
    new->tam = size;
    new->Elemento = malloc(size * sizeof(No*));

    for(int i = 0; i < size; i++){
        new->Elemento[i] = NULL;
    }

    return new;
}

/* Função Hash (Gabriel Fernandes Menoni)
Entrada: Numero
Retorno: Indice do numero na Tabela
Obs: Função bem básica, recomenda-se verificar e trocar caso tenha necessidade */
int hash(int size, int num){
    return num % size;
}

/* Função insereElemento (Gabriel Fernandes Menoni)
Entrada: Tabela hash e um numero
Retorno: Não possui
Objetivo: Insere o número na tabela hash 
Obs: Insere sempre no final da lista ligada */
void insereElemento(Hash* has, int num){
    if(has == NULL){
        return;
    }

    int indice = hash(has->tam, num);

    No *new = malloc(sizeof(No));
    new->chave = num;
    new->prox = NULL;

    if(has->Elemento[indice] == NULL){
        has->Elemento[indice] = new;
        has->qtd = has->qtd + 1;
        return;
    } else {
        No *aux = has->Elemento[indice];
        while(aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = new;
        has->qtd = has->qtd + 1;
        return;
    }
}

/* Função removeElemento (Gabriel Fernandes Menoni)
Entrada: Tabela hash e um numero
Retorno: true or false (1 ou 0)
Objetivo: Remove o número da tabela hash 
Obs: Remove sempre o primeiro elemento encontrado com aquele número */
int removeElemento(Hash* has, int num){
    if(has == NULL){
        return 0;
    }
    
    int indice = hash(has->tam, num);

    No *aux = has->Elemento[indice];

    if(aux == NULL){
        return 0;
    }

    if(aux->chave == num){
        has->Elemento[indice] = aux->prox;
        free(aux);
        has->qtd = has->qtd - 1;
        return 1;
    }

    No *past = NULL;

    while(aux->prox != NULL && aux->chave != num){
        past = aux;
        aux = aux->prox;
    }

    if(aux->chave == num){
        past->prox = aux->prox;
        free(aux);
        has->qtd = has->qtd - 1;
        return 1;
    }

    return 0;
}

/* Função buscaElemento (Gabriel Fernandes Menoni)
Entrada: Tabela hash, um numero e o endereço de um nó (recomenda-se passar &nó e não ponteiro)
Retorno: o indice do elemento buscado e o endereço dele na variavel ret
Objetivo: Buscar um Elemento na tabela hash e retornar o seu indice e seu endereço 
Obs: Retorna sempre o primeiro elemento com o número*/
int buscaElemento(Hash* has, int num, No* ret){
    if(has == NULL){
        ret = NULL;
        return -1;
    }
    
    int indice = hash(has->tam, num);

    No *aux = has->Elemento[indice];

    while(aux->prox != NULL && aux->chave != num){
        aux = aux->prox;
    }

    if(aux->chave == num){
        *ret = *aux;
        return indice;
    }

    ret = NULL;
    return -1;
}

/* Função qtdElementos (Gabriel Fernandes Menoni)
Entrada: Tabela hash
Retorno: quantidade de elementos na tabela hash
Objetivo: - */
int qtdElementos(Hash* has){
    return has->qtd;
}

/* Função imprimeHash (Gabriel Fernandes Menoni)
Entrada: Tabela hash
Retorno: Não possui
Objetivo: Imprimir toda a tabela no console do programa */
void imprimeHash(Hash* hash){
    if(hash == NULL){
        printf("A tabela nao existe\n");
        return;
    }

    int size = hash->tam;
    No *aux = NULL;

    for(int i = 0; i < size; i++){
        printf("%d: ", i+1);

        if (hash->Elemento[i] == NULL){
            printf("Vazia");
        } else {
            aux = hash->Elemento[i];
            printf("%d", aux->chave);

            while(aux->prox != NULL){
                aux = aux->prox;
                printf(" %d", aux->chave);
            }
        }

        printf("\n");
    }
}

/* Função excluiHash (Gabriel Fernandes Menoni)
Entrada: Tabela hash
Retorno: Não possui
Objetivo: Desalocar todo o espaço em memoria da tabela hash 
Obs: Não é recomendavel utilizar nenhuma função com a tabela hash após
     esse comando, pois a mesma possuirá comportamento indefinido. */
void excluiHash(Hash* has){
    if(has != NULL){
        for(int i = 0; i < has->tam; i++){
            limpa(has->Elemento[i]);
        }

        free(has->Elemento);
        free(has);
    }
}

/* Função limpa (Gabriel Fernandes Menoni)
Entrada: Ponteiro para Nó
Retorno: Não possui
Objetivo: auxilia a função excluiHash
Obs: Não é recomendavel utilizar a função por si só. */
void limpa(No* aux){
    if(aux->prox != NULL){
        limpa(aux->prox);
    }

    free(aux);
}