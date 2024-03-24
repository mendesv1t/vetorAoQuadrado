#include "pthread.h"
#include "metodos_vetor.c"

// método que será executado pelas threads
void * vetorAoQuadrado(void *arg) {

    int thread_num = *((int *) arg);
    int lote = N / (M * (N / M));

    int inicio = 0;
    if (thread_num > 1) {
        inicio = (thread_num - 1) * (N / M) * lote;
    }

    int fim = thread_num * (N / M) * lote;

    // para garantir casos ímpares chegarem ao fim do vetor:
    if (thread_num == M) {
        fim = N;
    }
    printf("Thread nº%.2d está executando o lote do %.2d ao %.2d\n", thread_num, inicio, fim);

    for (int i = inicio; i < fim; i++) {
        vetor[i] *= vetor[i];
    }

    printf("Thread %d finalizada.\n", thread_num);
    pthread_exit(NULL);

}