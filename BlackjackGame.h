#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "Deck.h"
#include "Player.h"
#include "SaveLoad.h"

class BlackjackGame {
public:
    BlackjackGame();
    void playGame();
    void displayBlackjackRules() const;

private:
    void playerTurn();
    void dealerTurn();
    void determineOutcome();

    Deck deck;
    Player player;
    Player dealer;
};

#endif
