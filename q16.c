#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b); // retorna um valor maior que zero caso seja necessario modificar os valores de posição e retornar um valor igual ou menor que zero caso não seja necessario modificar os valores de posição. A expressão converte a que é um ponteiro para void em um ponteiro para inteiro.
}

// Função para ler valores e apresentá-los em ordem crescente
void ordenar_crescente(int n) {

    float *valores = (float *)malloc(n * sizeof(float)); // Alocar memória para armazenar os valores

    if (valores == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    // Ler os valores e atribui
    printf("Digite %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &valores[i]);
    }

    // Chama a função qsort() para ordenar os valores com o auxilio da função comparar
    qsort(valores, n, sizeof(float), comparar);

    // Apresentar os valores em ordem crescente
    printf("Valores em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f\n", valores[i]);
    }

    // Liberar a memória alocada
    free(valores);
}

int main() {
    
    clock_t inicio, fim; //criando duas variaveis do tipo clock_t para armazenar os valores de inicio e fim

    inicio = clock(); //Iniciando o tempo

    int n;
    printf("Quantos valores deseja inserir? ");
    scanf("%d", &n); // obtém o tamanho do array

    ordenar_crescente(n); // chama a função para ordenar os valores

    fim = clock(); // Finalizando o tempo

    // Calcula o tempo decorrido em segundos
    double tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo decorrido: %.6f segundos\n", tempo_decorrido);

    return 0;
}
