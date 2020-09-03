
#ifndef PROJETS_CORE_H
#define PROJETS_CORE_H

# include <math.h>
# include <stdint.h>
# include <debug.h>

# include "ball.h"
# include "display.h"
# include "obstacle.h"
# include "game_info.h"
# include "map.h"

# define DISTANCE 80.0
# define TIME 32768 // ONE SECOND
# define SPEED (DISTANCE / TIME)

# define STEP 5

# define t1 variables[0]
# define t2 variables[1]
# define moy_t variables[2]
# define a_2 variables[3]
# define c_2 variables[4]
# define delta variables[5]
# define sqrt_delta variables[6]

double rad(int16_t angle);
int16_t deg(double angle);
void ballMove(uint8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH], t_obstacle *obstacles, t_ball *ball, double *speed_total, uint32_t *nb_speed);

#endif //PROJETS_CORE_H
