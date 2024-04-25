// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bibliotecas do projeto
#include "listaEncadeada.h"

// funcao principal
int main(void) 
{
  
  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  // o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Lista *l1 = NULL;
  Lista *l2 = NULL;
  
  int opcao1, opcao2, dado, ok;
  
  // cria as listas
  l1 = criar_lista();
  l2 = criar_lista();

  // menu de opções para execuções de operações sobre a lista
  do 
  {
    printf("\n\n------ SOMA DE NÚMEROS GRANDES ------");
    printf("\n1 - Informar valores para inserir na lista");
    printf("\n2 - Imprimir Lista 1");
    printf("\n3 - Imprimir Lista 2");
    printf("\n4 - Somar Lista 1 e Lista 2");
    printf("\n5 - Limpar as listas");
    printf("\n6 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao1);

    switch (opcao1) 
    {
      case 1:
        do
        {
          printf("\n\n----- INSERIR VALORES -----");
          printf("\n1 - Inserir valor na Lista 1 (de 0 a 9)");
          printf("\n2 - Inserir valor na Lista 2 (de 0 a 9)");
          printf("\n3 - Voltar");
          printf("\nOpção: ");
          scanf("%d", &opcao2);
          
          switch (opcao2)
          {
            case 1:
              printf("\n\n----- INSERIR VALORES NA LISTA 1 -----");
              printf("\nInforme o valor: ");
              scanf("%d", &dado);

              // verifica se o dado informado é maior que 9 ou menor que 0
              if(dado > 9 || dado < 0)
              {
                printf("\nValor inválido!\n");
                break;
              }

              // se passou, insere no final da lista 1
              ok = inserir_lista_final(l1, dado);
              if (ok == 1) 
              {
                printf("\nInserção realizada com sucesso!\n");
              } 
              else 
              {
                printf("\nFalha na inserção!\n");
              }
              break;

            case 2:
              printf("\n\n----- INSERIR VALORES NA LISTA 2 -----");
              printf("\nInforme o valor: ");
              scanf("%d", &dado);
              
              // verifica se o dado informado é maior que 9 ou menor que 0
              if(dado > 9 || dado < 0)
              {
                printf("\nValor inválido!\n");
                break;
              }
              
              // se passou, insere no final da lista 2
              ok = inserir_lista_final(l2, dado);
              if (ok == 1) 
              {
                printf("\nInserção realizada com sucesso!\n");
              } 
              else 
              {
                printf("\nFalha na inserção!\n");
              }
              break;

            case 3:
              printf("\nRetornando...\n");
              break;

            default:
              printf("\nOpção inválida!\n");
              break;

          }
        
        }while(opcao2 != 3);

        break;

      case 2:
        // imprime a lista 1
        printf("\nNúmero criado (Lista 1): ");
        ok = imprimir_lista(l1);

        if (!ok) 
        {
          printf("\nLista não encontrada!\n");
        }
        break;

      case 3:
        // imprime a lista 2
        printf("\nNúmero criado (Lista 2): ");
        ok = imprimir_lista(l2);

        if (!ok) 
        {
          printf("\nLista não encontrada!\n");
        }
        break;

      case 4:
        // funcao que recebe as duas listas, e imprimi a soma das duas
        ok = somar_listas(l1, l2);
        if(ok)
        {
          printf("\nSoma realizada com sucesso!\n");
        }
        else
        {
          printf("\nFalha ao somar!\n");
        }
        break;


      case 5:
        // libera memória
        liberar_lista(l1);
        liberar_lista(l2);

        //para criar novamente (vazias)
        l1 = criar_lista();
        l2 = criar_lista();

        printf("\nListas esvaziadas com sucesso!\n");
        break;
      
      
      case 6:
        // libera memória e finaliza programa
        liberar_lista(l1);
        liberar_lista(l2);
        printf("\nFinalizando...\n");
        break;

      default:
        printf("\nOpção inválida!\n");
        break;
    }

  }while(opcao1 != 6);
  
  return 0;
}
