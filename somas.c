// Alunos
// João Pedro Boaretto - 16876293
// Lorena Borges - 16883652

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

char busca_binaria_aux (int k, int ordenado[], int N) {
    int procurado;

    for (int i=0; i<N-1; i++) {
        procurado = ordenado[i]-k;
        if (busca_binaria(procurado, ordenado, N) == 'S') return 'S';
    }

    return 'N';
}

char busca_binaria (int procurado, int vetor[], int fim) {
    int meio = fim/2, inicio = 0;

    while(inicio<fim) {
        if (vetor[meio] == procurado) {
            return "S";
        }

        if (procurado<vetor[meio]) {
            fim = meio-1;
            meio = (meio-1)/2;
        }
        else {
            inicio = meio+1;
            meio = (fim-inicio)/2;
        }

    }

    return "N";
}

void mergesort(int vetor[], int tamVetor) {
    int *aux = (int *) malloc(tamVetor*sizeof(int));

    if (aux!=NULL) {
        mergesort_rec(vetor, aux, 0, tamVetor-1);
        
        free(aux);
    }
}

void mergesort_rec(int vetor[], int aux[], int inicio, int fim) {
    // para vetores com menos de 25 elementos, utiliza insertionsort para diminuir o peso da recursao
    // funciona tambem como uma forma complexa de caso base
    if ((fim-inicio)<25) {
        insertionsort(&vetor[inicio], fim-inicio + 1);
        return;
    }

    int meio = (inicio+fim)/2;

    // dividir para conquistar
    mergesort_rec(vetor, aux, inicio, meio);
    mergesort_rec(vetor, aux, meio+1, fim);

    // na volta da recursao, junta os subvetores ordenados ordenadamente
    merge(vetor, aux, inicio, meio, fim);
}

void merge(int vetor[], int aux[], int inicio, int meio, int fim) {
    int i = inicio;    // indice do subvetor esquerdo
    int j = meio+1;  // indice do subvetor direito
    int k = inicio;    // indice do vetor ordenado (aux)

    // enquanto houver elementos nao analisados nos dois subvetores
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

    // se sobrar algo de algum lado, copia tudo para o final do vetor ordenado
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

    // copia o vetor auxiliar ordenado para o vetor principal
    for(i=inicio; i<=fim; i++) {
        vetor[i] = aux[i];
    }
}