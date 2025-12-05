// Alunos
// João Pedro Boaretto - 16876293
// Lorena Borges - 16883652

#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b);
char two_sum_two_pointers(int k, int v[], int n);

char sequencial(int k, int *A, int N);

char busca_binaria_aux(int k, int ordenado[], int N);
char busca_binaria(int procurado, int vetor[], int ini, int fim);

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int *A = (int *)malloc(N * sizeof(int));
    if (A == NULL) return 0;

    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    // ordena o vetor A
    qsort(A, N, sizeof(int), cmp_int);

    int M;
    if (scanf("%d", &M) != 1) {
        free(A);
        return 0;
    }

    for (int i = 0; i < M; i++) {
        int k;
        scanf("%d", &k);
        char ans = two_sum_two_pointers(k, A, N);
        printf("%c\n", ans);
    }

    free(A);
    return 0;
}

int cmp_int(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

char two_sum_two_pointers(int k, int v[], int n) {
    int i = 0;
    int j = n - 1;
    while (i < j) {
        long long soma = (long long)v[i] + v[j];
        if (soma == k) return 'S';
        if (soma < k)  i++; // soma pequena  ->  aumenta o menor elemento
        else           j--; // soma grande   ->  diminui o maior elemento
    }
    return 'N';
}

char busca_binaria(int procurado, int vetor[], int ini, int fim) {
    int l = ini, r = fim;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (vetor[m] == procurado) return 'S';
        if (procurado < vetor[m]) r = m - 1;
        else                      l = m + 1;
    }
    return 'N';
}

char busca_binaria_aux(int k, int ordenado[], int N) {
    for (int i = 0; i < N-1; i++) {
        int procurado = k - ordenado[i];
        if (busca_binaria(procurado, ordenado, i+1, N-1) == 'S') return 'S';
    }
    return 'N';
}

char sequencial(int k, int *A, int N) {
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            if (A[i] + A[j] == k) return 'S';
        }
    }
    return 'N';
}
