
#include "core.h"

uint16_t TIMER[3] = {32768/2, 32768/5, 32768/8};

t_piece *createPiece() {
    uint32_t random_number;
    t_piece *new_piece;

    if (!(new_piece = malloc(sizeof(t_piece))))
        return NULL;

    switch (randInt(0, 6)) {
        case 0 :
            *new_piece = PIECE_0;
            break;
        case 1 :
            *new_piece = PIECE_1;
            break;
        case 2 :
            *new_piece = PIECE_2;
            break;
        case 3 :
            *new_piece = PIECE_3;
            break;
        case 4 :
            *new_piece = PIECE_4;
            break;
        case 5 :
            *new_piece = PIECE_5;
            break;
        case 6 :
            *new_piece = PIECE_6;
            break;
    }
    return new_piece;
}

uint8_t checkCaseMovement(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_pos checking_case) {
    if (checking_case.x < 0 || checking_case.x >= MATRIX_X_LENGTH) {
        return 0;
    }
    if (checking_case.y >= MATRIX_Y_LENGTH) {
        return 0;
    }
    if (checking_case.y >= 0) {
        if (matrix[checking_case.y][checking_case.x] != WHITE) {
            return 0;
        }
    }
    return 1;
}

uint8_t checkPieceMovement(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece piece) {
    uint8_t i;
    t_pos piece_pos;

    for (i = 0 ; i < SIZE_OF_PIECE ; i++) {
        piece_pos.x = piece.pos.x + piece.rotation_pos[piece.rotation_state][i].x;
        piece_pos.y = piece.pos.y + piece.rotation_pos[piece.rotation_state][i].y;
        if (!(checkCaseMovement(matrix, piece_pos))) {
            return 0;
        }
    }
    return 1;
}

void initMatrix(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH]) {
    uint8_t i;
    uint8_t j;

    for (i = 0; i < MATRIX_Y_LENGTH; i++) {
        for (j = 0; j < MATRIX_X_LENGTH; j++) {
            matrix[i][j] = WHITE;
        }
    }
}

void moveLeft(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece) {
    uint8_t i;
    t_piece checking_piece;
    checking_piece = *piece;

    checking_piece.pos.x--;

    if (checkPieceMovement(matrix, checking_piece)) {
        clearPiece(*piece);
        *piece = checking_piece;
        printPiece(*piece);
    }
}

void moveRight(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece) {
    uint8_t i;
    t_piece checking_piece;
    checking_piece = *piece;

    checking_piece.pos.x++;

    if (checkPieceMovement(matrix, checking_piece)) {
        clearPiece(*piece);
        *piece = checking_piece;
        printPiece(*piece);
    }
}

void leftRotation(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece) {
    t_piece checking_piece;

    checking_piece = *piece;

    if (checking_piece.rotation_state > 0) {
        checking_piece.rotation_state-- ;
    }
    else {
        checking_piece.rotation_state = NUMBER_OF_ROTATION - 1;
    }

    if (checkPieceMovement(matrix, checking_piece)) {
        clearPiece(*piece);
        *piece = checking_piece;
        printPiece(*piece);
    }
}

void rightRotation(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece) {
    t_piece checking_piece;
    checking_piece = *piece;

    if (checking_piece.rotation_state < NUMBER_OF_ROTATION - 1) {
        checking_piece.rotation_state++ ;
    }
    else {
        checking_piece.rotation_state = 0;
    }

    if (checkPieceMovement(matrix, checking_piece)) {
        clearPiece(*piece);
        *piece = checking_piece;
        printPiece(*piece);
    }
}

void moveDown(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece) {
    uint8_t i;
    t_pos piece_pos;

    clearPiece(*piece);
    piece->pos.y++;
    printPiece(*piece);
}

void moveDownMatrix(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], uint8_t y) {
    uint8_t i;
    uint8_t j;

    for (i = y; i > 0; i--) {
        for (j = 0; j < MATRIX_X_LENGTH; j++) {
            matrix[i][j] = matrix[i - 1][j];
        }
    }
    for (i = 0; i < MATRIX_X_LENGTH; i++) {
        matrix[0][i] = WHITE;
    }
    printScreen(matrix);
}

uint8_t checkMoveDown(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece) {
    t_piece checking_piece;

    checking_piece = *piece;
    checking_piece.pos.y++;

    if (checkPieceMovement(matrix, checking_piece)) {
        return 1;
    }
    return 0;
}

void verificationSuppressLine(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], uint32_t *score) {
    uint8_t i;
    uint8_t j;
    uint8_t line_count;
    uint8_t number_line_count;

    number_line_count = 0;
    for (i = 0; i < MATRIX_Y_LENGTH; i++) {
        line_count = 0;
        for (j = 0; j < MATRIX_X_LENGTH; j++) {
            if (matrix[i][j] != WHITE) {
                line_count++;
            }
        }
        if (line_count == MATRIX_X_LENGTH) {
            moveDownMatrix(matrix, i);
            number_line_count++;
        }
    }
    switch (number_line_count) {
        case 1 :
            *score += 40;
            break;
        case 2 :
            *score += 100;
            break;
        case 3 :
            *score += 300;
            break;
        case 4 :
            *score += 1200;
            break;
    }
    printScore(*score);
}

void placePiece(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece, uint32_t *score) {
    uint8_t i;
    t_pos piece_pos;

    for (i = 0; i < SIZE_OF_PIECE; i++) {
        piece_pos.x = piece->pos.x + piece->rotation_pos[piece->rotation_state][i].x;
        piece_pos.y = piece->pos.y + piece->rotation_pos[piece->rotation_state][i].y;
        matrix[piece_pos.y][piece_pos.x] = piece->color;
    }
    printPiece(*piece);
    free(piece);
    verificationSuppressLine(matrix, score);
}

void drop(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece, uint32_t *score) {
    t_piece checking_piece;

    checking_piece = *piece;

    while (checkPieceMovement(matrix, checking_piece)) {
        checking_piece.pos.y++;
        if (checkPieceMovement(matrix, checking_piece)) {
            clearPiece(*piece);
            *piece = checking_piece;
            printPiece(*piece);
        }
    }
    placePiece(matrix, piece, score);
}

uint8_t checkEnd(t_piece piece) {
    uint8_t i;
    t_pos piece_pos;
    for (i = 0; i < SIZE_OF_PIECE; i++) {
        piece_pos.y = piece.pos.y + piece.rotation_pos[piece.rotation_state][i].y;
        if (piece_pos.y < 0) {
            return 1;
        }
    }
    return 0;
}

uint8_t checkKbAction(uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH], t_piece *piece, kb_key_t *old_key, uint32_t *score) {
    kb_key_t key;

    key = kb_Data[1];

    if (*old_key == key)
        return 0;

    *old_key = key;

    switch (key) {
        case kb_Trace :
            moveRight(matrix, piece);
            break;
        case kb_Window :
            moveLeft(matrix, piece);
            break;
        case kb_Graph :
            rightRotation(matrix, piece);
            break;
        case kb_Yequ :
            leftRotation(matrix, piece);
            break;
        case kb_Zoom :
            drop(matrix, piece, score);
            return 1;
        case kb_2nd :
            if (checkMoveDown(matrix, piece)) {
                moveDown(matrix, piece);
            } else {
                placePiece(matrix, piece, score);
                return 1;
            }
            break;
        case kb_Mode :
            printPause();
            delay(1000);
            do {
                kb_Scan();
            } while (!(kb_Data[1] & kb_Mode || kb_Data[1] & kb_Del));
            clearPause();
            break;
    }
    return 0;
}

void gameOver() {
    printGameOver();
    while (!(kb_Data[1] & kb_Del)) {
        kb_Scan();
    }
}

uint8_t chooseDifficulty() {
    uint8_t difficulty;
    kb_key_t key;
    kb_key_t old_key;

    difficulty = NORMAL;
    kb_Scan();
    old_key = kb_Data[7];

    printDifficulty(difficulty);
    do {
        kb_Scan();
        key = kb_Data[7];

        if (key != old_key) {
            old_key = key;
            switch (key) {
                case kb_Right :
                    if (difficulty < HARD) {
                        difficulty++;
                        printDifficulty(difficulty);
                    }
                    break;
                case kb_Left :
                    if (difficulty > EASY) {
                        difficulty--;
                        printDifficulty(difficulty);
                    }
                    break;
            }
        }
    } while (!(kb_Data[6] & kb_Enter || kb_Data[1] & kb_Del));
    return difficulty;
}

void loop(uint8_t difficulty) {
    uint8_t matrix[MATRIX_Y_LENGTH][MATRIX_X_LENGTH];
    uint8_t end;
    uint32_t score;
    kb_key_t old_key;
    t_piece *piece;
    t_piece *next_piece;
    t_piece checking_piece;

    old_key = 0;
    end = 0;
    score = 0;

    gfx_FillScreen(BLACK);

    printScore(score);

    initMatrix(matrix);
    printScreen(matrix);

    if (!(piece = createPiece()))
        return;
    if (!(next_piece = createPiece()))
        return;

    printPiece(*piece);
    printNextPiece(*next_piece);

    timer_Control = TIMER1_DISABLE;
    timer_1_ReloadValue = timer_1_Counter = TIMER[difficulty];
    timer_Control = TIMER1_ENABLE | TIMER1_32K | TIMER1_0INT | TIMER1_DOWN;

    do {
        kb_Scan();
        if (checkKbAction(matrix, piece, &old_key, &score)) {
            timer_IntAcknowledge = TIMER1_RELOADED;

            piece = next_piece;
            if (!(next_piece = createPiece()))
                return;
            printPiece(*piece);
            printNextPiece(*next_piece);
        }

        if (timer_IntStatus & TIMER1_RELOADED) {
            timer_IntAcknowledge = TIMER1_RELOADED;

            checking_piece = *piece;
            checking_piece.pos.y++;

            if (checkPieceMovement(matrix, checking_piece)) {
                moveDown(matrix, piece);
            } else if (checkEnd(*piece)) {
                end = 1;
            } else {
                placePiece(matrix, piece, &score);
                piece = next_piece;
                if (!(next_piece = createPiece()))
                    return;
                printPiece(*piece);
                printNextPiece(*next_piece);
            }
        }
    } while (!(kb_Data[1] & kb_Del || end));

    if (end) {
        gameOver();
    }

    free(piece);
    free(next_piece);
}

