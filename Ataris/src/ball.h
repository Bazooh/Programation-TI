
#ifndef PROJETS_BALL_H
#define PROJETS_BALL_H

# include <stdint.h>
# include <math.h>

# define BALL_RAYON ((BALL_SIZE + 1) / 2)
# define NUMBER_DIRECTION 4

typedef struct s_pos {
    uint24_t x;
    uint8_t y;
}              t_pos;

typedef struct s_precision_pos {
    double x;
    double y;
}              t_precision_pos;

typedef struct s_ball {
    t_precision_pos pos;
    t_pos old_pos;
    double direction;
    double speed;
}              t_ball;

extern const double DIRECTION[NUMBER_DIRECTION][2];

#endif //PROJETS_BALL_H
