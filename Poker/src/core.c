
#include "../inc/core.h"

uint8_t checkEnd(t_player *players, uint8_t number_of_player) {
    uint8_t i;
    uint8_t player_in_game;

    player_in_game = 0;

    for (i = 0; i < number_of_player; i++) {
        if (players[i].bankroll) {
            player_in_game++;
        }
    }

    if (player_in_game <= 1) { return 1; }

    return 0;
}

uint8_t getWinnerId(t_player *players, uint8_t number_of_player) {
    uint8_t i;

    for (i = 0; i < number_of_player; i++) {
        if (players[i].bankroll) { return i; }
    }
    return -1;
}

void play() {
    t_player *players;
    t_game game;
    uint8_t winner_id;

    menu(&game);

    if (!(players = initPlayers(game))) { return; }

    while (!checkEnd(players, game.param.number_of_player)) {
        gameRound(players, &game);
    }

    winner_id = getWinnerId(players, game.param.number_of_player);

    if (winner_id < 0 || winner_id >= game.param.number_of_player) { return; }

    printWinner(players[winner_id]);

    free(players);
}