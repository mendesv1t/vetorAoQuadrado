#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// variáveis globais, que serão compartilhadas com os fluxos de execução criados:
const int M = 4; // número de threads
const int N = 100; // número de elementos de um vetor do tipo inteiro.
int *vetor; // declarando vetor de inteiros.
int *vetorAux; // declarando vetor auxiliar de inteiros.

// método que será executado pelas threads
void * vetorAoQuadrado(void *arg) {

    int thread_num = *((int *)arg);
    int lote = N / (M * (N/M));

    int inicio = 0;
    if (thread_num > 1 ) {
        inicio = (thread_num - 1) * (N/M) * lote;
    }

    int fim = thread_num * (N/M) * lote;
    // para garantir casos ímpares chegarem ao fim dos inteiros:
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

// método para criar vetor original e auxiliar:
void criaVetor(int tamanho) {

    // alocando memória para armazenamento de um vetor de inteiros:
    vetor = malloc(tamanho * sizeof(int));
    vetorAux = malloc(tamanho * sizeof(int ));
    // criando os elementos ordenadamente de 0 ao tamanho definido - 1;
    for (int i = 0; i < tamanho; i++) {
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
        int quadrado = vetorOriginal[i]*vetorOriginal[i];
        if (quadrado != vetorQuadrado[i]) {
            printf("Original: %.2d | Vetor quadrado: %.2d\n", vetorOriginal[i], vetorQuadrado[i]);
            return 1;
        }
    }
    return 0;
}

int main(void) {
    // criando vetor original e auxiliar para realizar as operações:
    criaVetor(N);

    pthread_t tid_sistema[M];
    int threads[M];

    for (int i = 1; i <= M; i++) {
        threads[i] = i;
        if (pthread_create(&tid_sistema[i], NULL, vetorAoQuadrado, (void *)&threads[i])) {
            printf("--ERRO: pthread_create()\n");
            exit(-1);
        }
        printf("--Cria a thread %d\n", i);
    }

    for (int i = 0; i < M; i++) {
        pthread_join(tid_sistema[i], NULL);
    }

    //testando os resultados:
    if (testVetor(vetorAux, vetor) != 0) {
        printf("Ocorreu um erro: Algum fluxo de execução não efetuou o cálculo correto.\n");
    }

    printf("--Thread principal terminou\n");


    return 0;
}
