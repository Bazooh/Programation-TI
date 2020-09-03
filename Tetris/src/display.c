
#include "display.h"
#include <string.h>

gfx_sprite_t* initPrintBlock(uint8_t color) {
    uint16_t i;
    uint8_t sprite_case[CASE_SIZE];

    sprite_case[0] = CASE_X_LENGTH;
    sprite_case[1] = CASE_Y_LENGTH;
    for (i = 2; i < CASE_SIZE; i++) {
        sprite_case[i] = color;
    }
    for (i = 2; i < CASE_X_LENGTH ; i++) {
        sprite_case[i] = color - 1;
    }
    for (i = CASE_X_LENGTH + 2; i < CASE_SIZE - CASE_X_LENGTH; i += CASE_X_LENGTH) {
        sprite_case[i] = color - 1;
    }
    for (i = CASE_X_LENGTH + 3; i < (CASE_X_LENGTH * 2) + 1; i++) {
        sprite_case[i] = WHITE;
    }
    for (i = (CASE_X_LENGTH * 2) + 3; i < (CASE_X_LENGTH * 2) + 5; i++) {
        sprite_case[i] = WHITE;
    }
    for (i = (CASE_X_LENGTH * 2) + 1; i < CASE_SIZE; i += CASE_X_LENGTH) {
        sprite_case[i] = color + 1;
    }
    for (i = CASE_SIZE - CASE_X_LENGTH; i < CASE_SIZE; i++) {
        sprite_case[i] = color + 1;
    }

     //                                 color - 1, color - 1, color - 1, color - 1, color - 1, color - 1, color - 1, color - 1, color - 1, color - 1,
     //                                 color - 1,     WHITE,     WHITE,     WHITE,     WHITE,     WHITE,     WHITE,     WHITE,     WHITE, color + 1,
     //                                 color - 1,     WHITE,     WHITE,     color,     color,     color,     color,     color,     color, color + 1,
     //                                 color - 1,     color,     color,     color,     color,     color,     color,     color,     color, color + 1,
     //                                 color - 1,     color,     color,     color,     color,     color,     color,     color,     color, color + 1,
     //                                 color - 1,     color,     color,     color,     color,     color,     color,     color,     color, color + 1,
     //                                 color - 1,     color,     color,     color,     color,     color,     color,     color,     color, color + 1,
     //                                 color - 1,     color,     color,     color,     color,     color,     color,     color,     color, color + 1,
     //                                 color - 1,     color,     color,     color,     color,     color,     color,     color,     color, color + 1,
     //                                 color + 1, color + 1, color + 1, color + 1, color + 1, color + 1, color + 1, color + 1, color + 1, color + 1,

    return (gfx_sprite_t*)sprite_case;
}

void printScreen(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH]) {
    uint8_t i;
    uint8_t j;

    for (i = 0; i < MATRIX_Y_LENGTH; i++) {
        for (j = 0; j < MATRIX_X_LENGTH; j++) {
            printBlock((uint24_t)j, (uint8_t)i, matrix[i][j]);
        }
    }
}

void printPause() {
    uint24_t marge_x_pause;
    uint8_t marge_y_pause;

    marge_x_pause = MARGE_X_PAUSE;
    marge_y_pause = MARGE_Y_PAUSE;

    gfx_SetTextFGColor(BRIGHT_WHITE);
    gfx_PrintStringXY("game paused", marge_x_pause, marge_y_pause);
}

void clearPause() {
    uint24_t marge_x_pause;
    uint8_t marge_y_pause;
    uint8_t char_length;
    uint8_t pause_length;

    marge_x_pause = MARGE_X_PAUSE;
    marge_y_pause = MARGE_Y_PAUSE;
    char_length = CHAR_LENGTH;
    pause_length = PAUSE_LENGTH;

    gfx_SetColor(BLACK);
    gfx_FillRectangle(marge_x_pause, marge_y_pause, pause_length * char_length, char_length);
}

void printGameOver() {
    uint24_t marge_x_pause;
    uint8_t marge_y_pause;

    marge_x_pause = MARGE_X_PAUSE;
    marge_y_pause = MARGE_Y_PAUSE;

    gfx_SetTextFGColor(BRIGHT_WHITE);
    gfx_PrintStringXY("game over", marge_x_pause, marge_y_pause);
}

void printPiece(t_piece piece) {
    uint8_t i;
    t_pos piece_pos;

    for (i = 0; i < SIZE_OF_PIECE; i++) {
        piece_pos.x = piece.pos.x + piece.rotation_pos[piece.rotation_state][i].x;
        piece_pos.y = piece.pos.y + piece.rotation_pos[piece.rotation_state][i].y;
        if (piece_pos.y >= 0 && piece_pos.y < MATRIX_Y_LENGTH) {
            printBlock((uint24_t)piece_pos.x, (uint8_t)piece_pos.y, piece.color);
        }
    }
}

void printBlock(uint24_t x, uint8_t y, uint8_t color) {
    gfx_Sprite_NoClip(
            initPrintBlock(color),
            (CASE_X_LENGTH * x) + MARGE_X,
            (CASE_Y_LENGTH * y) + MARGE_Y);
}

void clearPiece(t_piece piece) {
    uint8_t i;
    t_pos piece_pos;

    for (i = 0; i < SIZE_OF_PIECE; i++) {
        piece_pos.x = piece.pos.x + piece.rotation_pos[piece.rotation_state][i].x;
        piece_pos.y = piece.pos.y + piece.rotation_pos[piece.rotation_state][i].y;
        if (piece_pos.y >= 0 && piece_pos.y < MATRIX_Y_LENGTH) {
            printBlock((uint24_t)piece_pos.x, (uint8_t)piece_pos.y, WHITE);
        }
    }
}

void printDifficulty(uint8_t difficulty) {
    uint24_t marge_x_difficulty;
    uint8_t marge_y_difficulty;
    uint8_t char_length;
    uint8_t difficulty_length;

    marge_x_difficulty = MARGE_X_DIFFICULTY;
    marge_y_difficulty = MARGE_Y_DIFFICULTY;
    char_length = CHAR_LENGTH;
    difficulty_length = DIFFICULTY_LENGTH;

    gfx_SetColor(BRIGHT_WHITE);
    gfx_FillRectangle(marge_x_difficulty, marge_y_difficulty, difficulty_length * char_length, char_length);

    gfx_SetTextFGColor(BLACK);
    gfx_PrintStringXY("difficulty :", marge_x_difficulty - (char_length * 10) - 2, marge_y_difficulty);
    switch (difficulty) {
        case 0 :
            gfx_PrintStringXY(" Easy ", marge_x_difficulty, marge_y_difficulty);
            break;
        case 1 :
            gfx_PrintStringXY("Normal", marge_x_difficulty, marge_y_difficulty);
            break;
        case 2 :
            gfx_PrintStringXY(" Hard ", marge_x_difficulty, marge_y_difficulty);
            break;
    }
}

void printScore(uint32_t score) {
    uint8_t score_length;
    uint24_t marge_x_score;
    uint8_t marge_y_score;
    uint8_t char_length;

    score_length = SCORE_LENGTH;
    marge_x_score = MARGE_X_SCORE;
    marge_y_score = MARGE_Y_SCORE;
    char_length = CHAR_LENGTH;

    gfx_SetColor(BLACK);
    gfx_FillRectangle(marge_x_score, marge_y_score, score_length * char_length, char_length);

    gfx_SetTextFGColor (WHITE);
    gfx_PrintStringXY("score :", marge_x_score - (char_length * 6) - 2, marge_y_score);
    gfx_SetTextXY(marge_x_score, marge_y_score);
    gfx_PrintUInt(score, score_length);
}

void printNextPiece(t_piece next_piece) {
    uint8_t i;
    uint8_t j;
    uint24_t x;
    uint8_t y;

    for (i = 0; i < SIZE_OF_PIECE + 2; i++) {
        for (j = 0; j < SIZE_OF_PIECE + 2; j++) {
            x = (CASE_X_LENGTH * (i - 1)) + MARGE_X_NEXT_PIECE;
            y = (CASE_Y_LENGTH * (j - 1)) + MARGE_Y_NEXT_PIECE;
            gfx_Sprite_NoClip(initPrintBlock(WHITE), x, y);
        }
    }
    for (i = 0; i < SIZE_OF_PIECE; i++) {
        x = (CASE_X_LENGTH * next_piece.rotation_pos[0][i].x) + MARGE_X_NEXT_PIECE;
        y = (CASE_Y_LENGTH * next_piece.rotation_pos[0][i].y) + MARGE_Y_NEXT_PIECE;
        gfx_Sprite_NoClip(initPrintBlock(next_piece.color), x, y);
    }
}
