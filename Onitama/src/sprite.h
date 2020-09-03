
#ifndef SRC_SPRITE_H
#define SRC_SPRITE_H

# include <stdint.h>

# include "game.h"

# define CASE_X_LENGTH 25
# define CASE_Y_LENGTH 25
# define CASE_SIZE (CASE_X_LENGTH*CASE_Y_LENGTH + 2)

# define MARGE_X ((320 - CASE_X_LENGTH*MATRIX_X_LENGTH) / 2)
# define MARGE_Y ((240 - CASE_Y_LENGTH*MATRIX_Y_LENGTH) / 2)

# define SPRITE_EMPTY (gfx_sprite_t*)sprite_empty
extern uint8_t sprite_empty[CASE_SIZE];

# define SPRITE_KING_WHITE (gfx_sprite_t*)sprite_king_white
extern uint8_t sprite_king_white[CASE_SIZE];
# define SPRITE_PION_WHITE (gfx_sprite_t*)sprite_pion_white
extern uint8_t sprite_pion_white[CASE_SIZE];

# define SPRITE_KING_BLACK (gfx_sprite_t*)sprite_king_black
extern uint8_t sprite_king_black[CASE_SIZE];

# define SPRITE_PION_BLACK (gfx_sprite_t*)sprite_pion_black
extern uint8_t sprite_pion_black[CASE_SIZE];

# define SPRITE_CURSOR (gfx_sprite_t*)sprite_cursor
extern uint8_t sprite_cursor[CASE_SIZE];

# define SPRITE_MOVEMENT (gfx_sprite_t*)sprite_movement
extern uint8_t sprite_movement[CASE_SIZE];

# define SPRITE_MOVEMENT_TOUCH (gfx_sprite_t*)sprite_movement_touch
extern uint8_t sprite_movement_touch[CASE_SIZE];

#endif // SRC_SPRITE_H