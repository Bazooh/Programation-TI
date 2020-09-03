
#include "map_generator.h"

void increment(t_pos *pos, uint8_t direction) {
    switch (direction) {
        case 0:
            ++(pos->x);
            break;
        case 1:
            ++(pos->y);
            break;
        case 2:
            --(pos->x);
            break;
        case 3:
            --(pos->y);
            break;
    }
}

uint8_t checkDeploy(t_game *game, t_pos pos, uint8_t direction) {
    int8_t number;

    number = game->matrix[pos.x][pos.y].number;
    increment(&pos, direction);

    while (number && isInMap(game, pos)) {
        if (game->matrix[pos.x][pos.y].number <= CASE_BLOCKED) {
            --number;
        }
        increment(&pos, direction);
    }
    if (!number) { return TRUE; }
    return FALSE;
}

void deployNumber(t_game *game, t_pos *numbers) {
    uint8_t i;
    uint8_t direction;
    uint8_t direction_count;
    int8_t number;

    for (i = 0; i < game->amount_number; ++i) {
        direction_count = 0;
        direction = randInt(0, NUMBER_DIRECTION - 1);

        while (direction_count < NUMBER_DIRECTION && !checkDeploy(game, numbers[i], (direction + direction_count) % NUMBER_DIRECTION)) {
            ++direction_count;
        }
        if (direction_count >= NUMBER_DIRECTION) {
            game->matrix[numbers[i].x][numbers[i].y].number = CASE_BLOCKED;
        } else {
            direction += direction_count;
            direction %= NUMBER_DIRECTION;
            number = game->matrix[numbers[i].x][numbers[i].y].number;
            while (number) {
                increment(&numbers[i], direction);
                if (game->matrix[numbers[i].x][numbers[i].y].number <= CASE_BLOCKED) {
                    game->matrix[numbers[i].x][numbers[i].y].number = CASE_EMPTY;
                    game->matrix[numbers[i].x][numbers[i].y].old_number = CASE_EMPTY;
                    --number;
                }
            }
        }
    }
}

void generateNumbers(t_game *game, t_pos *numbers) {
    t_pos random_pos;
    int8_t random_number;
    uint8_t i;

    for (i = 0; i < game->amount_number; ++i) {
        do {
            random_pos.x = randInt(0, game->x_max - 1);
            random_pos.y = randInt(0, game->y_max - 1);
            random_number = randInt(1, game->number_max);
        } while (game->matrix[random_pos.x][random_pos.y].number >= CASE_EMPTY);
        game->matrix[random_pos.x][random_pos.y].id = i + 1;
        game->matrix[random_pos.x][random_pos.y].number = random_number;
        game->matrix[random_pos.x][random_pos.y].old_number = random_number;
        numbers[i] = random_pos;
    }
}

void generateMap(t_game *game) {
    t_pos *numbers;

    if (!(numbers = malloc(sizeof(t_pos) * game->amount_number))) { return; }

    generateNumbers(game, numbers);
    deployNumber(game, numbers);

    free(numbers);
}