
#include "../inc/display.h"

void printSizeOfDeck(t_deck *deck) {
    printf("length : %d\n", sizeOfDeck(deck));
}

void printCard(t_card card) {
    printf("%d %2d", card.color, card.value);
}

void printDeck(t_deck *deck) {
    printSizeOfDeck(deck);
    while (deck->next) {
        deck = deck->next;
        printCard(deck->card);
        if (deck->next && deck->card.color == deck->next->card.color) {
            printf(" | ");
        } else {
            printf("\n");
        }
    }
    printf("\n");
}

void printPlayer(t_player player) {
    uint8_t i;

    printf("name     : %s\n", player.name);
    printf("password : %d\n", player.password);
    printf("money    : %d\n", player.bankroll);
    printf("hand     : ");

    for (i = 0; i < NUMBER_OF_CARD_IN_HAND; i++) {
        printCard(player.hand[i]);
        if (i != NUMBER_OF_CARD_IN_HAND - 1) { printf(" | "); }
    }
    printf("\n");

    printf("fold     : %d\n", player.fold);
    printf("ready    : %d\n", player.ready);

    for (i = 0; i < NUMBER_OF_ROUND; i++) {
        printf("bet[%d]   : %d", i, player.bet[i]);
    }
    printf("\n\n");
}

void printAllPlayers(t_player *players, uint8_t number_of_player) {
    uint8_t i;

    for (i = 0; i < number_of_player; i++) {
        printPlayer(players[i]);
    }
}

void printGameInfo(t_player *players, t_game game) {
    uint8_t i;
    uint8_t ready;

    ready = 0;

    printf("bet        : %d\n", game.round.bet);
    printf("pot        : %d\n", game.pot);
    for (i = 0; i < game.param.number_of_player; i++) {
        if (players[i].ready) { ready++; }
    }
    printf("ready      : %d\n", ready);
    printf("last_raise : %d\n",game.round.last_raise_id);

    printf("\n");
}

void printPossibleBet(uint32_t *possible_bet) {
    uint32_t i;

    for (i = 1; i <= possible_bet[0]; i++) {
        printf("%d  ", possible_bet[i]);
    }
    printf("\n");
}

void printBoard(t_card *board) {
    uint8_t i;

    i = 0;

    for (i = 0; i < NUMBER_OF_CARD_IN_BOARD; i++) {
        printCard(board[i]);
        if (i != NUMBER_OF_CARD_IN_BOARD - 1) {
            printf(" | ");
        }
    }
    printf("\n");
}

void printWinner(t_player winner) {
    printf("Le gagnant est : %s\n", winner.name);
}