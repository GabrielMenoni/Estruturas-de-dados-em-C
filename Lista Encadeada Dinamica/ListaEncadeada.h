//Autor: Gabriel Fernandes Menoni (github.com/GabrielMenoni)

//Definições de No e Lista
typedef struct No No;

struct No{
    int chave;
    No *prox;
};

typedef struct No* Lista;

//Prototipos
Lista* criaLista();
void insereInicio(Lista* lista, int num);
void insereFinal(Lista* lista, int num);
int insereIndice(Lista* lista, int pos, int num);
int removeInicio(Lista* lista);
int removeFinal(Lista* lista);
int removeIndice(Lista* lista, int indice);
int removeNum(Lista* lista, int num);
int numToIndice(Lista* lista, int num);
int* indiceToNum(Lista* lista, int indice);
int tamanhoLista(Lista *lista);
int listaVazia(Lista* lista);
void imprimeLista(Lista* lista);
void limpaLista(Lista* lista);