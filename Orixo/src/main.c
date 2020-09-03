
#include "main.h"

uint8_t CURSOR[NUMBER_OF_CATEGORY + 1][2] = {
    {0, 3},
    {3, 30}, // Map X max
    {3, 20}, // Map Y max
    {1, 100}, // Amount of Numbers
    {1, 5},  // Number max
};

void initMap(t_game *game) {
    uint8_t i;
    uint8_t j;

    for (i = 0; i < game->x_max; ++i) {
        for (j = 0; j < game->y_max; ++j) {
            game->matrix[i][j].number = CASE_BLOCKED;
            game->matrix[i][j].old_number = CASE_BLOCKED;
            game->matrix[i][j].id = 0;
        }
    }
}

void kb_Move(t_pos *cursor_pos) {

    if (!kb_Data[7]) { return; }

    if (kb_Data[7] & kb_Right && cursor_pos->x < CURSOR[cursor_pos->y][1]) {
        ++(cursor_pos->x);
        if (cursor_pos->y) {
            MENU[CUSTOMIZE][cursor_pos->y] = cursor_pos->x;
        }
    }
    else if (kb_Data[7] & kb_Left && cursor_pos->x > CURSOR[cursor_pos->y][0]) {
        --(cursor_pos->x);
        if (cursor_pos->y) {
            MENU[CUSTOMIZE][cursor_pos->y] = cursor_pos->x;
        }
    }
    else if (kb_Data[7] & kb_Down && (cursor_pos->x == CUSTOMIZE || cursor_pos->y) && cursor_pos->y < NUMBER_OF_CATEGORY - 1) {
        ++(cursor_pos->y);
        cursor_pos->x = MENU[CUSTOMIZE][cursor_pos->y];
    }
    else if (kb_Data[7] & kb_Up && cursor_pos->y > 0) {
        --(cursor_pos->y);
        cursor_pos->x = MENU[CUSTOMIZE][cursor_pos->y];
    }
    else { return; }

    printMenu(cursor_pos);
    delay(WAITING_DELAY);
}

void menu(t_game *game) {
    t_pos cursor_pos;

    cursor_pos.x = EASY;
    cursor_pos.y = 0;

    delay(WAITING_DELAY);
    printMenu(&cursor_pos);

    do {
        kb_Scan();
        kb_Move(&cursor_pos);
    } while (!(kb_Data[6] & kb_Enter) && !(kb_Data[1] & kb_Del));

    if (cursor_pos.y) {
        cursor_pos.x = 3;
    }

    game->x_max = MENU[cursor_pos.x][1];
    game->y_max = MENU[cursor_pos.x][2];
    game->amount_number = MENU[cursor_pos.x][3];
    game->number_max = MENU[cursor_pos.x][4];
    game->win = FALSE;

    if (game->amount_number >= game->x_max * game->y_max) {
        game->amount_number = game->x_max * game->y_max;
    }
    if (!(kb_Data[1] & kb_Del)) {
        delay(WAITING_DELAY);
    }
}

void main() {
    t_game game;

    gfx_Begin();
    defPal();
    gfx_SetPalette(gfx_pal, sizeof_gfx_pal, 0);
    gfx_FillScreen(BLACK);
    gfx_SetTextFGColor(LIGHT_GREY);
    gfx_SetColor(BLACK);
    srandom(rtc_Time());

    menu(&game);
    initMap(&game);
    generateMap(&game);

    play(game);

    gfx_End();
}