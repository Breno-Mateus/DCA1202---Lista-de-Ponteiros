#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de comparação para ordenação crescente
int comparar_crescente(const void *a, const void *b) {
    int valor1 = *((int *)a);
    int valor2 = *((int *)b);
    return valor1 - valor2;
}

// Função de ordenação personalizada
void ordenar(int *array, int n, int (*comparar)(const void *, const void *)) {
    qsort(array, n, sizeof(int), comparar_crescente);
}

int main() {

    clock_t inicio, fim; //criando duas variaveis do tipo clock_t para armazenar os valores de inicio e fim

    inicio = clock(); //Iniciando o tempo

    int n;
    printf("Quantos valores deseja inserir? ");
    scanf("%d", &n);

    int valores[n];

    printf("Digite %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &valores[i]);
    }

    // Ordenação crescente
    ordenar(valores, n, comparar_crescente);

    printf("Array após a ordenação crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n");

    fim = clock(); // Finalizando o tempo

    // Calcula o tempo decorrido em segundos
    double tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo decorrido: %.6f segundos\n", tempo_decorrido);

    return 0;
}
