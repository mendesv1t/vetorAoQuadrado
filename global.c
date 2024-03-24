#include "stdio.h"

// variáveis globais, que serão compartilhadas com os fluxos de execução criados:
const int M = 4; // número de threads
const int N = 100; // número de elementos do vetor
int * vetor = NULL; // declarando vetor de inteiros.
int * vetorAux = NULL; // declarando vetor auxiliar de inteiros.