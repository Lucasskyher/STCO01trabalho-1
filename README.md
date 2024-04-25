Feito por: Lucas Silva Pinheiro

I. Introdução
Este documento apresenta o trabalho feito em linguagem C que utiliza uma estrutura de dados de lista encadeada para realizar a soma de números grandes. O código implementa um menu interativo que permite ao usuário inserir números em duas listas e, em seguida, somar esses números, considerando que cada dígito é representado por um nó da lista. O objetivo é demonstrar como a estrutura de lista encadeada pode ser utilizada para lidar com números inteiros grandes que não podem ser armazenados diretamente em variáveis de tamanho fixo.

II. Breve Descrição do Problema Abordado
O problema abordado neste código é a soma de números inteiros grandes, que podem ter uma quantidade significativa de dígitos. Muitas linguagens de programação têm limitações no tamanho de inteiros que podem ser representados, e essa limitação pode ser insuficiente para representar números grandes. O código implementa uma solução para essa limitação, permitindo que o usuário insira números com quantidades variáveis de dígitos e, em seguida, some esses números.

III. Apresentação da Estrutura de Dados Utilizada
A estrutura de dados utilizada neste código é a lista encadeada. A lista encadeada é uma estrutura de dados dinâmica que consiste em nós, onde cada nó contém um valor e um ponteiro para o próximo nó na sequência. No contexto deste código, cada nó representa um dígito de um número, e a sequência de nós na lista representa o número inteiro. Duas listas encadeadas são utilizadas para armazenar os números a serem somados.

IV. Descrição das Principais Partes da Implementação
O código é dividido em várias partes:
Criação das Listas: Duas listas (l1 e l2) são criadas para armazenar os números a serem somados. Cada lista é inicializada como vazia.
Menu Interativo: O código implementa um menu interativo que permite ao usuário escolher entre várias opções, como inserir valores nas listas, imprimir as listas, somar os números ou limpar as listas.
Inserção de Valores: O usuário pode inserir valores de 0 a 9 nas listas. O código verifica se os valores são válidos e, se forem, insere esses valores no final das respectivas listas.
Impressão das Listas: O código permite a impressão das listas, mostrando os números que foram inseridos.
Soma dos Números: A função “somar_listas” é responsável por somar os números representados pelas duas listas. Ela percorre as listas e realiza a soma, considerando as regras de soma com transporte (quando a soma dos dígitos ultrapassa 9). O resultado é impresso na tela.
Liberação de Memória: O código permite a liberação de memória alocada para as listas quando o usuário deseja limpar as listas ou finalizar o programa.

V. Breve Explicação de Como Utilizar a Aplicação
Para utilizar a aplicação, siga os seguintes passos:
1- Execute o programa.
2- Use o menu interativo para inserir valores nas duas listas (l1 e l2) de 0 a 9.
3- Escolha a opção de somar as listas.
4- O resultado da soma será exibido na tela.
Você pode optar por imprimir as listas a qualquer momento para verificar os números inseridos.
Para limpar as listas e começar novamente, escolha a opção de limpar as listas.
Finalize o programa escolhendo a opção "Sair" no menu.

VI. Conclusão
O código apresentado demonstra uma implementação prática do uso de listas encadeadas para somar números inteiros grandes. A estrutura de lista encadeada é flexível o suficiente para lidar com números de tamanho variável, tornando-a uma solução adequada para esse tipo de problema. Além disso, a interface interativa oferece uma maneira conveniente para os usuários inserirem números e visualizarem o resultado da soma. O código fornece uma solução elegante para um desafio comum em programação: lidar com números grandes que ultrapassam os limites de representação de tipos de dados inteiros fixos.
