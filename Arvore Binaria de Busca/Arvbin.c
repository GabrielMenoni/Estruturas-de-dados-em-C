//Autor: Gabriel Fernandes Menoni (github.com/GabrielMenoni)

//Inclusão de bibliotecas / headers
#include <stdlib.h>
#include <stdio.h>
#include "ArvBin.h"

/* Função criaArvore (Gabriel Fernandes Menoni)
Entrada: Não possui
Retorno: Ponteiro para ArvBin
Objetivo: Função utilizada para criar uma nova ABB */
ArvBin* criaArvore(){
    ArvBin *new = malloc(sizeof(ArvBin));
    *new = NULL;

    return new;
}

/* Função insereArv (Gabriel Fernandes Menoni)
Entrada: Uma ABB e um número
Retorno: True or false (1 ou 0)
Objetivo: Inserir um novo elemento na ABB (Não aceita elementos repetidos) */
int insereArv(ArvBin* arv, int num){
    if(arv == NULL)
        return 0;

    No *new = malloc(sizeof(No));
    new->chave = num;
    new->dir = NULL;
    new->esq = NULL;

    if(*arv == NULL){
        *arv = new;
        return 1;
    }

    No *aux = *arv;

    while(1){
        if(new->chave == aux->chave){
            return 0;
        } else if (new->chave < aux->chave){
            if(aux->esq == NULL){
                aux->esq = new;
                return 1;
            } else {
                aux = aux->esq;
            }     
        } else {
            if(aux->dir == NULL){
                aux->dir = new;
                return 1;
            } else {
                aux = aux->dir;
            }
        }
    }

    return 0;
}

/* Função removeArv (Gabriel Fernandes Menoni)
Entrada: Uma ABB e um número
Retorno: True or false (1 ou 0)
Objetivo: Remover um elemento na ABB */
int removeArv(ArvBin* arv, int num){
    if(arv == NULL || *arv == NULL)
        return 0;

    No *aux = *arv;
    No *past = NULL;

    //Busca do nó a ser removido
    while(aux->chave != num){
        if(aux->chave < num){
            if(aux->dir == NULL)
                return 0;

            past = aux;
            aux = aux->dir;
        } else {
            if(aux->esq == NULL)
                return 0;

            past = aux;
            aux = aux->esq;
        }
    }

    //Caso nó raiz
    if(past == NULL){
        //Sem filhos
        if(aux->dir == NULL && aux->esq == NULL){
            *arv = NULL;
            free(aux);
            return 1;
        }

        // Um filho
        else if (aux->dir == NULL && aux->esq != NULL){
            *arv = aux->esq;
            free(aux);
            return 1;

        } else if (aux->dir != NULL && aux->esq == NULL){
            *arv = aux->dir;
            free(aux);
            return 1;
        }

        // Dois filhos
        else{
            aux = aux->esq;

            while(aux->dir != NULL){
                past = aux;
                aux = aux->dir;
            }

            if(past == NULL){
                *arv = (*arv)->esq;
                free(aux);
                return 1;
            }

            free(*arv);
            past->dir = NULL;
            *arv = aux;
            return 1;
        }
    }

    //Caso "não nó raiz"
    //Caso sem filhos
    if(aux->dir == NULL && aux->esq == NULL){
        if(past->dir->chave == aux->chave){
            past->dir = NULL;
            free(aux);
            return 1;
        } else {
            past->esq = NULL;
            free (aux);   
            return 1;
        }
    }
    //Caso um filho
    else if(aux->dir == NULL && aux->esq != NULL){
        if(past->dir->chave == aux->chave){
            past->dir = aux->esq;
            free(aux);
            return 1;
        } else {
            past->esq = aux->esq;
            free(aux);
            return 1;
        }
    } else if(aux->dir != NULL && aux->esq == NULL){
        if(past->dir->chave == aux->chave){
            past->dir = aux->dir;
            free(aux);
            return 1;
        } else {
            past->esq = aux->dir;
            free(aux);
            return 1;
        }
    }
    //Caso 2 filhos
    else {
        No *past2 = NULL;
        aux = aux->esq;

        while(aux->dir != NULL){
            past2 = aux;
            aux = aux->dir;
        }

        if(past2 == NULL){
            if(past->dir->chave == num){
                aux->dir = past->dir->dir;
                free(past->dir);
                past->dir = aux;
                return 1;
            } else {
                aux->dir = past->esq->dir;
                free(past->esq);
                past->esq = aux;
                return 1;
            }
        }

        if(past->dir->chave == num){
            aux->dir = past->dir->dir;
            free(past->dir);
            past->dir = aux;
        } else {
            aux->dir = past->esq->dir;
            free(past->esq);
            past->esq = aux;
        }

        past2->dir = NULL;
        return 1;
    }

    return 0;
}

/* Função consultaElemento (Gabriel Fernandes Menoni)
Entrada: Uma ABB e um número
Retorno: True or false (1 ou 0)
Objetivo: Verificar se o elemento já consta na ABB */
int consultaElemento(ArvBin* arv, int num){
    if(arv == NULL || *arv == NULL)
        return 0;

    No *aux = *arv;

    while(aux->chave != num){
        if(aux->chave < num){
            if(aux->dir == NULL)
                return 0;

            aux = aux->dir;
        } else {
            if(aux->esq == NULL)
                return 0;

            aux = aux->esq;
        }
    }

    return 1;
}

/* Função arvVazia (Gabriel Fernandes Menoni)
Entrada: Uma ABB
Retorno: True or false (1 ou 0)
Objetivo: Verificar se a ABB está vazia */
int arvVazia(ArvBin* arv){
    if(arv == NULL || *arv == NULL)
        return 1;

    return 0;
}

/* Função qtdNo (Gabriel Fernandes Menoni)
Entrada: Uma ABB
Retorno: Qtd de nó na ABB
Objetivo: - */
int qtdNo(ArvBin* arv){
    if(arv == NULL || *arv == NULL)
        return 0;

    int qtdEsq = qtdNo(&((*arv)->esq));
    int qtdDir = qtdNo(&((*arv)->dir));
    return (qtdDir + qtdEsq + 1);
}

/* Função altArv (Gabriel Fernandes Menoni)
Entrada: Uma ABB
Retorno: Altura da ABB
Objetivo: - */
int altArv(ArvBin* arv){
    if(arv == NULL || *arv == NULL)
        return -1;

    if((*arv)->dir == NULL && (*arv)->esq == NULL)
        return 0;

    int altDir = altArv(&((*arv)->dir));
    int altEsq = altArv(&((*arv)->esq));

    return (altDir >= altEsq ? altDir : altEsq) + 1;
}

/* Função liberaArv (Gabriel Fernandes Menoni)
Entrada: Uma ABB
Retorno: Não possui
Objetivo: Desalocar toda a memoria da ABB */
void liberaArv(ArvBin* arv){
    if(arv == NULL)
        return;

    liberaNo((*arv)->dir);
    liberaNo((*arv)->esq);

    free(*arv);
    free(arv);

}

//========================================================================
//Funções auxiliares

/* Função liberaNo (Gabriel Fernandes Menoni)
Entrada: Um No
Retorno: Não possui
Objetivo: Desalocar toda a memoria do nó e seus filhos */
void liberaNo(No* atual){
    if(atual == NULL)
        return;

    liberaNo(atual->dir);
    liberaNo(atual->esq);

    free(atual);
}