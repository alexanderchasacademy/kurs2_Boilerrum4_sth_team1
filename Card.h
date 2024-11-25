#ifndef CARD_H
#define CARD_H

#include <string>

struct Card {
    std::string suit;
    int value;

    std::string getCardString() const; // Converts card value to a string for display
};

#endif
