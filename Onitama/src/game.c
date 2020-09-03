
#include "game.h"

void reverseMatrix(MATRIX) {
    int8_t matrix_copy[MATRIX_X_LENGTH][MATRIX_Y_LENGTH];
    uint8_t i;
    uint8_t j;

    for (i = 0; i < MATRIX_X_LENGTH; ++i) {
        for (j = 0; j < MATRIX_Y_LENGTH; ++j) {
            matrix_copy[i][j] = matrix[i][j];
        }
    }
    for (i = 0; i < MATRIX_X_LENGTH; ++i) {
        for (j = 0; j < MATRIX_Y_LENGTH; ++j) {
            matrix[i][j] = matrix_copy[MATRIX_X_LENGTH - i - 1][MATRIX_Y_LENGTH - j - 1];
        }
    }
}

void copyCard(CARD, int8_t card_to_copy[MATRIX_X_LENGTH][MATRIX_Y_LENGTH]) {
    uint8_t i;
    uint8_t j;

    for (i = 0; i < MATRIX_X_LENGTH; ++i) {
        for (j = 0; j < MATRIX_Y_LENGTH; ++j) {
            card[i][j] = card_to_copy[i][j];
        }
    }
}