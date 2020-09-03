//
// Created by Bazooh on 16/11/2019.
//

#ifndef DISPLAY_H
#define DISPLAY_H

#define MAX_NEAR_BOMB 9

void            printCase(t_case matrix[MAP_X_MAX][MAP_Y_MAX], int8_t x, int8_t y);
void            printScreen(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos cursor);
void            printCursor(t_pos cursor);
void            deleteCursor(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos cursor);
gfx_sprite_t*   returnValue(uint8_t value, uint8_t bomb);
gfx_sprite_t*   getCase(t_case matrix[MAP_X_MAX][MAP_Y_MAX], int8_t x, int8_t y);

#endif //DISPLAY_H
