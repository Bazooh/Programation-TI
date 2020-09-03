
#ifndef SRC_DISPLAY_H
#define SRC_DISPLAY_H

# include <stdint.h>
# include <graphx.h>

# include "game.h"
# include "sprite.h"
# include "card.h"

# define PAL_LENGTH 8
# define sizeof_gfx_pal (PAL_LENGTH * 2)

extern uint16_t gfx_pal[PAL_LENGTH];

void printCase(MATRIX, uint24_t x, uint8_t y);
void printMatrix(MATRIX);
void eraseCursor(MATRIX, t_pos cursor);
void printCursor(t_pos cursor);
void printDeck(t_game game);
void printMovement(MATRIX, t_pos *movement, uint8_t number_of_movement);
void eraseMovement(MATRIX, t_pos *movement, uint8_t number_of_movement);

#endif //SRC_DISPLAY_H