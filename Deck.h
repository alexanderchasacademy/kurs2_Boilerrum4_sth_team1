#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
public:
    Deck();
    void shuffleDeck();
    Card drawCard();

private:
    std::vector<Card> cards;
};

#endif
