#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma matriz tridimensional
typedef struct {
    int ***dados;
    int altura;
    int largura;
    int profundidade;
} MatrizTridimensional;

// Função para alocar dinamicamente uma matriz tridimensional
MatrizTridimensional* criarMatrizTridimensional(int altura, int largura, int profundidade) {
    // Alocação do ponteiro para a estrutura da matriz
    MatrizTridimensional *matriz = (MatrizTridimensional*)malloc(sizeof(MatrizTridimensional));

    if (matriz == NULL) {
        printf("Erro ao alocar memória para a matriz.\n");
        exit(1);
    }

    // Atribuição das dimensões da matriz
    matriz->altura = altura;
    matriz->largura = largura;
    matriz->profundidade = profundidade;

    // Alocação das linhas da matriz
    matriz->dados = (int***)malloc(altura * sizeof(int**));
    if (matriz->dados == NULL) {
        printf("Erro ao alocar memória para as linhas da matriz.\n");
        exit(1);
    }

    // Alocação das colunas da matriz
    for (int i = 0; i < altura; i++) {
        matriz->dados[i] = (int**)malloc(largura * sizeof(int*));
        if (matriz->dados[i] == NULL) {
            printf("Erro ao alocar memória para as colunas da matriz.\n");
            exit(1);
        }
        
        // Alocação das profundidades da matriz
        for (int j = 0; j < largura; j++) {
            matriz->dados[i][j] = (int*)malloc(profundidade * sizeof(int));
            if (matriz->dados[i][j] == NULL) {
                printf("Erro ao alocar memória para as profundidades da matriz.\n");
                exit(1);
            }
        }
    }

    return matriz;
}

// Função para liberar a memória alocada para a matriz tridimensional
void liberarMatrizTridimensional(MatrizTridimensional *matriz) {
    // Liberação das profundidades da matriz
    for (int i = 0; i < matriz->altura; i++) {
        for (int j = 0; j < matriz->largura; j++) {
            free(matriz->dados[i][j]);
        }
    }

    // Liberação das colunas da matriz
    for (int i = 0; i < matriz->altura; i++) {
        free(matriz->dados[i]);
    }

    // Liberação das linhas da matriz
    free(matriz->dados);

    // Liberação da estrutura da matriz
    free(matriz);
}

// Função para imprimir um plano da matriz tridimensional
void imprimirPlano(MatrizTridimensional *matriz, int plano) {
    printf("Plano %d:\n", plano);
    for (int i = 0; i < matriz->altura; i++) {
        for (int j = 0; j < matriz->largura; j++) {
            printf("%d ", matriz->dados[i][j][plano]);
        }
        printf("\n");
    }
}

// Função para modificar o estado de um elemento da matriz tridimensional
void modificarElemento(MatrizTridimensional *matriz, int altura, int largura, int profundidade, int valor) {
    matriz->dados[altura][largura][profundidade] = valor;
}

int main() {
    int altura, largura, profundidade;

    printf("Digite as dimensões da matriz tridimensional (altura largura profundidade): ");
    scanf("%d %d %d", &altura, &largura, &profundidade);

    // Criação da matriz tridimensional
    MatrizTridimensional *matriz = criarMatrizTridimensional(altura, largura, profundidade); /* Aqui está sendo declarado a variável matriz do tipo "MatrizTridimensional" que é um ponteiro. Que irá armazenar o endereço de memória da matriz tridimensional */

    // Exemplo de modificação de um elemento da matriz
    modificarElemento(matriz, 1, 1, 1, 1);

    // Exemplo de impressão de um plano da matriz
    imprimirPlano(matriz, 1);

    // Função usada para liberar as memórias alocadas na matriz tridimensional
    liberarMatrizTridimensional(matriz);

    return 0;
}
