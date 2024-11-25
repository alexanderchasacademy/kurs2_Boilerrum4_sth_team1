#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "Deck.h"
#include "Player.h"
#include "SaveLoad.h"

class BlackjackGame {
public:
    static void displayRules();
    static void playGame(int &balance);
};

#endif
