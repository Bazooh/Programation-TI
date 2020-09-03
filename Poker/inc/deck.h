
#ifndef PROJETS_DECK_H
#define PROJETS_DECK_H

# include <stdint.h>
# include <stdlib.h>

# include "card.h"

typedef struct s_deck {
    t_card card;
    struct s_deck *next;
}              t_deck;

void removeDeckCard(t_deck *deck, uint8_t elem_place);
void freeDeck(t_deck *deck);
void initDeck(t_deck *deck);
uint8_t sizeOfDeck(t_deck *list);

#endif //PROJETS_DECK_H