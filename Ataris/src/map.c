
#include "map.h"

void setHiddenObstacle(t_obstacle *obstacles, uint8_t id, uint8_t side, uint8_t value) {
    uint8_t i;

    for (i = 0; i < id; ++i) {
        obstacles = obstacles->next;
    }
    obstacles->hide[side] = value;
}

void setAdjHiddenObstacle(uint8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH], t_obstacle *obstacles, uint8_t x, uint8_t y, uint8_t value) {
    if (x >= 1 && matrix[x - 1][y]) {
        setHiddenObstacle(obstacles, matrix[x - 1][y], EAST, TRUE);
        setHiddenObstacle(obstacles, matrix[x][y], WEST, TRUE);
    }
    if (y >= 1 && matrix[x][y - 1]) {
        setHiddenObstacle(obstacles, matrix[x][y - 1], SOUTH, TRUE);
        setHiddenObstacle(obstacles, matrix[x][y], NORTH, TRUE);
    }
    if (x <= MATRIX_X_LENGTH - 2 && matrix[x + 1][y]) {
        setHiddenObstacle(obstacles, matrix[x + 1][y], WEST, TRUE);
        setHiddenObstacle(obstacles, matrix[x][y], EAST, TRUE);
    }
    if (y <= MATRIX_Y_LENGTH - 2 && matrix[x][y + 1]) {
        setHiddenObstacle(obstacles, matrix[x][y + 1], NORTH, TRUE);
        setHiddenObstacle(obstacles, matrix[x][y], SOUTH, TRUE);
    }
}

void addObstacleRectangleInMatrix(uint8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH], t_obstacle *obstacles, uint8_t x, uint8_t y, uint16_t life) {
    t_obstacle *new_elem;

    if (!(new_elem = addObstacleRectangle(obstacles, OBSTACLE_X_LENGTH*x + MAP_X_MARGE, OBSTACLE_Y_LENGTH*(uint24_t)y + MAP_Y_MARGE, OBSTACLE_X_LENGTH - 1, OBSTACLE_Y_LENGTH - 1, life))) { return; }

    new_elem->in_matrix = TRUE;
    new_elem->matrix.x = x;
    new_elem->matrix.y = y;

    matrix[x][y] = new_elem->id;

    setAdjHiddenObstacle(matrix, obstacles, x, y, TRUE);

    if (x == 0) { setHiddenObstacle(obstacles, matrix[x][y], WEST, TRUE); }
    if (x == MATRIX_X_LENGTH - 1) { setHiddenObstacle(obstacles, matrix[x][y], EAST, TRUE); }
    if (y == 0) { setHiddenObstacle(obstacles, matrix[x][y], NORTH, TRUE); }
    if (y == MATRIX_Y_LENGTH - 1) { setHiddenObstacle(obstacles, matrix[x][y], SOUTH, TRUE); }
}

void generateLine(uint8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH], t_obstacle *obstacles) {
    uint8_t i;
    uint32_t random_number;

    for (i = 0; i < MATRIX_X_LENGTH; ++i) {
        random_number = random() % 2;
        if (random_number) {
            addObstacleRectangleInMatrix(matrix, obstacles, i, 0, 10);
        }
    }
}

uint8_t mapMoveDown(uint8_t matrix[MATRIX_X_LENGTH][MATRIX_Y_LENGTH], t_obstacle *obstacles) {
    uint8_t i;
    t_obstacle *obstacle;

    obstacle = obstacles;

    while (obstacle->next) {
        obstacle = obstacle->next;
        for (i = 0; i < NUMBER_POINT_OBSTACLE; ++i) {
            obstacle->point[i].y += OBSTACLE_Y_LENGTH;
            if (obstacle->point[i].y >= MATRIX_Y_LENGTH*OBSTACLE_Y_LENGTH + MAP_Y_MARGE) { return FALSE; }
        }
        if (obstacle->in_matrix) {
            if (obstacle->matrix.y == 0) { setHiddenObstacle(obstacles, matrix[obstacle->matrix.x][obstacle->matrix.y], NORTH, FALSE); }
            if (matrix[obstacle->matrix.x][obstacle->matrix.y] == obstacle->id) { matrix[obstacle->matrix.x][obstacle->matrix.y] = 0; }
            (obstacle->matrix.y)++;
            matrix[obstacle->matrix.x][obstacle->matrix.y] = obstacle->id;
            if (obstacle->matrix.y == MATRIX_Y_LENGTH - 1) { setHiddenObstacle(obstacles, matrix[obstacle->matrix.x][obstacle->matrix.y], SOUTH, TRUE); }
        }
    }
    return TRUE;
}