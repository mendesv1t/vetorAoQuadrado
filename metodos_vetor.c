#include "global.c"
#include "stdlib.h"

// método para criar vetor original e auxiliar:
void preencheVetores() {
    // alocando memória para armazenamento de um vetor de inteiros:
    vetor = malloc(N * sizeof(int));
    vetorAux = malloc(N * sizeof(int));
    // criando os elementos ordenadamente de 0 ao N - 1;
    for (int i = 0; i < N; i++) {
        vetor[i] = i;
        vetorAux[i] = i;
    }
}

// cria comparator para ordenar inteiros:
int comparator(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// criando teste para validar resultados
int testVetor(int vetorOriginal[], int vetorQuadrado[]) {

    // utilizando o método qsort da biblioteca stdlib.h para ordenar valores de um vetor:
    qsort(vetorOriginal, N, sizeof(int), comparator);
    qsort(vetorQuadrado, N, sizeof(int), comparator);
    for (int i = 0; i < N; i++) {
        int quadrado = vetorOriginal[i] * vetorOriginal[i];
        if (quadrado != vetorQuadrado[i]) {
            return 1;
        }
    }
    return 0;
}
