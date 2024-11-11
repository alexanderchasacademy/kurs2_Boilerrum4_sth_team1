#include "BlackjackGame.h"
#include <iostream>

int main() {
    BlackjackGame game;
    char choice;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. View Game Rules\n";
        std::cout << "2. Start Game\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == '1') {
            game.displayBlackjackRules();
        } else if (choice == '2') {
            game.playGame();
        } else if (choice == '3') {
            break;
        } else {
            std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
