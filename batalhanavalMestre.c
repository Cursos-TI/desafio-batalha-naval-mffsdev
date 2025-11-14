#include <stdio.h>

// Nível Mestre – Habilidades Especiais (Cone, Cruz, Octaedro)
// Cada habilidade é representada por uma matriz própria usando 1 para área atingida e 0 para área vazia.

int main() {

    // ---------------------- HABILIDADE: CONE ----------------------
    // Formato:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    int cone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    // ---------------------- HABILIDADE: OCTAEDRO ----------------------
    // Formato:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    int octaedro[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // ---------------------- HABILIDADE: CRUZ ----------------------
    // Formato:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    int cruz[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };

    // ---------------------- EXIBIÇÃO DAS HABILIDADES ----------------------

    printf("===== HABILIDADE: CONE =====\n\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }

    printf("\n===== HABILIDADE: OCTAEDRO =====\n\n");