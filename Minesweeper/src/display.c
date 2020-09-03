
#include "minesweeper.h"

const gfx_sprite_t* SPRITE_NEAR_BOMB[MAX_NEAR_BOMB] = {
        SPRITE_CASE_0,
        SPRITE_CASE_1,
        SPRITE_CASE_2,
        SPRITE_CASE_3,
        SPRITE_CASE_4,
        SPRITE_CASE_5,
        SPRITE_CASE_6,
        SPRITE_CASE_7,
        SPRITE_CASE_8,
};


void printCase(t_case matrix[MAP_X_MAX][MAP_Y_MAX], int8_t x, int8_t y) {
    gfx_Sprite_NoClip(
            getCase(matrix, x, y),
            CASE_OUTER_WIDTH * (int32_t)x + MARGE,
            CASE_OUTER_HEIGHT * (int32_t)y + HUD_HEIGHT);
}

void printScreen(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos cursor) {
    int8_t i;
    int8_t j;
    for(j = 0; j < MAP_Y_MAX; j++) {
        for(i = 0; i < MAP_X_MAX; i++) {
            printCase(matrix, i, j);
        }
    }
    printCursor(cursor);
}

void printCursor(t_pos cursor) {
    gfx_TransparentSprite(
            SPRITE_CURSOR,
            CASE_OUTER_WIDTH * (int32_t)cursor.x + MARGE,
            CASE_OUTER_HEIGHT * (int32_t)cursor.y + HUD_HEIGHT);
}

void deleteCursor(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos cursor) {
    printCase(matrix, cursor.x, cursor.y);
}

gfx_sprite_t *returnValue(uint8_t value, uint8_t bomb) {

    if (bomb)
        return SPRITE_BOMB;
    return SPRITE_NEAR_BOMB[value];

}

gfx_sprite_t *getCase(t_case matrix[MAP_X_MAX][MAP_Y_MAX], int8_t x, int8_t y) {
    t_case  value = matrix[x][y];

    if (value.visible)
        return returnValue(value.value, value.bomb);
    if (value.flag)
        return SPRITE_FLAG;
    return SPRITE_HIDDEN_CASE;

}
