//Autor: Gabriel Fernandes Menoni (github.com/GabrielMenoni)

//Definições de No e ArvAvl

typedef struct No No;

struct No{
    int chave;
    int altura;
    No* esq;
    No* dir;
};

typedef struct No* ArvAvl;

//Protótipos
ArvAvl* criaArvore();
int insereArv(ArvAvl* arv, int num);
int removeArv(ArvAvl* arv, int num);
int consultaElemento(ArvAvl* arv, int num);
int qtdNo(ArvAvl* arv);
int altArv(ArvAvl* arv);
int arvVazia(ArvAvl* arv);
void liberaArv(ArvAvl* arv);

//Protótipos de funções auxiliares
void liberaNo(No* atual);
int fatBalan(No* atual);
int maior(int x, int y);
void rotacaoLL(ArvAvl* Desb);
void rotacaoRR(ArvAvl* Desb);
void rotacaoLR(ArvAvl* Desb);
void rotacaoRL(ArvAvl* Desb);
No* menorNo(No* atual);
