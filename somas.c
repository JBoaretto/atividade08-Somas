// Alunos
// João Pedro Boaretto - 16876293
// Lorena Borges - 16883652

#include <stdio.h>
#include <stdlib.h>

char sequencial(int k, int *A, int N);
char busca_binaria_aux (int k, int ordenado[], int N);
char busca_binaria (int procurado, int vetor[], int fim);

void mergesort(int vetor[], int tamVetor);
void mergesort_rec(int vetor[], int aux[], int inicio, int fim);
void merge(int vetor[], int aux[], int inicio, int meio, int fim);
void insertionsort(int vetor[], int tam);

int main(){
    int N; 
    if(scanf("%d", &N) != 1) return 1;

    int *A = (int *)malloc(N * sizeof(int));
    if(A == NULL) return 1;

    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    int *A_ordenado = (int *)malloc(N * sizeof(int));
    if(A_ordenado == NULL){
        free(A);
        return 1;
    }

    for(int i = 0; i < N; i++){
        A_ordenado[i] = A[i];
    }

    mergesort(A_ordenado, N);

    int M;
    if(scanf("%d", &M) != 1){
        free(A);
        free(A_ordenado);
        return 1;
    }

    int *K = (int *)malloc(M * sizeof(int));
    if(K == NULL){
        free(A);
        free(A_ordenado);
        return 1;
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &K[i]);
    }

    for (int i = 0; i < M; i++)
    {
        printf("%c\n", busca_binaria_aux(K[i], A_ordenado, N));
    }
    
    free(A);
    free(A_ordenado);
    free(K);

    return 0;
}

char sequencial(int k, int *A, int N){
    for(int i=0; i<(N-1); i++){
        for (int j=(i+1); j<N; j++)
        {
            if(A[i] + A[j] == k){
                return 'S';
            }
        }
    }
    return 'N';
}

char busca_binaria_aux (int k, int ordenado[], int N) {
    int procurado;

    for (int i=0; i<N-1; i++) {
        procurado = k-ordenado[i];
        if (busca_binaria(procurado, ordenado, N) == 'S') return 'S';
    }

    return 'N';
}

char busca_binaria (int procurado, int vetor[], int fim) {
    int inicio = 0;
    int meio;

    while(inicio <= fim-1) {
        meio = (inicio + (fim-1))/2;

        if (vetor[meio] == procurado) {
            return 'S';
        }

        if (procurado < vetor[meio]) {
            fim = meio;
        }
        else {
            inicio = meio+1;
        }
    }

    return 'N';
}

void mergesort(int vetor[], int tamVetor) {
    int *aux = (int *) malloc(tamVetor*sizeof(int));

    if (aux!=NULL) {
        mergesort_rec(vetor, aux, 0, tamVetor-1);
        
        free(aux);
    }
}

void mergesort_rec(int vetor[], int aux[], int inicio, int fim) {
    if ((fim-inicio)<25) {
        insertionsort(&vetor[inicio], fim-inicio + 1);
        return;
    }

    int meio = (inicio+fim)/2;

    mergesort_rec(vetor, aux, inicio, meio);
    mergesort_rec(vetor, aux, meio+1, fim);

    merge(vetor, aux, inicio, meio, fim);
}

void merge(int vetor[], int aux[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio+1;
    int k = inicio;

    while(i<=meio && j<=fim) {
        if (vetor[i]<=vetor[j]) {
            aux[k] = vetor[i];
            i++;
            k++;
        } else {
            aux[k] = vetor[j];
            j++;
            k++;
        }
    }

    while(i<=meio) {
        aux[k] = vetor[i];
        i++;
        k++;
    }

    while(j<=fim) {
        aux[k] = vetor[j];
        j++;
        k++;
    }

    for(i=inicio; i<=fim; i++) {
        vetor[i] = aux[i];
    }
}

void insertionsort(int vetor[], int tam) {
    for (int i=1; i<tam; i++) {
        int chave = vetor[i];
        int j = i-1;
        while (j>=0 && vetor[j] > chave) {
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = chave;
    }
}