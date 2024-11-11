#include "Card.h"

Card::Card(const std::string& suit, int value) : suit(suit), value(value) {}

std::string Card::getSuit() const {
    return suit;
}

int Card::getValue() const {
    return value;
}

std::string Card::toString() const {
    return (value == 1 ? "A" : (value > 10 ? "10" : std::to_string(value))) + " of " + suit;
}
