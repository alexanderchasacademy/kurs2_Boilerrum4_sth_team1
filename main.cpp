#include "BlackjackGame.h"
#include "SaveLoad.h"
#include <iostream>

int main() {
    int balance = 1000;
    char choice;
    bool gameRunning = true;

    while (gameRunning) {
        std::cout << "\nMenu:\n";
        std::cout << "1. View Game Rules\n";
        std::cout << "2. Start Game\n";
        std::cout << "3. Load Game\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
        case '1':
            BlackjackGame::displayRules();
            break;
        case '2':
            balance = 1000;
            BlackjackGame::playGame(balance);
            break;
        case '3':
            balance = SaveLoad::loadBalance();
            BlackjackGame::playGame(balance);
            break;
        case '4': {
            char saveChoice;
            std::cout << "Would you like to save your game before exiting? (Y/N): ";
            std::cin >> saveChoice;
            if (saveChoice == 'Y' || saveChoice == 'y') {
                SaveLoad::saveBalance(balance);
            }
            gameRunning = false;
            std::cout << "Exiting the game.\n";
            break;
        }
        default:
            std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
