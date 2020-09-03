
#include "../inc/round.h"

void distributeCardToPlayer(t_deck *deck, t_player *player) {
    uint32_t randomNumber;
    uint8_t i;
    uint8_t j;
    t_deck *checking_card;
    uint8_t deck_size;

    for (i = 0; i < NUMBER_OF_CARD_IN_HAND; i++) {
        deck_size = sizeOfDeck(deck);

        if (!deck_size) {
            initDeck(deck);
            deck_size = sizeOfDeck(deck);
        }

        randomNumber = (rand() % deck_size) + 1;
        checking_card = deck;

        for (j = 0; j < randomNumber; j++) {
            checking_card = checking_card->next;
        }

        player->hand[i] = checking_card->card;
        removeDeckCard(deck, randomNumber);
    }
}

void distributeCardToAllPlayers(t_deck *deck, t_player *players, t_game game) {
    uint8_t i;
    uint8_t number_of_player = game.param.number_of_player;

    for (i = 0; i < number_of_player; i++) {
        distributeCardToPlayer(deck, &players[i]);
    }
}

void initBoard(t_card *board) {
    uint8_t i;

    for (i = 0; i < NUMBER_OF_CARD_IN_BOARD; i++) {
        initCard(&board[i], 0, 0);
    }
}

void addCardToBoard(t_deck *deck, t_card *board, uint8_t number) {
    uint32_t randomNumber;
    uint8_t i;
    t_deck *checking_card;
    uint8_t deck_size;

    deck_size = sizeOfDeck(deck);

    if (!deck_size) {
        initDeck(deck);
        deck_size = sizeOfDeck(deck);
    }

    randomNumber = (rand() % deck_size) + 1;
    checking_card = deck;

    for (i = 0; i < randomNumber; i++) {
        checking_card = checking_card->next;
    }

    board[number] = checking_card->card;
    removeDeckCard(deck, randomNumber);
}

void initGameRound(t_deck *deck, t_player *players, t_game *game) {
    initDeck(deck);
    distributeCardToAllPlayers(deck, players, *game);
}

void gameRound(t_player *players, t_game *game) {
    t_deck deck;
    uint8_t board_id;

    initGameRound(&deck, players, game);

    initBoard(game->round.board);
    game->round.round_id = 0;
    betFirstRound(players, game);

    for (board_id = 0; board_id < 5; board_id++) {
        addCardToBoard(&deck, game->round.board, board_id);
    }
    printBoard(game->round.board);
    game->round.round_id = 1;
    betRound(players, game);

    addCardToBoard(&deck, game->round.board, board_id);
    printBoard(game->round.board);
    game->round.round_id = 2;
    betRound(players, game);

    board_id++;

    addCardToBoard(&deck, game->round.board, board_id);
    printBoard(game->round.board);
    game->round.round_id = 3;
    betRound(players, game);

    freeDeck(&deck);
}