
#ifndef INC_2048_DISPLAY_H
#define INC_2048_DISPLAY_H

# include <graphx.h>
# include <stdint.h>

# include "info.h"
# include "case.h"
# include "board.h"

# define CASE_X_SPACE 4
# define CASE_Y_SPACE 4

void printScreen(uint8_t matrix[MATRIX_LENGTH][MATRIX_LENGTH]);

typedef struct s_case {
    uint8_t color;
    uint8_t number;
}              t_case;

#endif //INC_2048_DISPLAY_H
