#include <stdio.h>

#define ROWS 10
#define COLS 10
#define SHIP_SIZE 3

/* Função que inicializa o tabuleiro com zeros (água) */
void init_board(int board[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            board[r][c] = 0;
        }
    }
}

/* Verifica se um navio horizontal cabe no tabuleiro a partir de (r, c) */
int can_place_horizontal(int board[ROWS][COLS], int r, int c) {
    if (r < 0 || r >= ROWS) return 0;
    if (c < 0 || c + SHIP_SIZE - 1 >= COLS) return 0;

    /* checar sobreposição simplificada: se alguma posição já não for 0, não pode colocar */
    for (int i = 0; i < SHIP_SIZE; i++) {
        if (board[r][c + i] != 0) return 0;
    }
    return 1;
}

/* Verifica se um navio vertical cabe no tabuleiro a partir de (r, c) */
int can_place_vertical(int board[ROWS][COLS], int r, int c) {
    if (c < 0 || c >= COLS) return 0;
    if (r < 0 || r + SHIP_SIZE - 1 >= ROWS) return 0;

    for (int i = 0; i < SHIP_SIZE; i++) {
        if (board[r + i][c] != 0) return 0;
    }
    return 1;
}

/* Coloca um navio horizontal no tabuleiro com valor '3' (assume que já checou can_place_horizontal) */
void place_horizontal(int board[ROWS][COLS], int r, int c) {
    for (int i = 0; i < SHIP_SIZE; i++) {
        board[r][c + i] = 3;
    }
}

/* Coloca um navio vertical no tabuleiro com valor '3' (assume que já checou can_place_vertical) */
void place_vertical(int board[ROWS][COLS], int r, int c) {
    for (int i = 0; i < SHIP_SIZE; i++) {
        board[r + i][c] = 3;
    }
}

/* Imprime o tabuleiro de forma organizada */
void print_board(int board[ROWS][COLS]) {
    printf("   "); /* espaçamento para índices de coluna */
    for (int c = 0; c < COLS; c++) {
        printf("%2d ", c);
    }
    printf("\n");

    for (int r = 0; r < ROWS; r++) {
        printf("%2d ", r); /* índice da linha */
        for (int c = 0; c < COLS; c++) {
            printf("%2d ", board[r][c]);
        }
        printf("\n");
    }
}

int main(void) {
    int board[ROWS][COLS];
    init_board(board);

    /* 
       Coordenadas definidas diretamente no código (requisito simplificado).
       Use (linha, coluna), índices começando em 0 até 9.
       
       Altere essas coordenadas para testar diferentes posições.
    */

    /* Navio horizontal (linha, coluna inicial) */
    int h_row = 2;
    int h_col = 4;

    /* Navio vertical (linha, coluna inicial) */
    int v_row = 5;
    int v_col = 1;

    /* Validação e posicionamento do navio horizontal */
    if (!can_place_horizontal(board, h_row, h_col)) {
        printf("Erro: não é possível posicionar o navio horizontal em (%d, %d).\n", h_row, h_col);
        printf("Verifique limites ou sobreposição.\n");
        return 1;
    }
    place_horizontal(board, h_row, h_col);

    /* Validação e posicionamento do navio vertical */
    if (!can_place_vertical(board, v_row, v_col)) {
        printf("Erro: não é possível posicionar o navio vertical em (%d, %d).\n", v_row, v_col);
        printf("Verifique limites ou sobreposição.\n");
        return 1;
    }
    place_vertical(board, v_row, v_col);

    /* Exibe o tabuleiro final */
    printf("Tabuleiro com navios posicionados (0 = água, 3 = navio):\n");
    print_board(board);

    return 0;
}