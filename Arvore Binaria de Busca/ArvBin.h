//Autor: Gabriel Fernandes Menoni (github.com/GabrielMenoni)

//Definições de No e ArvBin

typedef struct No No;

struct No{
    int chave;
    No* esq;
    No* dir;
};

typedef struct No* ArvBin;

//Protótipos
ArvBin* criaArvore();
int insereArv(ArvBin* arv, int num);
int removeArv(ArvBin* arv, int num);
int consultaElemento(ArvBin* arv, int num);
int arvVazia(ArvBin* arv);
int qtdNo(ArvBin* arv);
int altArv(ArvBin* arv);
void liberaArv(ArvBin* arv);

//Protótipos de funções auxiliares
void liberaNo(No* atual);
