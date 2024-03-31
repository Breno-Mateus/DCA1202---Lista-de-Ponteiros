#include <stdio.h>
#include <stdlib.h>

// Função para multiplicação de matrizes
void multiplica_matrizes(int *A, int *B, int *C, int linhas_A, int colunas_A, int colunas_B) {
    for (int i = 0; i < linhas_A; i++) {
        for (int j = 0; j < colunas_B; j++) {
            C[i * colunas_B + j] = 0; // Inicializa o elemento C[i][j] como zero
            for (int k = 0; k < colunas_A; k++) {
                C[i * colunas_B + j] += A[i * colunas_A + k] * B[k * colunas_B + j]; // Soma o produto dos elementos correspondentes
            }
        }
    }
}

// Função para imprimir uma matriz
void imprime_matriz(int *matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i * colunas + j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas_A = 2, colunas_A = 3, colunas_B = 4;

    // Alocação de memória para as matrizes A, B e C
    int *A = (int *)malloc(linhas_A * colunas_A * sizeof(int));
    int *B = (int *)malloc(colunas_A * colunas_B * sizeof(int));
    int *C = (int *)malloc(linhas_A * colunas_B * sizeof(int));

    // Preenchimento das matrizes A e B (apenas para teste)
    for (int i = 0; i < linhas_A * colunas_A; i++) {
        A[i] = i + 1;
    }
    for (int i = 0; i < colunas_A * colunas_B; i++) {
        B[i] = i + 1;
    }

    // Chamada da função de multiplicação de matrizes
    multiplica_matrizes(A, B, C, linhas_A, colunas_A, colunas_B);

    // Impressão das matrizes A, B e C (apenas para teste)
    printf("Matriz A:\n");
    imprime_matriz(A, linhas_A, colunas_A);
    printf("\nMatriz B:\n");
    imprime_matriz(B, colunas_A, colunas_B);
    printf("\nMatriz C (resultado da multiplicação AxB):\n");
    imprime_matriz(C, linhas_A, colunas_B);

    // Liberação da memória alocada
    free(A);
    free(B);
    free(C);

    return 0;
}
