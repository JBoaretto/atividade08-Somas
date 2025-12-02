#include <stdio.h>
#include <stdlib.h>

char sequencial(int k, int *A, int N);

int main(){
    // Leitura de dados
    int N; 
    if(scanf("%d", &N) != 1) return 1;

    int *A = (int *)malloc(N * sizeof(int));
    if(A == NULL) return 1;

    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    // Consultas
    int M;
    if(scanf("%d", &M) != 1){
        free(A);
        return 1;
    }

    int *K = (int *)malloc(M * sizeof(int));
    if(K == NULL){
        free(A);
        return 1;
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &K[i]);
    }

    // Processamento e saída
    for (int i = 0; i < M; i++)
    {
        printf("%c\n", sequencial(K[i], A, N));
    }
    
    free(A);
    free(K);

    return 0;
}

char sequencial(int k, int *A, int N){
    for(int i = 0; i < (N - 1); i++){
        for (int j = (i + 1); j < N; j++)
        {
            if(A[i] + A[j] == k){
                return 'S';
            }
        }
    }
    return 'N';
}