
#ifndef SRC_GAME_H
#define SRC_GAME_H

# include <stdint.h>

# define TRUE 1
# define FALSE 0

# define WHITE 0
# define BLACK 1

# define MATRIX_X_LENGTH 5
# define MATRIX_Y_LENGTH 5

# define NUMBER_OF_MOVEMENT_MAX 5

# define MATRIX int8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH]
# define CARD int8_t card[MATRIX_X_LENGTH][MATRIX_Y_LENGTH]
# define MOVEMENT t_pos movement[NUMBER_OF_MOVEMENT_MAX]

# define NUMBER_OF_CARD_IN_HAND 2
# define NUMBER_OF_CARD 5
# define NUMBER_OF_CARD_TOTAL 14

# define EMPTY 0
# define PION_WHITE 1
# define KING_WHITE 2
# define PION_BLACK -1
# define KING_BLACK -2

# define WAITING_DELAY 100

typedef struct s_pos {
    uint8_t x;
    uint8_t y;
}              t_pos;

typedef struct s_card {
    int8_t value[MATRIX_X_LENGTH][MATRIX_Y_LENGTH];
}              t_card;

typedef struct s_player {
    t_card card[NUMBER_OF_CARD_IN_HAND];
}              t_player;

typedef struct s_game {
    MATRIX;
    uint8_t card_id;
    MOVEMENT;
    t_card side_card;
    t_pos cursor;
    uint8_t number_of_movement;
    int8_t player_turn;
    t_player player[2];
    uint8_t win;
}              t_game;

void reverseMatrix(MATRIX);
void copyCard(CARD, int8_t card_to_copy[MATRIX_X_LENGTH][MATRIX_Y_LENGTH]);

#endif //SRC_GAME_H