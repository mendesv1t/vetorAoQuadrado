#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"

// variáveis globais, que serão compartilhadas com os fluxos de execução criados:
const int M = 2; // número de threads
const int N = 10; // número de elementos do vetor
int * vetor = NULL; // declarando vetor de inteiros.
int * vetorAux = NULL; // declarando vetor auxiliar de inteiros.