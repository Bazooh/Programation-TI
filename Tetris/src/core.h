
#ifndef TETRIS_CORE_H
#define TETRIS_CORE_H

# include <stdint.h>
# include <keypadc.h>

# include "initPiece.h"
# include "struct.h"
# include "coreDefine.h"
# include "display.h"

# define EASY 0
# define NORMAL 1
# define HARD 2

extern uint16_t TIMER[3];

t_piece *createPiece();
uint8_t checkCaseMovement(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_pos checking_case);
uint8_t checkPieceMovement(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece piece);
void initMatrix(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH]);
void moveLeft(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece);
void moveRight(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece);
void leftRotation(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece);
void rightRotation(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece);
void moveDown(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece);
void moveDownMatrix(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], uint8_t y);
void verificationSuppressLine(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], uint32_t *score);
void placePiece(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece, uint32_t *score);
void drop(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece, uint32_t *score);
uint8_t checkEnd(t_piece piece);
uint8_t checkKbAction(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece, kb_key_t *old_key, uint32_t *score);
uint8_t checkingTime(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece, uint32_t *time);
uint8_t chooseDifficulty();
void loop(uint8_t difficulty);
void gameOver();

#endif //TETRIS_CORE_H