
#include "minesweeper.h"

t_pos DIRECTIONS[MAX_DIRECTIONS] = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1},
};

int8_t LINE_DIRECTIONS_X[NUMBER_OF_SIDES_OF_A_SQUARE] = {
        0,
        -1,
        0,
        1,
};

int8_t LINE_DIRECTIONS_Y[NUMBER_OF_SIDES_OF_A_SQUARE] = {
        -1,
        0,
        1,
        0,
};

int8_t maxABCD(int8_t a, int8_t b, int8_t c, int8_t d) {
    if (a >= b && a >= c && a >= d)
        return a;
    if (b >= a && b >= c && b >= d)
        return b;
    if (c >= a && c >= b && c >= d)
        return c;
    return d;
}

uint8_t checkInnerMap(t_pos direction) {
    if (direction.x < 0 || direction.x >= MAP_X_MAX)
        return false;
    if (direction.y < 0 || direction.y >= MAP_Y_MAX)
        return false;
    return true;
}

void putBomb(t_case matrix[MAP_X_MAX][MAP_Y_MAX], uint8_t x, uint8_t y) {
    uint8_t i;
    t_pos direction;

    matrix[x][y].bomb = true;
    for(i = 0; i < MAX_DIRECTIONS; i++) {
        direction.x = x + DIRECTIONS[i].x;
        direction.y = y + DIRECTIONS[i].y;
        if (checkInnerMap(direction) && !matrix[direction.x][direction.y].bomb)
            matrix[direction.x][direction.y].value++;
    }
}

void mapGenerator(t_case matrix[MAP_X_MAX][MAP_Y_MAX], uint16_t number_of_bomb) {
    uint16_t i;
    uint32_t random_number;
    uint8_t x;
    uint8_t y;

    srandom(rtc_Time());

    for (i = 0; i < number_of_bomb; i++) {
        do {
            random_number = random();
            x = (random_number >> 0x10) % MAP_X_MAX;
            y = (random_number & 0x0000FFFF) % MAP_Y_MAX;
        } while (matrix[x][y].bomb);
        putBomb(matrix, x, y);
    }
}

void initCursor(t_pos *cursor) {
    cursor->x = 0;
    cursor->y = 0;
}

void initMatrix(t_case matrix[MAP_X_MAX][MAP_Y_MAX]) {
    uint8_t i;
    uint8_t j;
    for(j = 0; j < MAP_Y_MAX; j++) {
        for(i = 0; i < MAP_X_MAX; i++) {
            matrix[i][j].visible = false;
            matrix[i][j].flag = false;
            matrix[i][j].bomb = false;
            matrix[i][j].value = 0;
        }
    }
}

uint8_t checkNullCase(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos direction) {
    t_case value = matrix[direction.x][direction.y];
    if (value.visible || value.value || value.bomb)
        return false;
    return true;
}

void discoverBombInLine(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos *case_check, int8_t line_length, t_pos direction) {
    uint8_t i;

    for(i = 0; i < line_length; i++) {
        case_check->x = case_check->x + direction.x;
        case_check->y = case_check->y + direction.y;

        if (matrix[case_check->x][case_check->y].bomb) {
            if (checkInnerMap(*case_check)) {
                matrix[case_check->x][case_check->y].visible = true;
                matrix[case_check->x][case_check->y].flag = false;
                printCase(matrix, case_check->x, case_check->y);
                delay(10);
            }
        }
    }
}

void discoverBombInSquare(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos cursor, int8_t square_length) {
    int8_t i;
    int8_t j;
    t_pos case_check;
    t_pos direction;
    case_check.x = cursor.x;
    case_check.y = cursor.y;

    for(i = 0; i < square_length; i++) {
        for(j = 0; j < 2; j++) {
            direction.x = LINE_DIRECTIONS_X[j];
            direction.y = LINE_DIRECTIONS_Y[j];
            discoverBombInLine(matrix, &case_check, (2 * i) + 1, direction);
        }
        for(j = 2; j < 4; j++) {
            direction.x = LINE_DIRECTIONS_X[j];
            direction.y = LINE_DIRECTIONS_Y[j];
            discoverBombInLine(matrix, &case_check, (2 * i) + 2, direction);
        }
    }
}

void discoverBomb(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos cursor) {
    int8_t max_case_check;

    max_case_check = maxABCD(cursor.x, MAP_X_MAX - cursor.x, cursor.y, MAP_Y_MAX - cursor.y);

    discoverBombInSquare(matrix, cursor, max_case_check);
}

void discoverCase(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos cursor) {
    t_case  *value = &matrix[cursor.x][cursor.y];

    value->visible = true;
    value->flag = false;

    printCase(matrix, cursor.x, cursor.y);

    if (value->bomb)
        discoverBomb(matrix, cursor);
}

void checkAddToList(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos direction, t_list *elem) {
    if (checkNullCase(matrix, direction))
        addPos(elem, direction);
}

void discoverCases(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos cursor) {
    uint8_t i;
    t_pos   direction;
    t_list  start;
    t_list  *elem;

    start.next = NULL;

    checkAddToList(matrix, cursor, &start);
    discoverCase(matrix, cursor);

    elem = start.next;
    while (elem) {
        for(i = 0; i < MAX_DIRECTIONS; i++) {
            direction.x = elem->pos.x + DIRECTIONS[i].x;
            direction.y = elem->pos.y + DIRECTIONS[i].y;
            if (checkInnerMap(direction)) {
                checkAddToList(matrix, direction, elem);
                discoverCase(matrix, direction);
            }
        }
        elem = deleteGoNext(elem);
    }
}



void putFlag(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos cursor) {
    t_case  *value = &matrix[cursor.x][cursor.y];

    if (value->visible)
        return ;

    value->flag = !value->flag;
    printCase(matrix, cursor.x, cursor.y);
}

uint8_t checkCanMove(t_pos *cursor, int8_t increment_x, int8_t increment_y) {
    if (cursor->x + increment_x >= MAP_X_MAX || cursor->x + increment_x < 0)
        return (false);
    if (cursor->y + increment_y >= MAP_Y_MAX || cursor->y + increment_y < 0)
        return (false);
    return (true);
}

void moveCursor(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos *cursor, int8_t increment_x, int8_t increment_y) {
    if (!checkCanMove(cursor, increment_x, increment_y))
        return ;
    deleteCursor(matrix, *cursor);
    cursor->x += increment_x;
    cursor->y += increment_y;
    printCursor(*cursor);
}

void lockDelay(kb_key_t *old_keys) {
    uint8_t pause = false;
    uint8_t i;
    for (i = 1; i < 8; i++) {
        if (old_keys[i] != kb_Data[i]) {
            pause = true;
            old_keys[i] = kb_Data[i];
        }
    }

    if (pause)
        delay(160);
    delay(40);
}

void keyArrow(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos *cursor) {
    kb_key_t key = kb_Data[7];

    if (key & kb_Down)
        moveCursor(matrix, cursor, MOVE_DOWN);
    if (key & kb_Up)
        moveCursor(matrix, cursor, MOVE_UP);
    if (key & kb_Left)
        moveCursor(matrix, cursor, MOVE_LEFT);
    if (key & kb_Right)
        moveCursor(matrix, cursor, MOVE_RIGHT);
}

void keyAction(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos cursor) {

    if (kb_Data[5] & kb_Chs) {
        putFlag(matrix, cursor);
        printCursor(cursor);
    }
    if (kb_Data[6] & kb_Enter) {
        discoverCases(matrix, cursor);
        printCursor(cursor);
    }
}

void gameLoop(t_case matrix[MAP_X_MAX][MAP_Y_MAX], t_pos *cursor) {
    kb_key_t old_key[8];

    do {
        kb_Scan();
        keyArrow(matrix, cursor);
        keyAction(matrix, *cursor);
        lockDelay(old_key);
    } while (!(kb_Data[1] & kb_Del));

}

void play(void) {
    t_case  matrix[MAP_X_MAX][MAP_Y_MAX];
    t_pos   cursor;
    initCursor(&cursor);


    initMatrix(matrix);
    mapGenerator(matrix, 100);
    printScreen(matrix, cursor);
    gameLoop(matrix, &cursor);

}

