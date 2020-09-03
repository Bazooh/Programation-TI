
#include "obstacle.h"

void removeObstacle(t_obstacle *obstacle, uint8_t elem_place) {
    uint8_t i;
    t_obstacle *obstacle_to_free;

    for (i = 0; i < elem_place - 1; ++i) {
        if (!obstacle->next) { return; }
        obstacle = obstacle->next;
    }

    obstacle_to_free = obstacle->next;
    obstacle->next = obstacle_to_free->next;
    free(obstacle_to_free);

    while (obstacle->next) {
        obstacle = obstacle->next;
        --(obstacle->id);
    }
}

void freeObstacles(t_obstacle *obstacle) {
    t_obstacle *obstacle_to_free;

    while (obstacle->next) {
        obstacle_to_free = obstacle;
        obstacle = obstacle->next;
        free(obstacle_to_free);
    }
    free(obstacle);
}

t_obstacle *createObstacle(
        uint8_t x0, uint24_t y0,
        uint8_t x1, uint24_t y1,
        uint8_t x2, uint24_t y2,
        uint8_t x3, uint24_t y3,
        uint16_t life) {

    uint8_t i;
    t_obstacle *new_elem;

    if (!(new_elem = malloc(sizeof(t_obstacle)))) { return NULL; }

    new_elem->point[0].x = x0;
    new_elem->point[0].y = y0;
    new_elem->point[1].x = x1;
    new_elem->point[1].y = y1;
    new_elem->point[2].x = x2;
    new_elem->point[2].y = y2;
    new_elem->point[3].x = x3;
    new_elem->point[3].y = y3;

    new_elem->life = life;

    for (i = 0; i < NUMBER_POINT_OBSTACLE; ++i) {
        new_elem->ortho[i] = FALSE;
        new_elem->hide[i] = FALSE;
    }
    new_elem->in_matrix = FALSE;

    new_elem->next = NULL;

    return new_elem;
}

t_obstacle *createObstacleRectangle(uint8_t x, uint24_t y, uint8_t width, uint24_t height, uint16_t life) {
    t_obstacle *new_elem;

    new_elem = createObstacle(
            x,         y,
            x,         y + height,
            x + width, y + height,
            x + width, y,
            life);

    new_elem->ortho[WEST] = VERTICAL;
    new_elem->ortho[SOUTH] = HORIZONTAL;
    new_elem->ortho[EAST] = VERTICAL;
    new_elem->ortho[NORTH] = HORIZONTAL;

    return new_elem;
}

t_obstacle *createInvObstacleRectangle(uint8_t x, uint24_t y, uint8_t width, uint24_t height, uint16_t life) {
    t_obstacle *new_elem;

    new_elem = createObstacle(
            x + width, y + height,
            x + width, y,
            x,         y,
            x,         y + height,
            life);

    new_elem->ortho[WEST] = VERTICAL;
    new_elem->ortho[SOUTH] = HORIZONTAL;
    new_elem->ortho[EAST] = VERTICAL;
    new_elem->ortho[NORTH] = HORIZONTAL;

    return new_elem;
}


uint8_t nbObstacle(t_obstacle *obstacle) {
    uint8_t i;

    i = 1;

    while (obstacle->next) {
        obstacle = obstacle->next;
        ++i;
    }
    return i;
}

t_obstacle *addObstacleRectangle(t_obstacle *obstacles, uint8_t x, uint24_t y, uint8_t width, uint24_t height, uint16_t life) {
    t_obstacle *new_elem;
    uint8_t obstacle_id;

    if (!(new_elem = createObstacleRectangle(x, y, width, height, life))) { return NULL; }

    obstacle_id = 1;

    while (obstacles->next) {
        obstacles = obstacles->next;
        ++obstacle_id;
    }

    new_elem->id = obstacle_id;
    new_elem->in_matrix = FALSE;
    obstacles->next = new_elem;

    return new_elem;
}