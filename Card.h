#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    Card(const std::string& suit, int value);

    std::string getSuit() const;
    int getValue() const;
    std::string toString() const;

private:
    std::string suit;
    int value;
};

#endif
