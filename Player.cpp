#include "Player.h"
#include <iostream>

Player::Player(int balance) : balance(balance) {}

void Player::addCardToHand(const Card& card) {
    hand.push_back(card);
}

void Player::clearHand() {
    hand.clear();
}

int Player::calculateScore() const {
    int score = 0, aces = 0;
    for (const Card& card : hand) {
        if (card.getValue() >= 10)
            score += 10;
        else if (card.getValue() == 1) {
            score += 11;
            aces++;
        } else {
            score += card.getValue();
        }
    }
    while (score > 21 && aces > 0) {
        score -= 10;
        aces--;
    }
    return score;
}

int Player::getBalance() const {
    return balance;
}

void Player::updateBalance(int amount) {
    balance += amount;
}

void Player::displayHand() const {
    for (const Card& card : hand) {
        std::cout << card.toString() << ", ";
    }
    std::cout << "(Score: " << calculateScore() << ")\n";
}
