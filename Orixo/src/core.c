
#include "core.h"

void setFirstNumber(t_game *game, t_pos *first_number) {
    uint8_t i;
    uint8_t j;
    uint8_t breaking;

    breaking = FALSE;

    for (i = 0; i < game->x_max; ++i) {
        for (j = 0; j < game->y_max; ++j) {
            if (game->matrix[i][j].number > CASE_EMPTY) {
                breaking = TRUE;
                break;
            }
        }
        if (breaking) { break; }
    }
    i %= MATRIX_X_MAX;
    j %= MATRIX_Y_MAX;

    first_number->x = i;
    first_number->y = j;
}

void initCursor(t_game *game) {
    t_pos first_number;

    setFirstNumber(game, &first_number);

    game->cursor.pos.x = first_number.x;
    game->cursor.pos.y = first_number.y;
    game->cursor.state = 0;
}

uint8_t cursorCanMove(t_game *game, int8_t increment_x, int8_t increment_y) {
    if (game->cursor.pos.x + increment_x >= game->x_max || game->cursor.pos.x + increment_x < 0)
        return FALSE;
    if (game->cursor.pos.y + increment_y >= game->y_max || game->cursor.pos.y + increment_y < 0)
        return FALSE;
    if (game->matrix[game->cursor.pos.x + increment_x][game->cursor.pos.y + increment_y].number == CASE_BLOCKED)
        return FALSE;
    return TRUE;
}

void moveCursor(t_game *game, int8_t increment_x, int8_t increment_y) {
    if (!cursorCanMove(game, increment_x, increment_y)) { return; }

    eraseCursor(game);
    game->cursor.pos.x += increment_x;
    game->cursor.pos.y += increment_y;
    printCursor(game->cursor);
    delay(WAITING_DELAY);
}

void kbArrowMove(t_game *game) {
    kb_key_t key = kb_Data[7];

    if (key & kb_Down)
        moveCursor(game, DOWN);
    if (key & kb_Up)
        moveCursor(game, UP);
    if (key & kb_Left)
        moveCursor(game, LEFT);
    if (key & kb_Right)
        moveCursor(game, RIGHT);
}

uint8_t checkGameWin(t_game *game) {
    uint8_t i;
    uint8_t j;

    for (i = 0; i < game->x_max; ++i) {
        for (j = 0; j < game->y_max; ++j) {
            if (game->matrix[i][j].number > CASE_USED)
                return FALSE;
        }
    }
    return TRUE;
}

uint8_t isInMap(t_game *game, t_pos pos) {
    if (pos.x >= 0 && pos.x < game->x_max && pos.y >= 0 && pos.y < game->y_max) { return TRUE; }
    return FALSE;
}

uint8_t checkPlacement(t_game *game, t_pos pos, int8_t increment_x, int8_t increment_y) {
    uint8_t number;

    number = game->matrix[pos.x][pos.y].number;

    while (isInMap(game, pos) && number) {
        pos.x += increment_x;
        pos.y += increment_y;
        if (game->matrix[pos.x][pos.y].number <= CASE_BLOCKED) { break; }
        if (!(game->matrix[pos.x][pos.y].number)) { --number; }
    }
    if (!number) { return TRUE; }
    return FALSE;
}

void placement(t_game *game, int8_t increment_x, int8_t increment_y) {
    uint8_t number;
    t_pos pos;
    uint8_t id;

    pos.x = game->cursor.pos.x;
    pos.y = game->cursor.pos.y;

    if (!checkPlacement(game, pos, increment_x, increment_y)) { return; }

    number = game->matrix[pos.x][pos.y].number;
    id = game->matrix[pos.x][pos.y].id;
    game->matrix[pos.x][pos.y].number = CASE_USED;
    printCase(game->matrix, pos.x, pos.y);
    delay(50);

    while (number) {
        pos.x += increment_x;
        pos.y += increment_y;
        if (!(game->matrix[pos.x][pos.y].number)) {
            game->matrix[pos.x][pos.y].number = CASE_USED;
            game->matrix[pos.x][pos.y].id = id;
            printCase(game->matrix, pos.x, pos.y);
            --number;
            delay(50);
        }
    }
    game->cursor.state = 0;
    printCursor(game->cursor);
    delay(WAITING_DELAY);
    game->win = checkGameWin(game);
}

void undo(t_game *game) {
    uint8_t i;
    uint8_t j;
    uint8_t id;

    id = game->matrix[game->cursor.pos.x][game->cursor.pos.y].id;

    if (!id) { return; }

    for (i = 0; i < game->x_max; ++i) {
        for (j = 0; j < game->y_max; ++j) {
            if (game->matrix[i][j].id == id) {
                game->matrix[i][j].number = game->matrix[i][j].old_number;
            }
        }
    }
    printMap(game);
}

void kbArrowPlace(t_game *game) {
    kb_key_t key = kb_Data[7];

    if (game->matrix[game->cursor.pos.x][game->cursor.pos.y].number <= 0) { return; }

    if (key & kb_Down)
        placement(game, DOWN);
    if (key & kb_Up)
        placement(game, UP);
    if (key & kb_Left)
        placement(game, LEFT);
    if (key & kb_Right)
        placement(game, RIGHT);
}

void kbAction(t_game *game) {
    if (kb_Data[6] & kb_Enter && game->matrix[game->cursor.pos.x][game->cursor.pos.y].number > CASE_EMPTY) {
        eraseCursor(game);
        game->cursor.state = !(game->cursor.state);
        printCursor(game->cursor);
        delay(WAITING_DELAY);
    }
    if (game->cursor.state) {
        kbArrowPlace(game);
    } else {
        kbArrowMove(game);
    }
    if (kb_Data[6] & kb_Clear) {
        undo(game);
    }
    if (kb_Data[1] & kb_2nd) {
        eraseCursor(game);
        initCursor(game);
        printCursor(game->cursor);
    }
}

void play(t_game game) {
    t_cursor cursor;

    initCursor(&game);
    kb_Scan();

    printMap(&game);

    while (!(game.win) && !(kb_Data[1] & kb_Del)) {
        kbAction(&game);
        kb_Scan();
    }
}