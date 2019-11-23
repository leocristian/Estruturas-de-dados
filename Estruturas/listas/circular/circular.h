typedef struct no No;

No *criarLista();
No *inserir(No *lista, int valor);
No *inserirOrdenado(No *lista, int valor);
No *remover(No *lista, int valor);
void buscar(No *lista, int valor);
void mostrar(No *lista);
void liberar(No *lista);