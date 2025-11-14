#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Aventureiro – Tabuleiro 10x10 e navios diagonais

int main() {

    // ---------- NIVEL AVENTUREIRO ----------

    // Tabuleiro 10x10
    int tabuleiro[10][10];

    // Inicializando o tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int tamanhoNavio = 3;

    // 🔹 NAVIO 1 – HORIZONTAL (tamanho 3)
    int hLinha = 1;
    int hColuna = 2;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[hLinha][hColuna + i] = 3;
    }

    // 🔹 NAVIO 2 – VERTICAL (tamanho 3)
    int vLinha = 4;
    int vColuna = 7;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[vLinha + i][vColuna] = 3;
    }

    // 🔹 NAVIO 3 – DIAGONAL ↘ (descendo para a direita)
    int d1Linha = 6;
    int d1Coluna = 1;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[d1Linha + i][d1Coluna + i] = 3;
    }

    // 🔹 NAVIO 4 – DIAGONAL ↙ (descendo para a esquerda)
    int d2Linha = 2;
    int d2Coluna = 8;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[d2Linha + i][d2Coluna - i] = 3;
    }

    // ---------- EXIBIÇÃO DO TABULEIRO ----------
    printf("Tabuleiro 10x10 - Nivel Aventureiro:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}