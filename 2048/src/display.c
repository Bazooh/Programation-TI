
#include "display.h"

const gfx_sprite_t* SPRITE_CASE[MAX_VALUE] = {
        SPRITE_EMPTY,
        SPRITE_2,
        SPRITE_4,
        SPRITE_8,
        SPRITE_16,
        SPRITE_32,
        SPRITE_64,
        SPRITE_128,
        SPRITE_256,
        SPRITE_512,
        SPRITE_1024,
        SPRITE_2048,
        SPRITE_4096,
        SPRITE_8192,
};

void printCase(uint8_t x, uint8_t y, uint8_t value) {
    gfx_TransparentSprite_NoClip(
            SPRITE_CASE[value],
            (CASE_WIDTH + CASE_X_SPACE) * (int24_t)x + MARGE_X,
            (CASE_HEIGHT + CASE_Y_SPACE) * (int8_t)y + MARGE_Y);
}

void printScreen(uint8_t matrix[MATRIX_LENGTH][MATRIX_LENGTH]) {
    uint8_t i;
    uint8_t j;

    for (i = 0; i < MATRIX_LENGTH; i++) {
        for (j = 0; j < MATRIX_LENGTH; j++) {
            printCase(j, i, matrix[i][j]);
        }
    }
}