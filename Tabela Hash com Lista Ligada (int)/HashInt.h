<<<<<<< HEAD
//Autor: Gabriel Fernandes Menoni (github.com/GabrielMenoni)

//Definições de Nó e Hash
=======
//Defnições de tipos de dados abstratos Nó e Hash
>>>>>>> a5d46790d0377e56aed0eadd1bbb2d67c75088d5
typedef struct No No;

struct No{
    int chave;
    No *prox;
};

typedef struct{
    int tam, qtd;
    No **Elemento;
} Hash;

//Protótipos
Hash* criaHash(int size);
int hash(int size, int num);
void insereElemento(Hash* has, int num);
int removeElemento(Hash* has, int num);
int buscaElemento(Hash* has, int num, No* ret);
int qtdElementos(Hash* has);
void imprimeHash(Hash* hash);
void excluiHash(Hash* has);
void limpa(No* aux);