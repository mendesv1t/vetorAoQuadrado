#include "threads.c"

int main(void) {
    // preenchendo vetor original e auxiliar com inteiros:
    preencheVetores();

    // recuperando o id das threads no sistema:
    pthread_t tid_sistema[M];
    int threads[M];

    // criando M threads:
    for (int i = 1; i <= M; i++) {
        threads[i] = i;
        if (pthread_create(&tid_sistema[i], NULL, vetorAoQuadrado, (void *)&threads[i])) {
            printf("--ERRO: pthread_create()\n");
            exit(-1);
        }
        printf("--Cria a thread %d\n", i);
    }

    // pthread_join aguarda o término das threads:
    for (int i = 0; i < M; i++) {
        pthread_join(tid_sistema[i], NULL);
    }

    //testando os resultados finais:
    if (testVetor(vetorAux, vetor) != 0) {
        printf("Ocorreu um erro: Algum fluxo de execução não efetuou o cálculo correto.\n");
    }


    printf("--Thread principal terminou\n");

    //desfazendo os mallocs:
    free(vetorAux);
    free(vetor);

    return 0;
}