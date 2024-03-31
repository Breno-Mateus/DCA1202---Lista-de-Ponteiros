#include <stdio.h>

// Função para enviar o estado da matriz via porta serial
void send(unsigned long estado) {
    // Simulação da função de envio via porta serial
    printf("Estado enviado via porta serial: %llu\n", estado);
}

int main() {
    // Matriz de leds
    unsigned char m[8][8] = {
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1}
    };

    // Variável para armazenar o estado da matriz de leds
    unsigned long estado = 0;

    // Codificação da matriz m na variável de 64 bits
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // Deslocamento dos bits e atribuição do estado do led na variável de 64 bits
            estado |= ((unsigned long)m[i][j] << ((i * 8) + j));
        }
    }

    // Envio do estado da matriz via porta serial
    send(estado);

    return 0;
}
