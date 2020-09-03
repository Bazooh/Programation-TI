
#include "main.h"

void moveCursor(uint8_t *cursor_x, uint8_t *cursor_y) {
    if (*cursor_x < MATRIX_LENGTH - 1) {
        (*cursor_x)++;
    } else {
        *cursor_x = 0;
        if (*cursor_y < MATRIX_LENGTH - 1) {
            (*cursor_y)++;
        } else {
            *cursor_y = 0;
        }
    }
}

uint8_t placeNumber(uint8_t matrix[MATRIX_LENGTH][MATRIX_LENGTH], uint8_t *availableCase) {
    uint32_t randomNumber;
    uint8_t cursor_x;
    uint8_t cursor_y;

    if (!(*availableCase)) { return 0; }

    cursor_x = 0;
    cursor_y = 0;
    randomNumber = random() % *availableCase;
    while (randomNumber) {
        while (matrix[cursor_y][cursor_x]) {
            moveCursor(&cursor_x, &cursor_y);
        }
        moveCursor(&cursor_x, &cursor_y);
        randomNumber--;
    }
    while (matrix[cursor_y][cursor_x]) {
        moveCursor(&cursor_x, &cursor_y);
    }

    matrix[cursor_y][cursor_x] = (random() % 2) + 1;
    (*availableCase)--;

    return 1;
}

void initMatrix(uint8_t matrix[MATRIX_LENGTH][MATRIX_LENGTH]) {
    uint8_t i;
    uint8_t j;

    srandom(rtc_Time());

    for (i = 0; i < MATRIX_LENGTH; i++) {
        for (j = 0; j < MATRIX_LENGTH; j++) {
            matrix[i][j] = 0;
        }
    }
}

void defLine(uint8_t matrix[MATRIX_LENGTH][MATRIX_LENGTH], uint8_t *line, uint8_t direction, uint8_t number) {
    int8_t i;

    switch (direction) {
        case 1:
            for (i = 0; i < MATRIX_LENGTH; i++) {
                line[i] = matrix[number][i];
            }
            break;
        case 2:
            for (i = MATRIX_LENGTH - 1; i >= 0; i--) {
                line[MATRIX_LENGTH - i - 1] = matrix[i][number];
            }
            break;
        case 3:
            for (i = MATRIX_LENGTH - 1; i >= 0; i--) {
                line[MATRIX_LENGTH - i - 1] = matrix[number][i];
            }
            break;
        case 4:
            for (i = 0; i < MATRIX_LENGTH; i++) {
                line[i] = matrix[i][number];
            }
            break;
    }
}

void replaceLine(uint8_t matrix[MATRIX_LENGTH][MATRIX_LENGTH], uint8_t *line, uint8_t direction, uint8_t number) {
    int8_t i;

    switch (direction) {
        case 1:
            for (i = 0; i < MATRIX_LENGTH; i++) {
                matrix[number][i] = line[i];
            }
            break;
        case 2:
            for (i = MATRIX_LENGTH - 1; i >= 0; i--) {
                matrix[i][number] = line[MATRIX_LENGTH - i - 1];
            }
            break;
        case 3:
            for (i = MATRIX_LENGTH - 1; i >= 0; i--) {
                matrix[number][i] = line[MATRIX_LENGTH - i - 1];
            }
            break;
        case 4:
            for (i = 0; i < MATRIX_LENGTH; i++) {
                matrix[i][number] = line[i];
            }
            break;
    }
}

void initFusion(uint8_t *fusion) {
    uint8_t i;

    for (i = 0; i < MATRIX_LENGTH; i++) {
        fusion[i] = 0;
    }
}

uint8_t moveLine(uint8_t *line, uint8_t *availableCase) {
    int8_t i;
    uint8_t checkingCase;
    uint8_t fusion[MATRIX_LENGTH];
    uint8_t move;

    move = 0;
    initFusion(fusion);

    for (i = MATRIX_LENGTH - 2; i >= 0; i--) {
        checkingCase = i;
        if (line[checkingCase]) {
            while (checkingCase < MATRIX_LENGTH - 1 && (!line[checkingCase + 1] || (line[checkingCase] == line[checkingCase + 1] && !fusion[checkingCase + 1] && !fusion[checkingCase]))) {
                if (line[checkingCase + 1]) {
                    line[checkingCase + 1]++;
                    (*availableCase)++;
                    fusion[checkingCase + 1] = 1;
                } else {
                    line[checkingCase + 1] = line[checkingCase];
                }
                line[checkingCase] = 0;
                checkingCase++;
                move = 1;
            }
        }
    }
    return move;
}

uint8_t move(uint8_t matrix[MATRIX_LENGTH][MATRIX_LENGTH], uint8_t *availableCase, uint8_t direction) {
    uint8_t line[MATRIX_LENGTH];
    uint8_t i;
    uint8_t move;

    move = 0;

    for (i = 0; i < MATRIX_LENGTH; i++) {
        defLine(matrix, line, direction, i);
        move += moveLine(line, availableCase);
        replaceLine(matrix, line, direction, i);
    }
    return move;
}

void play() {
    uint8_t direction;
    uint8_t matrix[MATRIX_LENGTH][MATRIX_LENGTH];
    uint8_t availableCase;

    availableCase = MATRIX_LENGTH * MATRIX_LENGTH;
    initMatrix(matrix);
    placeNumber(matrix, &availableCase);
    printScreen(matrix);

    while (1) {
        direction = 0;

        kb_Scan();

        if (kb_Data[1] & kb_Del) { return; }

        if (kb_Data[7] & kb_Right) {
            direction = 1;
        } else if (kb_Data[7] & kb_Up) {
            direction = 2;
        } else if (kb_Data[7] & kb_Left) {
            direction = 3;
        } else if (kb_Data[7] & kb_Down) {
            direction = 4;
        }

        if (direction) {
            if (move(matrix, &availableCase, direction)) {
                printScreen(matrix);
                delay(50);
                if (!placeNumber(matrix, &availableCase)) { return; }
                printScreen(matrix);
                delay(150);
            }
        }
    }
}

void menu() {
    play();
}

int main() {
    gfx_Begin();
    gfx_SetPalette(gfx_pal, sizeof_gfx_pal, 0);
    gfx_FillScreen(2);

    menu();

    kb_Reset();
    gfx_End();
    return (0);
}