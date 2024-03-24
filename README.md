# Vetor ao Quadrado
Laboratório 1 da Disciplina: Programação Concorrente, no período 2024.1

O programa consiste em, dado um vetor de N inteiros, e dada uma quantidade M de threads
realizar as operações de elevar ao quadrado cada valor inteiro presente no vetor.

Diante o proposto, armazenei as variáveis globais do programa no arquivo 'global.c', que
consistem no número de inteiros no vetor (N), número de threads (M), bem como a inicialização
do vetor original e uma cópia auxiliar. 

No arquivo 'threads.c' você encontrará a tarefa determinada para cada thread realizar a execução (```vetorAoQuadrado```),
escolhi uma lógica que divide os inteiros em lotes, nos quais cada thread realiza a rotina de "elevar ao quadrado"
o valor de cada inteiro dentro de um lote específico, a fim de não termos resultados equivocados no fim.

No arquivo 'metodos_vetor.c', tentei englobar todos os métodos que utilizei para manipulaçao de vetores, onde
inclui o método ```test_vetor```, no qual é responsável por realizar o teste dos resultados após os novos fluxos
de execução realizarem as tarefas destinadas.

Por fim, o arquivo 'main.c', sendo o arquivo principal, toma conta de realizar a criação das threads e definir
qual método irão executar, ele também armazena o vetor auxiliar durante a execução, chama a funcão de teste
para verificar se tudo está ok e libera o espaço alocado para os vetores na memória no fim.

Para executar o programa basta rodar ```gcc -o main main.c -lpthread -Wall```
em seguida, rode ```./main```.
