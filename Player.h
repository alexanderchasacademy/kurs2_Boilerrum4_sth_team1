#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Card.h"

class Player {
private:
    std::vector<Card> hand;
    bool isDealer;

public:
    Player(bool dealer = false);
    void addCard(const Card &card);
    int calculateScore() const;
    void displayHand() const;
    const std::vector<Card> &getHand() const;
    void clearHand();
};

#endif
