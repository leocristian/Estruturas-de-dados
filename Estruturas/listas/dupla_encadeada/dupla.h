typedef struct no No;

No *criarLista();
No *inserirOrdenado(No *lista, int valor);
No *remover(No *lista, int valor);
void buscar(No *lista, int valor);
void mostrarLista(No *lista);
void liberar(No *lista);