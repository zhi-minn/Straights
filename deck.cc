#include "deck.h"
#include "card.h"
#include <algorithm>
#include <random>
using namespace std;

Deck::Deck(int seed): seed{seed} {}

shared_ptr<Card> Deck::getCard(int pos) const {
    return cards[pos];
}

int Deck::getSize() {
    return cards.size();
}

void Deck::makeCards() {
    char suit;
    for (int i = 1; i <= 52; i++) {
        if (i <= 13) {
            suit = 'C';
        } else if (i <= 26) {
            suit = 'D';
        } else if (i <= 39) {
            suit = 'H';
        } else {
            suit = 'S';
        }
        if (i == 13 || i == 26 || i == 39 || i == 52) {
            cards.emplace_back(make_shared<Card>(suit, 13));
        } else {
            cards.emplace_back(make_shared<Card>(suit, i%13));
        }
    }
}

void Deck::shuffleDeck() {
    std::default_random_engine rng{seed};
    std::shuffle(cards.begin(), cards.end(), rng);
}

ostream &operator<<(ostream & out, const Deck & deck) {
    int count = 0;
    for (auto card : deck.cards) {
        out << *card << " ";
        count++;
        if (count == 13) {
            count = 0;
            out << endl;
        }
    }
    return out;
}