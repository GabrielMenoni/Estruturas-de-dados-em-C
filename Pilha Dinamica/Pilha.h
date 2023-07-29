//Autor: Gabriel Fernandes Menoni (github.com/GabrielMenoni)

//Definições de elemento e Pilha
typedef struct elemento elemento;

struct elemento{
    int chave;
    elemento *ant;
};

typedef struct elemento* Pilha;

//Prototipos
Pilha* criaPilha();
int inserePilha(Pilha* pilha, int chave);
int removePilha(Pilha* pilha);
int consultaPilha(Pilha* pilha, int *ret);
int pilhaVazia(Pilha* pilha);
int tamanhoPilha(Pilha* pilha);
void imprimePilha(Pilha* pilha);
void liberaPilha(Pilha* pilha);