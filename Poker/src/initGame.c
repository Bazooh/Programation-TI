
#include "../inc/initGame.h"

void menu(t_game *game) {
    game->param.number_of_player = 5;
    game->param.money = 5000;
    game->param.small_blind = 20;
    game->small_blind_id = 4;
}