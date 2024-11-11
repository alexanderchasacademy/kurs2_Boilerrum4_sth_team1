#include "BlackjackGame.h"
#include <iostream>

BlackjackGame::BlackjackGame() : player(SaveLoad::loadBalance()), dealer(0) {}

void BlackjackGame::displayBlackjackRules() const {
    std::cout << "Blackjack Rules:\n";
    std::cout << "1. Try to get as close to 21 as possible without going over.\n";
    std::cout << "2. Face cards are worth 10. Aces are worth 1 or 11.\n";
    std::cout << "3. Dealer must hit until reaching a minimum of 17.\n";
    std::cout << "4. You can hit or stand on your turn.\n";
}

void BlackjackGame::playGame() {
    char choice;
    while (true) {
        player.clearHand();
        dealer.clearHand();
        deck.shuffleDeck();
        
        player.addCardToHand(deck.drawCard());
        player.addCardToHand(deck.drawCard());
        dealer.addCardToHand(deck.drawCard());
        dealer.addCardToHand(deck.drawCard());

        std::cout << "Dealer's visible card: "  ;dealer.displayHand();

        playerTurn();
        if (player.calculateScore() > 21) {
            std::cout << "You bust! You lose.\n";
        } else {
            dealerTurn();
            determineOutcome();
        }

        std::cout << "Play another round? (Y/N): ";
        std::cin >> choice;
        if (choice == 'N' || choice == 'n') break;
    }
    SaveLoad::saveBalance(player.getBalance());
}

void BlackjackGame::playerTurn() {
    char choice;
    while (true) {
        player.displayHand();
        std::cout << "Do you want to (H)it or (S)tand? ";
        std::cin >> choice;
        if (choice == 'S' || choice == 's') break;
        if (choice == 'H' || choice == 'h') player.addCardToHand(deck.drawCard());
    }
}

void BlackjackGame::dealerTurn() {
    while (dealer.calculateScore() < 17) {
        dealer.addCardToHand(deck.drawCard());
    }
    dealer.displayHand();
}

void BlackjackGame::determineOutcome() {
    int playerScore = player.calculateScore();
    int dealerScore = dealer.calculateScore();

    if (dealerScore > 21 || playerScore > dealerScore) {
        std::cout << "You win!\n";
        player.updateBalance(100);
    } else if (playerScore < dealerScore) {
        std::cout << "Dealer wins. You lose.\n";
        player.updateBalance(-100);
    } else {
        std::cout << "It's a tie.\n";
    }
}
