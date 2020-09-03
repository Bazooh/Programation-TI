//
// Created by Bazooh on 16/11/2019.
//

#ifndef MAP_H
#define MAP_H

#include "minesweeper.h"

#define MAP_X_MAX 31
#define MAP_Y_MAX 21

typedef struct      s_pos {
    int8_t          x;
    int8_t          y;
}                   t_pos;

typedef struct      s_case {
    uint8_t         visible : 1;
    uint8_t         flag    : 1;
    uint8_t         bomb    : 1;
    uint8_t         value   : 4;

}                   t_case;

#endif //MAP_H
