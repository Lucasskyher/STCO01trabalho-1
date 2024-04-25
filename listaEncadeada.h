// TAD para Lista Dinâmica Encadeada 

#ifndef _LISTA_ENCADEADA
#define _LISTA_ENCADEADA

typedef struct elemento* Lista;

// funções para alocar e desalocar memória
Lista* criar_lista();
int liberar_lista(Lista *li);	

// funções para obter informações da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li, int dado);
int inserir_lista_final(Lista *li, int dado);

// função para imprimir a lista
int imprimir_lista(Lista *li);

// função para somar duas listas
int somar_listas(Lista *l1, Lista *l2);

#endif
