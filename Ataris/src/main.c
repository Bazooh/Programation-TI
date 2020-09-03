
#include "main.h"

t_obstacle *createMap() {
    t_obstacle *obstacles;

    if (!(obstacles = createInvObstacleRectangle(MAP_X_MARGE, MAP_Y_MARGE, MAP_X_LENGTH, MAP_Y_LENGTH, 0))) { return NULL; }

    obstacles->id = 0;

    return obstacles;
}

void gameOver(t_obstacle *obstacles) {
    freeObstacles(obstacles);
    kb_Reset();
    gfx_End();
}

void initBall(t_ball *ball) {
    ball->pos.x = 30;
    ball->pos.y = 30;
    ball->direction = rad(60);
    ball->old_pos.x = 0;
    ball->old_pos.y = 0;
}

void initMatrix(uint8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH]) {
    uint8_t i;
    uint8_t j;

    for (i = 0; i < MATRIX_Y_LENGTH; ++i) {
        for (j= 0; j < MATRIX_X_LENGTH; ++j) {
            matrix[j][i] = 0;
        }
    }
}

void main(void) {
    t_ball ball;
    uint8_t i;
    t_obstacle *obstacles;
    t_game_info game_info;
    double speed_total;
    double speed_moy;
    uint32_t nb_speed;
    uint8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH];

    dbg_ClearConsole();
    gfx_Begin();
    gfx_SetPalette(gfx_pal, sizeof_gfx_pal, 0);
    gfx_FillScreen(1);
    gfx_SetTextFGColor(2);
    gfx_SetColor(0);
    srandom(rtc_Time());

    timer_Control = TIMER1_DISABLE;
    timer_1_ReloadValue = timer_1_Counter = 0;
    timer_Control = TIMER1_ENABLE | TIMER1_32K | TIMER1_0INT | TIMER1_UP;

    initMatrix(matrix);
    initBall(&ball);
    speed_total = 0;
    nb_speed = 0;

    if (!(obstacles = createMap())) { return; }

    //generateLine(matrix, obstacles);

    printAll(obstacles, ball);

    while(1) {
        if (kb_AnyKey()) {
            delay(100);
            speed_moy = speed_total / (double)nb_speed;
            dbg_sprintf(dbgout, "    speed total : %d.%d\n", (int)speed_total, (int)(speed_total*1000000 - (int)speed_total*1000000));
            dbg_sprintf(dbgout, "       nb_speed : %d.%d\n", (int)nb_speed, (int)(nb_speed*1000000 - (int)nb_speed*1000000));
            dbg_sprintf(dbgout, "      speed moy : %d.%d\n", (int)speed_moy, (int)(speed_moy*1000000 - (int)speed_moy*1000000));

            if (!(mapMoveDown(matrix, obstacles))) { gameOver(obstacles); return; }
            generateLine(matrix, obstacles);

            printAll(obstacles, ball);

            while (!kb_AnyKey());
            delay(100);
            timer_1_Counter = 0;
        }
        ballMove(matrix, obstacles, &ball, &speed_total, &nb_speed);
        clearOldBall(ball);
        printBall(ball);
    }
}

