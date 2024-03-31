#include <stdio.h>
#include <stdlib.h>

// Função para trocar os valores de dois floats
void trocar(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ordenar os valores em ordem crescente
void ordenar_em_ordem_crescente(float *valores, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (valores[j] > valores[j + 1]) {
                trocar(&valores[j], &valores[j + 1]);
            }
        }
    }
}

// Função para ler valores e apresentá-los em ordem crescente
void ordenar_crescente(int n) {
    // Alocar memória para armazenar os valores
    float *valores = (float *)malloc(n * sizeof(float));

    if (valores == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    // Ler os valores
    printf("Digite %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &valores[i]);
    }

    // chamando a função para ordenar os valores em ordem crescente
    ordenar_em_ordem_crescente(valores, n);

    // Apresentar os valores em ordem crescente
    printf("Valores em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f\n", valores[i]);
    }

    // Liberar a memória alocada
    free(valores);
}

int main() {
    int n;
    printf("Quantos valores deseja inserir? ");
    scanf("%d", &n);

    // chama a função para ordenar os valores
    ordenar_crescente(n);

    return 0;
}