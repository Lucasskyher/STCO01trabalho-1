// TAD para Lista Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

// definição do struct elemento
struct elemento{
  int dado;
  struct elemento *prox;
};

// renomeando a estrutura elemento acima
typedef struct elemento Elemento;


//**************************************************************************
// função para alocar memória do tipo Lista
Lista* criar_lista()
{
  Lista *li = (Lista*) malloc(sizeof(Lista));  

  // se a lista foi criada corretamente, indica que ela está vazia
  if(li != NULL){
    *li = NULL;
  } 

  return li;
}


//**************************************************************************
// função para liberar memória
int liberar_lista(Lista *li)
{
  if(li == NULL){    
    return 0;
  }

  // libera todos os nós da lista que foram alocados
  Elemento *atual;
  while(*li != NULL){ // verifica se a lista é vazia
    atual = *li;
    *li = (*li)->prox;
    free(atual);    
  }

  // libera o ponteiro da lista
  free(li);

  return 1;  
}


//**************************************************************************
// função para obter o tamanho da lista
int tamanho_lista(Lista *li)
{
  // a lista não foi criada corretamente
  if(li == NULL){
    return -1;
  }

  int cont = 0;
  Elemento *no = *li;

  // acrescenta cont até acabar a lista
  while(no != NULL){
    cont++;
    no = no->prox;
  }

  return cont;
}


//**************************************************************************
// função para verificar se a lista está vazia
int lista_vazia(Lista *li)
{
  // verifica se houve problema na criação da lista
  // ou seja, li não é uma lista válida
  if(li == NULL){
    return -1;
  }

  // verifica se a lista foi criada corretamente
  // mas não contém nenhum valor
  if(*li == NULL){
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}


//**************************************************************************
// função para alocar memória do tipo Elemento
Elemento* criar_elemento()
{
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));  

  return no;
}


//**************************************************************************
// função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li, int dado)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = (*li);

  // insere elemento no início da lista
  *li = no;

  return 1;
}


//**************************************************************************
// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li, int dado)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = NULL;

  // se a lista estiver vazia, insere no início da lista
  if( (*li) == NULL ){
    *li = no;

  }else{

    // senão percorre a lista até o fim e insere no final
    Elemento *aux;
    aux = *li;

    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = no;
  }

  return 1;
}


//**************************************************************************
// função para somar duas listas
int somar_listas(Lista *l1, Lista *l2) 
{

  // lista criada para inverter a lista l1
  Lista *rev1;
  rev1 = criar_lista();

  // lista criada para inverter a lista l2
  Lista *rev2;
  rev2 = criar_lista();

  // lista criada para receber a soma das listas rev1 e rev2
  Lista *soma;
  soma = criar_lista();
  
  // variavel para carregar a soma dos digitos
  int carry = 0;

  // verifica se as listas foram criadas ou preenchidas corretamente
  if(l1 == NULL || (*l1) == NULL)
  {
    return 0;
  }

  if(l2 == NULL || (*l2) == NULL)
  {
    return 0;
  }

  Elemento *aux1 = (*l1);
  Elemento *aux2 = (*l2);

  int cont1 = 1;
  int cont2 = 1;

  int num1 = 0;
  int num2 = 0;
  int num3 = 0;

  // inverte a lista l1, colocando na lista rev1
  while(aux1->prox != NULL)
  {
    inserir_lista_inicio(rev1, aux1->dado);
    aux1 = aux1->prox;
    cont1++;
  }
  inserir_lista_inicio(rev1, aux1->dado);

  // inverte a lista l2, colocando na lista rev2
  while(aux2->prox != NULL)
  {
    inserir_lista_inicio(rev2, aux2->dado);
    aux2 = aux2->prox;
    cont2++;
  }
  inserir_lista_inicio(rev2, aux2->dado);

  int dado = 0;

  // verifica o tamanho das listas rev1 e rev2, e iguala o numero de digitos em cada
  // adiciona '0' para igualar as casas (facilita a soma)
  if (cont1 > cont2)
  {
    do
    {
      inserir_lista_final(rev2, dado);
      cont2++;
    }while(cont1 != cont2);
  }

  if (cont2 > cont1)
  {
    do
    {
      inserir_lista_final(rev1, dado);
      cont1++;
    }while(cont1 != cont2);
  }

  Elemento *aux3 = (*rev1);
  Elemento *aux4 = (*rev2);
  
  // percorre as duas listas invertidas, e soma os digitos de cada casa equivalente
  // adiciona os valores somados no inicio da lista 'soma'
  while (aux3->prox != NULL && aux4->prox != NULL) 
  {
    num1 = aux3->dado;
    num2 = aux4->dado;
    num3 = num1 + num2 + carry;
   
    // verifica se o resultado da soma é maior que 9, se for, adiciona 1 na variavel carry
    if(num3 >= 10 && num3 < 20)
    {
      num3 = num3 - 10;
      inserir_lista_inicio(soma, num3);
      carry = 1;
    }
    // verifica se o resultado da soma é maior que 20, se for, adiciona 2 na variavel carry
    else if(num3 >= 20)
    {
      num3 = num3 - 20;
      inserir_lista_inicio(soma, num3);
      carry = 2;
    }
    else
    {
      inserir_lista_inicio(soma, num3);
      carry = 0;
    }

    aux3 = aux3->prox;
    aux4 = aux4->prox;
  }

  num1 = aux3->dado;
  num2 = aux4->dado;
  num3 = num1 + num2 + carry;
  inserir_lista_inicio(soma, num3);

  // imprimi a lista 'soma'
  printf("\nA Soma de ");
  imprimir_lista(l1);
  printf(" e ");
  imprimir_lista(l2);
  printf(" é: ");
  imprimir_lista(soma);
  printf("\n");
  
  return 1;
  
}


//**************************************************************************
// função para imprimir a lista dinâmica
int imprimir_lista(Lista *li)
{
    if(li == NULL || (*li) == NULL){
      return 0;
    }

    Elemento *aux = (*li);

    while(aux->prox != NULL){
      printf("%d", aux->dado);
      aux = aux->prox;
    }

    printf("%d", aux->dado);

    return 1;
}
