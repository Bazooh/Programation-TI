
#ifndef PROJETS_MAP_H
#define PROJETS_MAP_H

# include <tice.h>

# include "obstacle.h"

void generateLine(uint8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH], t_obstacle *obstacles);
uint8_t mapMoveDown(uint8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH], t_obstacle *obstacles);
void setAdjHiddenObstacle(uint8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH], t_obstacle *obstacles, uint8_t x, uint8_t y, uint8_t value);
void addObstacleRectangleInMatrix(uint8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH], t_obstacle *obstacles, uint8_t x, uint8_t y, uint16_t life);

#endif //PROJETS_MAP_H
