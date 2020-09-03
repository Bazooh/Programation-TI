
#ifndef PROJETS_STRUCT_H
#define PROJETS_STRUCT_H

# include <stdint.h>

# include "coreDefine.h"

typedef struct s_pos {
    int8_t x;
    int8_t y;
}              t_pos;


typedef struct s_piece {
    t_pos rotation_pos[NUMBER_OF_ROTATION][SIZE_OF_PIECE];
    t_pos pos;
    uint8_t color;
    uint8_t rotation_state;
}              t_piece;

#endif //PROJETS_STRUCT_H
