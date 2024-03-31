#include <stdio.h>
#include <stdlib.h>

void soma_vetores(int vet1[], int vet2[], int resultado[], int n) {
    for (int i = 0; i < n; i++) {
        resultado[i] = vet1[i] + vet2[i];
    }
}

int main() {
    int n;
    
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    int *vet1 = (int *)malloc(n * sizeof(int));
    int *vet2 = (int *)malloc(n * sizeof(int));
    int *resultado = (int *)malloc(n * sizeof(int));

    printf("Digite os elementos do primeiro vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet1[i]);
    }

    printf("Digite os elementos do segundo vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet2[i]);
    }

    soma_vetores(vet1, vet2, resultado, n);

    printf("O vetor de soma dos elementos correspondentes é:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    free(vet1);
    free(vet2);
    free(resultado);

    return 0;
}
