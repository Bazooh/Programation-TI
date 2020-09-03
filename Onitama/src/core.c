
#include "core.h"

uint8_t isInMap(int32_t x, int16_t y) {
    if (x >= 0 && x < MATRIX_X_LENGTH && y >= 0 && y < MATRIX_Y_LENGTH) { return TRUE; }
    return FALSE;
}

uint8_t isCursorInMovement(t_pos *movement, uint8_t number_of_movement, t_pos cursor) {
    uint8_t i;

    for (i = 1; i < number_of_movement + 1; ++i) {
        if (cursor.x == movement[i].x && cursor.y == movement[i].y) { return TRUE; }
    }
    return FALSE;
}

uint8_t isCursorOnPlayerColor(MATRIX, uint8_t player_turn, uint16_t x, uint8_t y) {
    if (player_turn == WHITE && matrix[x][y] > EMPTY) { return TRUE; } 
    if (player_turn == BLACK && matrix[x][y] < EMPTY) { return TRUE; }
    return FALSE;
}

void setMovement(t_game *game) {
    uint8_t i;
    uint8_t j;
    int32_t x;
    int16_t y;

    game->number_of_movement = 0;
    game->movement[0].x = game->cursor.x;
    game->movement[0].y = game->cursor.y;

    for (i = 0; i < MATRIX_X_LENGTH; ++i) {
        for (j = 0; j < MATRIX_Y_LENGTH; ++j) {
            x = game->cursor.x + i - 2;
            y = game->cursor.y + j - 2;
            if (game->player[game->player_turn].card[game->card_id].value[i][j] && isInMap(x, y) && !isCursorOnPlayerColor(game->matrix, game->player_turn, x, y)) {
                ++(game->number_of_movement);
                game->movement[game->number_of_movement].x = game->cursor.x + i - 2;
                game->movement[game->number_of_movement].y = game->cursor.y + j - 2;
            }
        }
    }
}

void moveCursor(t_game *game, int8_t increment_x, int8_t increment_y) {
    eraseCursor(game->matrix, game->cursor);
    if (isCursorInMovement(game->movement, game->number_of_movement, game->cursor)) { printMovement(game->matrix, game->movement, game->number_of_movement); }
    game->cursor.x += increment_x;
    game->cursor.y += increment_y;
    printCursor(game->cursor);
    delay(WAITING_DELAY);
}

void turnDeck(t_game *game) {
    CARD;
    copyCard(card, game->side_card.value);
    copyCard(game->side_card.value, game->player[game->player_turn].card[game->card_id].value);
    copyCard(game->player[game->player_turn].card[game->card_id].value, card);
}

void playerTurn(t_game *game) {
    turnDeck(game);
    reverseMatrix(game->matrix);
    game->number_of_movement = 0;
    game->player_turn = !(game->player_turn);
    game->card_id = 0;
    initCursor(&game->cursor);
    printMatrix(game->matrix);
    printCursor(game->cursor);
    printDeck(*game);
}

uint8_t doesEnemyKingExist(MATRIX, int8_t king_color) {
    uint8_t i;
    uint8_t j;

    for (i = 0; i < MATRIX_X_LENGTH; ++i) {
        for (j = 0; j < MATRIX_Y_LENGTH; ++j) {
            if (matrix[i][j] == -king_color) { return TRUE; }
        }
    }
    return FALSE;
}

uint8_t checkWin(t_game *game) {
    int8_t king_color;

    if (game->player_turn == WHITE) {
        king_color = KING_WHITE;
    } else {
        king_color = KING_BLACK;
    }
    if (game->matrix[2][0] == king_color || !doesEnemyKingExist(game->matrix, king_color)) {
        game->win = TRUE;
    }
    return (game->win);
}

void keyAction(t_game *game) {
    if (kb_Data[7] & kb_Right && game->cursor.x < MATRIX_X_LENGTH - 1) {
        moveCursor(game,  1,  0);
    }
    if (kb_Data[7] & kb_Left && game->cursor.x > 0) {
        moveCursor(game, -1,  0);
    }
    if (kb_Data[7] & kb_Down && game->cursor.y < MATRIX_Y_LENGTH - 1) {
        moveCursor(game,  0, 1);
    }
    if (kb_Data[7] & kb_Up && game->cursor.y > 0) {
        moveCursor(game, 0, -1);
    }
    if (kb_Data[1] & kb_Zoom) {
        eraseMovement(game->matrix, game->movement, game->number_of_movement);
        ++(game->card_id);
        game->card_id %= NUMBER_OF_CARD_IN_HAND;
        game->number_of_movement = 0;
        if (isCursorOnPlayerColor(game->matrix, game->player_turn, game->cursor.x, game->cursor.y)) {
            setMovement(game);
            printMovement(game->matrix, game->movement, game->number_of_movement);
        }
        delay(WAITING_DELAY);
    }
    if (kb_Data[6] & kb_Enter) {
        if (isCursorOnPlayerColor(game->matrix, game->player_turn, game->cursor.x, game->cursor.y)) {
            eraseMovement(game->matrix, game->movement, game->number_of_movement);
            setMovement(game);
            printMovement(game->matrix, game->movement, game->number_of_movement);
            delay(WAITING_DELAY);
        } 
        if (isCursorInMovement(game->movement, game->number_of_movement, game->cursor)) {
            game->matrix[game->cursor.x][game->cursor.y] = game->matrix[game->movement[0].x][game->movement[0].y];
            game->matrix[game->movement[0].x][game->movement[0].y] = EMPTY;
            printCase(game->matrix, game->cursor.x, game->cursor.y);
            printCase(game->matrix, game->movement[0].x, game->movement[0].y);
            printCursor(game->cursor);
            if (checkWin(game)) { return; }
            playerTurn(game);
            delay(WAITING_DELAY);
        }
    }
}

void play() {
    t_game game;

    game.player_turn = WHITE;
    game.number_of_movement = 0;
    initMatrix(game.matrix);
    initDeck(&game);
    initCursor(&game.cursor);
    game.card_id = 0;
    game.win = FALSE;

    printMatrix(game.matrix);
    printDeck(game);
    printCursor(game.cursor);

    while (!(kb_Data[1] & kb_Del || game.win)) {
        kb_Scan();
        keyAction(&game);
    }
}