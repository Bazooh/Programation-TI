
#ifndef SRC_CARD_H
#define SRC_CARD_H

# include <stdint.h>

# include "game.h"

# define CARD_X_LENGTH 41
# define CARD_Y_LENGTH 41
# define CARD_SIZE (CARD_X_LENGTH*CARD_Y_LENGTH + 2)

# define CARD_CASE_X_LENGTH 5
# define CARD_CASE_Y_LENGTH 5
# define CARD_CASE_SIZE (CARD_CASE_X_LENGTH*CARD_CASE_Y_LENGTH + 2)

extern uint8_t CARDS[NUMBER_OF_CARD_TOTAL][MATRIX_X_LENGTH][MATRIX_Y_LENGTH];

# define SPRITE_CARD_CASE_EMPTY (gfx_sprite_t*)sprite_card_case_empty
extern uint8_t sprite_card_case_empty[CARD_CASE_SIZE];

# define SPRITE_CARD_CASE_FULL (gfx_sprite_t*)sprite_card_case_full
extern uint8_t sprite_card_case_full[CARD_CASE_SIZE];

# define SPRITE_CARD_CASE_MIDDLE (gfx_sprite_t*)sprite_card_case_middle
extern uint8_t sprite_card_case_middle[CARD_CASE_SIZE];

# define SPRITE_CARD (gfx_sprite_t*)sprite_card
extern uint8_t sprite_card[CARD_SIZE];

#endif //SRC_CARD_H