//Autor: Gabriel Fernandes Menoni (github.com/GabrielMenoni)

//Inclusão de bibliotecas / Headers
#include "ListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

/* Função criaLista (Gabriel Fernandes Menoni)
Entrada: Não possui
Retorno: Ponteiro para Lista
Objetivo: Função utilizada para criar uma nova lista */
Lista* criaLista(){
    Lista *new = malloc(sizeof(Lista));
    *new = NULL;

    return new;
}

/* Função insereInicio (Gabriel Fernandes Menoni)
Entrada: Uma lista e o numero a ser inserido
Retorno: Não possui
Objetivo: Insere um numero no indice 0 da lista */
void insereInicio(Lista* lista, int num){
    insereIndice(lista, 0, num);
    return;
}

/* Função insereFinal (Gabriel Fernandes Menoni)
Entrada: Uma lista e o numero a ser inserido
Retorno: Não possui
Objetivo: Insere um numero no final da lista */
void insereFinal(Lista* lista, int num){
    insereIndice(lista, tamanhoLista(lista), num);
    return;
}

/* Função insereIndice (Gabriel Fernandes Menoni)
Entrada: Uma lista, um indice e o numero a ser inserido
Retorno: 0 ou 1 (true or false)
Objetivo: Tenta inserir um numero no indice passado
Obs: Pode inserir em listas vazias. Escopo: de 0 até N+1 (sendo N o ultimo indice) */
int insereIndice(Lista* lista, int pos, int num){
    No *new = malloc(sizeof(No));
    new->chave = num;

    if(pos < 0){
        free(new);
        return 0;
    }

    if(pos == 0 || listaVazia(lista) == 1){
        if(listaVazia(lista) == 1 && pos == 0){
            new->prox = NULL;
            *lista = new;
            return 1;
        } else if (pos == 0){
            new->prox = *lista;
            *lista = new;
            return 1;
        } else {
            free(new);
            return 0;
        }
    }

    No *aux = *lista;
    No *past = NULL;
    int count = 0;
    while(aux->prox != NULL && count != pos){
        past = aux;
        aux = aux->prox;
        count++;
    }

    if(aux->prox == NULL){
        if(count == pos){
            past->prox = new;
            new->prox = aux;
            return 1;
        } else if(count + 1 == pos){
            new->prox = NULL;
            aux->prox = new;
            return 1;
        } else {
            free(new);
            return 0;
        }
    }

    past->prox = new;
    new->prox = aux;
    return 1;
}

/* Função removeInicio (Gabriel Fernandes Menoni)
Entrada: Uma lista
Retorno: 1 ou 0 (true or false)
Objetivo: Tenta remover o primeiro numero da lista */
int removeInicio(Lista* lista){
    return removeIndice(lista, 0);
}

/* Função removeFinal (Gabriel Fernandes Menoni)
Entrada: Uma lista
Retorno: 1 ou 0 (true or false)
Objetivo: Tenta remover o ultimo numero da lista */
int removeFinal(Lista* lista){
    return removeIndice(lista, tamanhoLista(lista) - 1);
}

/* Função removeIndice (Gabriel Fernandes Menoni)
Entrada: Uma lista e um indice
Retorno: 1 ou 0 (true or false)
Objetivo: Tenta remover o numero do indice da lista */
int removeIndice(Lista* lista, int indice){
    if(listaVazia(lista) == 1 || indice < 0){
        return 0;
    }

    int count = 0;
    No *past = NULL;
    No *aux = *lista;

    while(aux->prox != NULL && count != indice){
        past = aux;
        aux = aux->prox;
        count++;
    }

    if(aux->prox == NULL){
        if(count == indice){
            past->prox = NULL;
            free(aux);
            return 1;
        }

        return 0;
    }

    if(count == 0){
        *lista = aux->prox;
    } else {
        past->prox = aux->prox;
    }
    free(aux);
    return 1;
}

/* Função removeNum (Gabriel Fernandes Menoni)
Entrada: Uma lista e um numero
Retorno: 1 ou 0 (true or false)
Objetivo: Tenta remover o numero da lista */
int removeNum(Lista* lista, int num){
    if(listaVazia(lista) == 1){
        return 0;
    }

    No *aux = *lista;
    if(aux->chave == num){
        if(aux->prox == NULL){
            free(aux);
        *lista = NULL;
        return 1;
        }

        *lista = aux->prox;
        free(aux);
        return 1;
    }

    No *past = NULL;
    while(aux->chave != num && aux->prox != NULL){
        past = aux;
        aux = aux->prox;
    }
    if(aux->chave == num){
        if(aux->prox == NULL){
            free(aux);
            past->prox = NULL;
            return 1;
        }

        past->prox = aux->prox;
        free(aux);
        return 1;
    }

    return 0;
}

/* Função numToIndice (Gabriel Fernandes Menoni)
Entrada: Uma lista e um numero
Retorno: Indice do numero (-1 caso não seja possivel encontrar)
Objetivo: Tenta procura o indice do número na lista */
int numToIndice(Lista* lista, int num){
    if(listaVazia(lista) == 1){
        return -1;
    }

    No *aux = *lista;
    int count = 0;

    while(aux->chave != num && aux->prox != NULL){
        aux = aux->prox;
        count++;
    }

    if(aux->prox == NULL){
        if(aux->chave == num){
            return count;
        }
        return -1;
    }

    return count;
}

/* Função indiceToNum (Gabriel Fernandes Menoni)
Entrada: Uma lista e um indice
Retorno: Ponteiro para o número do indice (NULL caso não encontre)
Objetivo: Tenta procura o numero do indice na lista */
int* indiceToNum(Lista* lista, int indice){
    int *ret = NULL;

    if(listaVazia(lista) == 1 || indice < 0){
        return ret;
    }

    int count = 0;
    No *aux = *lista;

    while(aux->prox != NULL && count != indice){
        aux = aux->prox;
        count++;
    }

    if(aux->prox == NULL){
        if(count == indice){
            ret = &aux->chave;
        }

        return ret;
    }

    ret = &aux->chave;
    return ret;    
}

/* Função tamanhoLista (Gabriel Fernandes Menoni)
Entrada: Uma lista
Retorno: O tamanho da lista (N de indices + 1)
Objetivo: Contar quantos elementos possui a lista */
int tamanhoLista(Lista *lista){
    if(listaVazia(lista) == 1){
        return 0;
    }

    int count = 1;
    No *aux = *lista;
    while(aux->prox != NULL){
        aux = aux->prox;
        count++;
    }

    return count;
}

/* Função listaVazia (Gabriel Fernandes Menoni)
Entrada: Uma lista
Retorno: True or false (1 ou 0)
Objetivo: Verificar se uma lista está vazia */
int listaVazia(Lista* lista){
    if(*lista == NULL){
        return 1;
    }

    return 0;
}

/* Função imprimeLista (Gabriel Fernandes Menoni)
Entrada: Uma lista
Retorno: Não possui
Objetivo: Imprimir todos os elementos da lista no console */
void imprimeLista(Lista* lista){
    if(listaVazia(lista) == 1){
        printf("A lista esta vazia\n");
        return;
    }

    No *aux = *lista;
    printf("%d ", aux->chave);
    while(aux->prox != NULL){
        aux = aux->prox;
        printf("%d ", aux->chave);
    }

    printf("\n");
    return;
}

/* Função limpaLista (Gabriel Fernandes Menoni)
Entrada: Uma lista
Retorno: Não possui
Objetivo: Retirar todos os elementos da lista */
void limpaLista(Lista* lista){
    if(listaVazia(lista) == 1){
        return;
    }

    No *aux = *lista;
    if(aux->prox == NULL){
        free(aux);
        return;
    }

    No *prox = aux->prox;

    while(prox->prox != NULL){
        free(aux);
        aux = prox;
        prox = aux->prox;
    }

    free(aux);
    free(prox);
    *lista = NULL;
    return;
}