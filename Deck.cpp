#include "Deck.h"
#include <algorithm>
#include <random>
#include <ctime>

Deck::Deck() {
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    for (const std::string &suit : suits) {
        for (int value = 1; value <= 13; ++value) {
            cards.push_back({suit, value});
        }
    }
    shuffleDeck();
}

void Deck::shuffleDeck() {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::shuffle(cards.begin(), cards.end(), eng);
}

Card Deck::drawCard() {
    Card card = cards.back();
    cards.pop_back();
    return card;
}

