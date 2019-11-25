typedef struct fila Fila;
typedef struct no No;

Fila *criarFila();
void inserirFila(Fila *f, int valor);
void removerFila(Fila *f);
void liberarFila(Fila *f);
void mostrar(Fila *f);