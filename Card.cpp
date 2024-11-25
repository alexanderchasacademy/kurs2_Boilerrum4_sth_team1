#include "Card.h"

std::string Card::getCardString() const {
    if (value == 1) return "Ace";
    if (value == 11) return "Jack";
    if (value == 12) return "Queen";
    if (value == 13) return "King";
    return std::to_string(value);
}