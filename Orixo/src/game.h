
#ifndef PROJETS_POS_H
#define PROJETS_POS_H

# include <stdint.h>

# define MATRIX_X_MAX 30
# define MATRIX_Y_MAX 20

# define EASY 0
# define NORMAL 1
# define HARD 2
# define CUSTOMIZE 3

# define NUMBER_OF_CATEGORY 5
# define NUMBER_OF_DIFFICULTY 4

typedef struct s_pos {
    int16_t x;
    int16_t y;
}              t_pos;

typedef struct s_cursor {
    t_pos pos;
    uint8_t state;
}              t_cursor;

typedef struct s_case {
    int8_t number;
    int8_t old_number;
    uint8_t id;
}              t_case;

typedef struct s_game {
    uint8_t x_max;
    uint8_t y_max;
    t_case matrix[MATRIX_X_MAX][MATRIX_Y_MAX];
    uint8_t number_max;
    uint8_t amount_number;
    uint8_t win;
    t_cursor cursor;
}              t_game;

extern uint8_t MENU[NUMBER_OF_DIFFICULTY][NUMBER_OF_CATEGORY];

#endif //PROJETS_POS_H