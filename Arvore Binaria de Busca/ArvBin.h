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
void liberaArv(ArvBin* arv);
void liberaNo(No* atual);
int arvVazia(ArvBin* arv);
int consultaElemento(ArvBin* arv, int num);
int qtdNo(ArvBin* arv);
int altArv(ArvBin* arv);
