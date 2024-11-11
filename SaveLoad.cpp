#include "SaveLoad.h"
#include <fstream>
#include <iostream>

int SaveLoad::loadBalance() {
    std::ifstream inFile("savefile.txt");
    int balance = 1000;
    if (inFile) {
        inFile >> balance;
        std::cout << "Balance loaded from save: $" << balance << "\n";
    } else {
        std::cout << "No save file found. Starting with default balance: $" << balance << "\n";
    }
    return balance;
}

void SaveLoad::saveBalance(int balance) {
    std::ofstream outFile("savefile.txt");
    outFile << balance;
    std::cout << "Game saved! Balance: $" << balance << " has been saved.\n";
}
