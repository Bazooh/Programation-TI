
#include "../inc/deck.h"

void removeDeckCard(t_deck *deck, uint8_t elem_place) {
    uint8_t i;
    t_deck *card_to_free;

    if (elem_place < 1) { return; }

    for (i = 0; i < elem_place - 1; i++) {
        if (!deck->next) { return; }
        deck = deck->next;
    }

    card_to_free = deck->next;
    deck->next = card_to_free->next;
    free(card_to_free);
}

void freeDeck(t_deck *deck) {
    t_deck *card_to_free;

    deck = deck->next;

    while (deck->next) {
        card_to_free = deck;
        deck = deck->next;
        free(card_to_free);
    }
    free(deck);
}

t_deck *createCard(uint8_t color, uint8_t value) {
    t_deck *new_elem;

    if (!(new_elem = malloc(sizeof(t_deck)))) { return NULL; }

    initCard(&new_elem->card, color, value);
    new_elem->next = NULL;

    return new_elem;
}

void initDeck(t_deck *deck) {
    uint8_t color;
    uint8_t value;

    for (color = 1; color <= NUMBER_OF_COLOR; color++) {
        for (value = 1; value <= NUMBER_OF_VALUE; value++) {
            if (!(deck->next = createCard(color, value))) { return; }
            deck = deck->next;
        }
    }
}

uint8_t sizeOfDeck(t_deck *list) {
    uint8_t i;

    i = 0;

    while (list->next) {
        list = list->next;
        i++;
    }
    return i;
}