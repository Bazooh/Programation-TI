
#ifndef PROJETS_OBSTACLE_H
#define PROJETS_OBSTACLE_H

# include <stdint.h>
# include <stdlib.h>
# include <math.h>

# include "ball.h"

# define NUMBER_POINT_OBSTACLE 4

# define TRUE 1
# define FALSE 0

# define HORIZONTAL 1
# define VERTICAL 2

# define MATRIX_X_LENGTH 5
# define MATRIX_Y_LENGTH 5

# define OBSTACLE_X_LENGTH 10
# define OBSTACLE_Y_LENGTH 10

# define MAP_X_MARGE 10
# define MAP_Y_MARGE 10
# define MAP_X_LENGTH (MATRIX_X_LENGTH*OBSTACLE_X_LENGTH)
# define MAP_Y_LENGTH (MATRIX_Y_LENGTH*OBSTACLE_Y_LENGTH)

# define NUMBER_SIDE_TO_CHECK 2

# define NORTH 3
# define EAST 2
# define SOUTH 1
# define WEST 0

typedef struct s_obstacle {
    t_pos point[NUMBER_POINT_OBSTACLE];
    uint8_t ortho[NUMBER_POINT_OBSTACLE];
    uint8_t id;
    uint16_t life;
    uint8_t hide[NUMBER_POINT_OBSTACLE];
    uint8_t in_matrix;
    t_pos matrix;
    struct s_obstacle *next;
}              t_obstacle;

void removeObstacle(t_obstacle *obstacle, uint8_t elem_place);
void freeObstacles(t_obstacle *obstacle);
uint8_t nbObstacle(t_obstacle *obstacle);
t_obstacle *createInvObstacleRectangle(uint8_t x, uint24_t y, uint8_t width, uint24_t height, uint16_t life);
t_obstacle *addObstacleRectangle(t_obstacle *obstacles, uint8_t x, uint24_t y, uint8_t width, uint24_t height, uint16_t life);

#endif //PROJETS_OBSTACLE_H
