
#ifndef PROJETS_DISPLAY_H
#define PROJETS_DISPLAY_H

# include <stdint.h>
# include <graphx.h>

# include "ball.h"
# include "obstacle.h"

# define BALL_SIZE 5
# define BALL_GFX_SIZE (BALL_SIZE * BALL_SIZE) + 2

extern uint8_t sprite_ball[BALL_GFX_SIZE];
# define SPRITE_BALL ((gfx_sprite_t*)sprite_ball)
extern uint8_t sprite_clear_ball[BALL_GFX_SIZE];
# define SPRITE_CLEAR_BALL ((gfx_sprite_t*)sprite_clear_ball)

# define LENGTH_PAL 5
# define sizeof_gfx_pal LENGTH_PAL * 2
extern uint16_t gfx_pal[LENGTH_PAL];

void clearOldBall(t_ball ball);
void printBall(t_ball ball);
void printObstacle(t_obstacle *obstacle);
void eraseObstacle(t_obstacle *obstacle);
void printAllObstacle(t_obstacle *obstacles);
void printMap();
void printAll(t_obstacle *obstacles, t_ball ball);

#endif //PROJETS_DISPLAY_H
