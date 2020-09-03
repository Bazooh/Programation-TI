
#include "display.h"

uint16_t gfx_pal[PAL_LENGTH] = {
        gfx_RGBTo1555(  0,   0,   0),     // transparent
        gfx_RGBTo1555(250, 250, 250),     // white
        gfx_RGBTo1555(200, 200, 200),     // grey
        gfx_RGBTo1555( 50,  50,  50),     // dark_grey
        gfx_RGBTo1555(250,  50,  50),     // red
        gfx_RGBTo1555(250, 250,  50),     // yellow
        gfx_RGBTo1555(255, 255, 204),     // beige
        gfx_RGBTo1555( 42,   0, 128),     // mauve
};

gfx_sprite_t* matrixCase(int8_t matrix_case) {
    switch (matrix_case) {
        case KING_WHITE:
            return SPRITE_KING_WHITE;
        case PION_WHITE:
            return SPRITE_PION_WHITE;
        case KING_BLACK:
            return SPRITE_KING_BLACK;
        case PION_BLACK:
            return SPRITE_PION_BLACK;
    }
    return NULL;
}

void printCase(MATRIX, uint24_t x, uint8_t y) {
    gfx_TransparentSprite_NoClip(
        SPRITE_EMPTY,
        CASE_X_LENGTH * x + MARGE_X,
        CASE_Y_LENGTH * y + MARGE_Y);
    if (matrix[x][y]) {
        gfx_TransparentSprite_NoClip(
            matrixCase(matrix[x][y]),
            CASE_X_LENGTH * x + MARGE_X,
            CASE_Y_LENGTH * y + MARGE_Y);
    }
}

void eraseCursor(MATRIX, t_pos cursor) {
    printCase(matrix, cursor.x, cursor.y);
}

void printCursor(t_pos cursor) {
    gfx_TransparentSprite_NoClip(
        SPRITE_CURSOR,
        CASE_X_LENGTH * (uint24_t)(cursor.x) + MARGE_X,
        CASE_Y_LENGTH * (cursor.y) + MARGE_Y);
}

void printCardCase(uint8_t full, uint24_t x, uint8_t y, uint24_t marge_x, uint8_t marge_y) {
    if (full) {
        gfx_TransparentSprite_NoClip(
        SPRITE_CARD_CASE_FULL,
        (CARD_CASE_X_LENGTH + 2)*x + marge_x,
        (CARD_CASE_Y_LENGTH + 2)*y + marge_y);
    } else {
        gfx_TransparentSprite_NoClip(
        SPRITE_CARD_CASE_EMPTY,
        (CARD_CASE_X_LENGTH + 2)*x + marge_x,
        (CARD_CASE_Y_LENGTH + 2)*y + marge_y);
    }
}

void printCard(CARD, uint24_t marge_x, uint8_t marge_y) {
    uint8_t i;
    uint8_t j;

    gfx_TransparentSprite_NoClip(
        SPRITE_CARD,
        marge_x - 4,
        marge_y - 4);

    for (i = 0; i < MATRIX_X_LENGTH; ++i) {
        for (j = 0; j < MATRIX_Y_LENGTH; ++j) {
            printCardCase(card[i][j], i, j, marge_x, marge_y);
        }
    }
    
    gfx_TransparentSprite_NoClip(
        SPRITE_CARD_CASE_MIDDLE,
        (CARD_CASE_X_LENGTH + 2)*2 + marge_x,
        (CARD_CASE_Y_LENGTH + 2)*2 + marge_y);
}

void printMovement(MATRIX, t_pos *movement, uint8_t number_of_movement) {
    uint8_t i;

    for (i = 1; i < number_of_movement + 1; ++i) {
        if (matrix[movement[i].x][movement[i].y]) {
            gfx_TransparentSprite_NoClip(
                SPRITE_MOVEMENT_TOUCH,
                CASE_X_LENGTH * (uint24_t)(movement[i].x) + MARGE_X,
                CASE_Y_LENGTH * (uint8_t)(movement[i].y) + MARGE_Y);
        } else {
            gfx_TransparentSprite_NoClip(
                SPRITE_MOVEMENT,
                CASE_X_LENGTH * (uint24_t)(movement[i].x) + MARGE_X,
                CASE_Y_LENGTH * (uint8_t)(movement[i].y) + MARGE_Y);
        }
    }
}

void eraseMovement(MATRIX, t_pos *movement, uint8_t number_of_movement) {
    uint8_t i;

    for (i = 1; i < number_of_movement + 1; ++i) {
        printCase(matrix, movement[i].x, movement[i].y);
    }
}

void printDeck(t_game game) {
    t_card enemy_card[2];

    copyCard(enemy_card[0].value, game.player[!(game.player_turn)].card[0].value);
    copyCard(enemy_card[1].value, game.player[!(game.player_turn)].card[1].value);

    reverseMatrix(enemy_card[0].value);
    reverseMatrix(enemy_card[1].value);

    printCard(game.player[game.player_turn].card[0].value, 114, 197);
    printCard(game.player[game.player_turn].card[1].value, 165, 197);
    printCard(game.side_card.value, 250, 107);
    printCard(enemy_card[0].value, 114, 13);
    printCard(enemy_card[1].value, 165, 13);
}

void printMatrix(MATRIX) {
    uint8_t i;
    uint8_t j;

    for (i = 0; i < MATRIX_X_LENGTH; ++i) {
        for (j = 0; j < MATRIX_Y_LENGTH; ++j) {
            printCase(matrix, i, j);
        }
    }
}