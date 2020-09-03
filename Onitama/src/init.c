
#include "init.h"

uint8_t isInTab(uint8_t *tab, uint8_t length, uint8_t value) {
    uint8_t i;

    for (i = 0; i < length; ++i) {
        if (tab[i] == value) { return TRUE; }
    }
    return FALSE;
}

void initCursor(t_pos *cursor) {
    cursor->x = 2;
    cursor->y = 4;
}

void initCard(CARD, uint8_t card_number) {
    uint8_t i;
    uint8_t j;

    for (i = 0; i < MATRIX_X_LENGTH; ++i) {
        for (j = 0; j < MATRIX_Y_LENGTH; ++j) {
            card[i][j] = CARDS[card_number][j][i];
        }
    }
}

void initRandom(uint8_t *random_tab) {
    uint8_t i;

    for (i = 0; i < NUMBER_OF_CARD; ++i) {
        random_tab[i] = 0;
    }
}

void initDeck(t_game *game) {
    uint8_t random_tab[NUMBER_OF_CARD];
    uint8_t i;

    initRandom(random_tab);

    random_tab[0] = random() % NUMBER_OF_CARD_TOTAL;

    for (i = 1; i < NUMBER_OF_CARD; ++i) {
        do {
            random_tab[i] = random() % NUMBER_OF_CARD_TOTAL;
        } while (isInTab(random_tab, i, random_tab[i]));
    }

    initCard(game->player[0].card[0].value, random_tab[0]);
    initCard(game->player[0].card[1].value, random_tab[1]);
    initCard(game->side_card.value, random_tab[2]);
    initCard(game->player[1].card[0].value, random_tab[3]);
    initCard(game->player[1].card[1].value, random_tab[4]);
}

void initMatrix(MATRIX) {
    uint8_t i;
    uint8_t j;

    j = 0;

    for (i = 0; i < MATRIX_X_LENGTH; ++i) {
        matrix[i][j] = PION_BLACK;
    }
    matrix[2][0] = KING_BLACK;

    for (j = 1; j < MATRIX_Y_LENGTH - 1; ++j) {
        for (i = 0; i < MATRIX_X_LENGTH; ++i) {
            matrix[i][j] = EMPTY;
        }
    }

    for (i = 0; i < MATRIX_X_LENGTH; ++i) {
        matrix[i][j] = PION_WHITE;
    }
    matrix[2][4] = KING_WHITE;
}