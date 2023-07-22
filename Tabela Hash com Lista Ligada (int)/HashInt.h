//Defnições de tipos de dados abstratos Nó e Hash
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