
#include "display.h"

uint8_t sprite_ball[BALL_GFX_SIZE] = {
        BALL_SIZE,
        BALL_SIZE,
        0,2,2,2,0,
        2,1,2,2,2,
        2,2,2,2,2,
        2,2,2,2,2,
        0,2,2,2,0,
};

uint8_t sprite_clear_ball[BALL_GFX_SIZE] = {
        BALL_SIZE,
        BALL_SIZE,
        0,1,1,1,0,
        1,1,1,1,1,
        1,1,1,1,1,
        1,1,1,1,1,
        0,1,1,1,0,
};

uint16_t gfx_pal[LENGTH_PAL] = {
        gfx_RGBTo1555(255,255,255),   // transparent
        gfx_RGBTo1555(255,255,255),   // white
        gfx_RGBTo1555(0,0,0),         // black
        gfx_RGBTo1555(60,60,60),      // dark_grey
        gfx_RGBTo1555(150,150,150),   // light_grey
};

void clearOldBall(t_ball ball) {
    gfx_TransparentSprite_NoClip(
            SPRITE_CLEAR_BALL,
            ball.old_pos.x - (BALL_SIZE / 2),
            ball.old_pos.y - (BALL_SIZE / 2));
}

void printBall(t_ball ball) {
    gfx_TransparentSprite_NoClip(
            SPRITE_BALL,
            (uint24_t)(ball.pos.x - (BALL_SIZE / 2)),
            (uint8_t)(ball.pos.y - (BALL_SIZE / 2)));
}

void printObstacle(t_obstacle *obstacle) {
    if (obstacle->life < 3) {
        gfx_SetColor(4);
    } else if (obstacle->life < 6) {
        gfx_SetColor(3);
    } else {
        gfx_SetColor(2);
    }
    gfx_FillRectangle(obstacle->point[0].x + 1, obstacle->point[0].y + 1, obstacle->point[3].x - obstacle->point[0].x - 1, obstacle->point[1].y - obstacle->point[0].y - 1);
    gfx_SetColor(2);
    gfx_Rectangle(obstacle->point[0].x, obstacle->point[0].y, obstacle->point[3].x - obstacle->point[0].x + 1, obstacle->point[1].y - obstacle->point[0].y + 1);
    gfx_SetColor(0);
}

void eraseObstacle(t_obstacle *obstacle) {
    gfx_SetColor(1);
    gfx_FillRectangle(obstacle->point[0].x, obstacle->point[0].y, obstacle->point[3].x - obstacle->point[0].x + 1, obstacle->point[1].y - obstacle->point[0].y + 1);
    gfx_SetColor(0);
}

void printAllObstacle(t_obstacle *obstacles) {
    while (obstacles->next) {
        obstacles = obstacles->next;
        printObstacle(obstacles);
    }
}

void printMap() {
    gfx_SetColor(2);
    gfx_FillRectangle(0, 0, 2*MAP_X_MARGE + MAP_X_LENGTH, MAP_Y_MARGE);
    gfx_FillRectangle(0, MAP_Y_MARGE + MAP_Y_LENGTH, 2*MAP_X_MARGE + MAP_X_LENGTH, MAP_Y_MARGE);
    gfx_FillRectangle(0, MAP_Y_MARGE, MAP_X_MARGE, MAP_Y_LENGTH);
    gfx_FillRectangle(MAP_X_MARGE + MAP_X_LENGTH, MAP_Y_MARGE, MAP_X_MARGE, MAP_Y_LENGTH);
    gfx_SetColor(0);
}

void printAll(t_obstacle *obstacles, t_ball ball) {
    gfx_FillScreen(1);
    printMap();
    printAllObstacle(obstacles);
    printBall(ball);
}