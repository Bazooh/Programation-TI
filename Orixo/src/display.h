
#ifndef PROJETS_DISPLAY_H
#define PROJETS_DISPLAY_H

# include <stdint.h>
# include <graphx.h>

# include "game.h"

# define MARGE_X 20
# define MARGE_Y 25

# define CASE_X_LENGTH 9
# define CASE_Y_LENGTH 9
# define CASE_SIZE (CASE_X_LENGTH * CASE_Y_LENGTH + 2)

# define CHAR_LENGTH 8

# define WHITE 1
# define LIGHT_GREY 2
# define GREY 3
# define BLACK 4
# define RED 5
# define GREEN 6
# define BLUE 7
# define MAGENTA 8
# define DARK_RED 9

# define SPRITE_CASE_BLOCKED (gfx_sprite_t*)sprite_case_blocked
# define SPRITE_CASE_USED (gfx_sprite_t*)sprite_case_used
# define SPRITE_CASE_EMPTY (gfx_sprite_t*)sprite_case_empty
# define SPRITE_CASE_1 (gfx_sprite_t*)sprite_case_1
# define SPRITE_CASE_2 (gfx_sprite_t*)sprite_case_2
# define SPRITE_CASE_3 (gfx_sprite_t*)sprite_case_3
# define SPRITE_CASE_4 (gfx_sprite_t*)sprite_case_4
# define SPRITE_CASE_5 (gfx_sprite_t*)sprite_case_5
# define SPRITE_CURSOR_MOVE (gfx_sprite_t*)sprite_cursor_move
# define SPRITE_CURSOR_PLACE (gfx_sprite_t*)sprite_cursor_place

#define case_gfx_transparent_color_index 0x00

# define PAL_LENGTH 130
# define sizeof_gfx_pal (PAL_LENGTH * 2)
extern uint16_t gfx_pal[PAL_LENGTH];

void defPal();
void printCursor(t_cursor cursor);
void eraseCursor(t_game *game);
void printMap(t_game *game);
void printCase(t_case matrix[MATRIX_X_MAX][MATRIX_Y_MAX], int8_t x, int8_t y);
void printText(char *text, uint8_t length, uint8_t x, uint8_t y);
void printMenu(t_pos *cursor_pos);
void eraseMenuCursor(t_pos *cursor_pos);
void printFirstMenu();
void printUint(uint8_t number, uint8_t length, uint8_t x, uint8_t y);

#endif //PROJETS_DISPLAY_H
