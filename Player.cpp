#include "Player.h"
#include <iostream>

Player::Player(bool dealer) : isDealer(dealer) {}

void Player::addCard(const Card &card) {
    hand.push_back(card);
}

int Player::calculateScore() const {
    int score = 0, aces = 0;
    for (const Card &card : hand) {
        if (card.value >= 10)
            score += 10;
        else if (card.value == 1) {
            score += 11;
            ++aces;
        } else
            score += card.value;

        while (score > 21 && aces > 0) {
            score -= 10;
            --aces;
        }
    }
    return score;
}

void Player::displayHand() const {
    std::cout << (isDealer ? "Dealer's" : "Your") << " cards: ";
    for (const Card &card : hand) {
        std::cout << (card.value == 1 ? "A" : (card.value > 10 ? "10" : std::to_string(card.value)))
                  << " of " << card.suit << ", ";
    }
    std::cout << " (Score: " << calculateScore() << ")\n";
}

const std::vector<Card> &Player::getHand() const {
    return hand;
}

void Player::clearHand() {
    hand.clear();
}
