
#ifndef PROJETS_DISPLAY_H
#define PROJETS_DISPLAY_H

# include <stdint.h>
# include <graphx.h>

# include "struct.h"
# include "color.h"

# define case_gfx_transparent_color_index 0

# define MARGE_X 50
# define MARGE_Y 20
# define CASE_X_LENGTH 10
# define CASE_Y_LENGTH 10
# define CASE_SIZE 2 + (CASE_X_LENGTH * CASE_Y_LENGTH)
# define MARGE_X_NEXT_PIECE 220
# define MARGE_Y_NEXT_PIECE 30

# define MARGE_X_SCORE 240
# define MARGE_Y_SCORE 100
# define SCORE_LENGTH 6

# define MARGE_X_DIFFICULTY 180
# define MARGE_Y_DIFFICULTY 120
# define DIFFICULTY_LENGTH 6

# define MARGE_X_PAUSE 196
# define MARGE_Y_PAUSE 160
# define PAUSE_LENGTH 11

# define CHAR_LENGTH 8

gfx_sprite_t* initPrintBlock(uint8_t color);
void printScreen(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH]);
void printPiece(t_piece piece);
void printBlock(uint24_t x, uint8_t y, uint8_t color);
void clearPiece(t_piece piece);
void printNextPiece(t_piece next_piece);
void printScore(uint32_t score);
void printDifficulty(uint8_t difficulty);
void printPause();
void clearPause();
void printGameOver();

#endif //PROJETS_DISPLAY_H
