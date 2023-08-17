//Autor: Gabriel Fernandes Menoni (github.com/GabrielMenoni)

//Inclusão de bibliotecas / headers
#include <stdlib.h>
#include <stdio.h>
#include "ArvAVL.h"

/* Função criaárvore (Gabriel Fernandes Menoni)
Entrada: Não possui
Retorno: Ponteiro para ArvAvl
Objetivo: Função utilizada para criar uma nova arvore avl */
ArvAvl* criaArvore(){
    ArvAvl *new = malloc(sizeof(ArvAvl));
    *new = NULL;

    return new;
}

/* Função insereArv (Gabriel Fernandes Menoni)
Entrada: árvore avl e numero a ser inserido
Retorno: True or False (1 ou 0)
Objetivo: Inserir um número na arvore avl e balancear */
int insereArv(ArvAvl* arv, int num){
    if(arv == NULL)
        return 0;

    int aux;
    //Caso no raiz ou folha
    if(*arv == NULL){
        No *new = malloc(sizeof(No));
        new->dir = NULL;
        new->esq = NULL;
        new->chave = num;
        new->altura = 0;
        *arv = new;
        return 1;
    }

    No *atual = *arv;

    //Inserção na sub-árvore da esquerda com tratamento de balanceamento
    if(num < atual->chave){
        if((aux = insereArv(&(atual->esq), num)) == 1){
            if(fatBalan(atual) >= 2){
                if(num < (*arv)->esq->chave){
                    rotacaoLL(arv);
                } else {
                    rotacaoLR(arv);
                }
            }
        }

    //Inserção na sub-árvore da direita com tratamento de balanceamento
    } else if (num > atual->chave){
        if((aux = insereArv(&(atual->dir), num)) == 1){
            if(fatBalan(atual)>= 2){
                if((*arv)->dir->chave < num){
                    rotacaoRR(arv);
                } else {
                    rotacaoRL(arv);
                }
            }
        }
    //Caso número repetido
    } else {
        return 0;
    }

    //Calculo da altura atual
    atual->altura = maior(altArv(&(atual->esq)), altArv(&(atual->dir))) + 1;

    return aux;
}

/* Função removeArv (Gabriel Fernandes Menoni)
Entrada: Árvore avl e numero a ser removido
Retorno: True or False (1 ou 0)
Objetivo: Buscar o nó a ser removido e tratar todos os casos de remoção */
int removeArv(ArvAvl* arv, int num){
    if(arv == NULL || *arv == NULL)
        return 0;

    int aux;
    
    //Inserção na sub-árvore da esquerda com tratamento de balanceamento
    if(num < (*arv)->chave){
        if((aux = removeArv(&(*arv)->esq, num)) == 1){
             (*arv)->altura = maior(altArv(&(*arv)->esq), altArv(&(*arv)->dir)) + 1;
            if(fatBalan(*arv) >= 2){
                if(altArv(&(*arv)->dir->esq) <= altArv(&(*arv)->dir->dir)){
                    rotacaoRR(arv);
                } else {
                    rotacaoRL(arv);
                }
            }
        }
    //Inserção na sub-árvore da direita com tratamento de balanceamento
    } if ((*arv)->chave < num){
        if((aux = removeArv(&(*arv)->dir, num)) == 1){
            (*arv)->altura = maior(altArv(&(*arv)->esq), altArv(&(*arv)->dir)) + 1;
            if(fatBalan(*arv) >= 2){
                if(altArv(&(*arv)->esq->dir) <= altArv(&(*arv)->esq->esq)){
                    rotacaoLL(arv);
                } else {
                    rotacaoLR(arv);
                }
            }
        }

    //Número a ser removido encontrado    
    } if (num == (*arv)->chave){
        //Caso 1 ou nenhum filho
        if(((*arv)->esq == NULL || (*arv)->dir == NULL)){
            No *elim = *arv;
            if((*arv)->esq != NULL){
                *arv = (*arv)->esq;
            } else {
                *arv = (*arv)->dir;
            }
            free(elim);

        //Caso 2 filhos
        } else {
            No *temp = menorNo((*arv)->dir);
            (*arv)->chave = temp->chave;
            removeArv(&(*arv)->dir, (*arv)->chave);
            if(fatBalan(*arv) >= 2){
                if(altArv(&(*arv)->esq->dir) <= altArv(&(*arv)->esq->esq)){
                    rotacaoLL(arv);
                } else {
                    rotacaoLR(arv);
                }
            }
        }

        return 1;
    }
    return aux;
}

/* Função consultaElemento (Gabriel Fernandes Menoni)
Entrada: Uma árvore avl e um número
Retorno: True or false (1 ou 0)
Objetivo: Verificar se o elemento já consta na árvore avl */
int consultaElemento(ArvAvl* arv, int num){
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

/* Função qtdNo (Gabriel Fernandes Menoni)
Entrada: Uma árvore avl
Retorno: Qtd de nó na árvore avl
Objetivo: - */
int qtdNo(ArvAvl* arv){
    if(arv == NULL || *arv == NULL)
        return 0;

    int qtdEsq = qtdNo(&((*arv)->esq));
    int qtdDir = qtdNo(&((*arv)->dir));
    return (qtdDir + qtdEsq + 1);
}

/* Função altArv (Gabriel Fernandes Menoni)
Entrada: Uma árvore avl
Retorno: Altura da árvore avl
Objetivo: - */
int altArv(ArvAvl* arv){
    if(arv == NULL || *arv == NULL)
        return -1;

    return (*arv)->altura;
}

/* Função arvVazia (Gabriel Fernandes Menoni)
Entrada: Uma árvore avl
Retorno: True or false (1 ou 0)
Objetivo: Verificar se a árvore avl está vazia */
int arvVazia(ArvAvl* arv){
    if(arv == NULL || *arv == NULL)
        return 1;

    return 0;
}

/* Função liberaArv (Gabriel Fernandes Menoni)
Entrada: Uma árvore avl
Retorno: Não possui
Objetivo: Desalocar toda a memoria da árvore avl */
void liberaArv(ArvAvl* arv){
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

/* Função fatBalan (Gabriel Fernandes Menoni)
Entrada: Um nó
Retorno: Fator de balanceamento do no
Objetivo: Realizar o calculo do fator de balanceamento de um nó */
int fatBalan(No* atual){
    return labs(altArv(&(atual->esq)) - altArv(&(atual->dir)));
}

/* Função maior (Gabriel Fernandes Menoni)
Entrada: 2 inteiros
Retorno: Maior inteiro entre os 2
Objetivo: - */
int maior(int x, int y){
    if(x > y)
        return x;

    return y;    
}

/* Função rotacaoLL (Gabriel Fernandes Menoni)
Entrada: Árvore avl
Retorno: Não possui
Objetivo: Realizar uma rotação LL */
void rotacaoLL(ArvAvl* Desb){
    No *aux;
    aux = (*Desb)->esq;
    (*Desb)->esq = aux->dir;
    aux->dir = *Desb;
    
    (*Desb)->altura = maior(altArv(&((*Desb)->esq)), altArv(&((*Desb)->dir))) + 1;
    aux->altura = maior(altArv(&(aux->esq)), (*Desb)->altura) + 1;

    *Desb = aux;
}

/* Função rotacaoRR (Gabriel Fernandes Menoni)
Entrada: Árvore avl
Retorno: Não possui
Objetivo: Realizar uma rotação RR */
void rotacaoRR(ArvAvl* Desb){
    No *aux;
    aux = (*Desb)->dir;
    (*Desb)->dir = aux->esq;
    aux->esq = *Desb;

    (*Desb)->altura = maior(altArv(&((*Desb)->esq)), altArv(&((*Desb)->dir))) + 1;
    aux->altura = maior(altArv(&(aux->dir)), (*Desb)->altura) + 1;

    *Desb = aux;
}

/* Função rotacaoLR (Gabriel Fernandes Menoni)
Entrada: Árvore avl
Retorno: Não possui
Objetivo: Realizar uma rotação LR */
void rotacaoLR(ArvAvl* Desb){
    rotacaoRR(&(*Desb)->esq);
    rotacaoLL(Desb);    
}

/* Função rotacaoRL (Gabriel Fernandes Menoni)
Entrada: Árvore avl
Retorno: Não possui
Objetivo: Realizar uma rotação RL */
void rotacaoRL(ArvAvl* Desb){
    rotacaoLL(&(*Desb)->dir);
    rotacaoRR(Desb);
}

/* Função menorNo (Gabriel Fernandes Menoni)
Entrada: Ponteiro para nó
Retorno: Menor nó da árvore
Objetivo: Procurar o menor nó da árvore */
No* menorNo(No* atual){
    while(atual->esq != NULL){
        atual = atual->esq;
    }

    return atual;
}