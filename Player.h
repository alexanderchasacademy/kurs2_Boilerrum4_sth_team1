#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>

class Player {
public:
    Player(int balance = 1000);

    void addCardToHand(const Card& card);
    void clearHand();
    int calculateScore() const;
    int getBalance() const;
    void updateBalance(int amount);
    void displayHand() const;

private:
    std::vector<Card> hand;
    int balance;
};

#endif
