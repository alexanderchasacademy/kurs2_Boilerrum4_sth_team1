#include "BlackjackGame.h"
#include <iostream>

void BlackjackGame::displayRules() {
    std::cout << "Blackjack Rules:\n";
    std::cout << "1. Try to get as close to 21 as possible without going over.\n";
    std::cout << "2. Face cards are worth 10. Aces are worth 1 or 11.\n";
    std::cout << "3. Dealer must hit until reaching a minimum of 17.\n";
    std::cout << "4. You can hit or stand on your turn.\n";
    std::cout << "-------------------------------------\n";
}

void BlackjackGame::playGame(int &balance) {
    Deck deck;
    Player player(false);
    Player dealer(true);
    char choice;
    int bet;

    while (true) {
        player.clearHand();
        dealer.clearHand();

        std::cout << "\nBalance: $" << balance << "\nPlace your bet: ";
        std::cin >> bet;

        if (bet > balance) {
            std::cout << "You don't have enough money to bet that amount!\n";
            continue;
        }

        player.addCard(deck.drawCard());
        player.addCard(deck.drawCard());
        dealer.addCard(deck.drawCard());
        dealer.addCard(deck.drawCard());

        std::cout << "Dealer's visible card: " << dealer.getHand()[0].getCardString()
                  << " of " << dealer.getHand()[0].suit << "\n";

        bool playerBusted = false;

        while (true) {
            player.displayHand();

            if (player.calculateScore() > 21) {
                std::cout << "You bust! You lose $" << bet << "\n";
                balance -= bet;
                playerBusted = true;
                break;
            }

            std::cout << "Do you want to (H)it or (S)tand? ";
            std::cin >> choice;

            if (choice == 'S' || choice == 's') {
                break;
            } else if (choice == 'H' || choice == 'h') {
                player.addCard(deck.drawCard());
            }
        }

        if (!playerBusted && player.calculateScore() <= 21) {
            while (dealer.calculateScore() < 17) {
                dealer.addCard(deck.drawCard());
            }

            dealer.displayHand();

            int playerScore = player.calculateScore();
            int dealerScore = dealer.calculateScore();

            if (dealerScore > 21 || playerScore > dealerScore) {
                std::cout << "You win! You gain $" << bet << "\n";
                balance += bet;
            } else if (playerScore < dealerScore) {
                std::cout << "Dealer wins. You lose $" << bet << "\n";
                balance -= bet;
            } else {
                std::cout << "It's a tie! No money lost or won.\n";
            }
        }

        if (balance <= 0) {
            std::cout << "You're out of money! Game over.\n";
            break;
        }

        std::cout << "Play another round? (Y/N): ";
        std::cin >> choice;
        if (choice == 'N' || choice == 'n')
            break;
    }
}
