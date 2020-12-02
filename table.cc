#include "table.h"
#include "card.h"
#include <iostream>
using namespace std;

const vector<string> suits = {"Clubs:", "Diamonds:", "Hearts:", "Spades:"};

Table::Table() {
    initialise();
}

void Table::initialise() {
    for (int i = 0; i < 4; i++) {
        currCards.emplace_back(vector<shared_ptr<Card>>());
    }
}

void Table::addCard(char suit, shared_ptr<Card> card) {
    int suitOrder;
    switch(suit) {
        case 'C':
            suitOrder = 0;
            break;
        case 'D':
            suitOrder = 1;
            break;
        case 'H':
            suitOrder = 2;
            break;
        case 'S':
            suitOrder = 3;
            break;
    }
    currCards[suitOrder].emplace_back(card);
}

bool Table::empty() {
    return (currCards[0].empty() && currCards[1].empty() &&
            currCards[2].empty() && currCards[3].empty());
}

bool Table::checkLegalPlay(shared_ptr<Card> card) {
    char suit = card->getSuit();
    int rank = card->getRank();
    int suitIndex;
    switch(suit) {
        case 'C':
            suitIndex = 0;
            break;
        case 'D':
            suitIndex = 1;
            break;
        case 'H':
            suitIndex = 2;
            break;
        case 'S':
            suitIndex = 3;
            break;
    }

    if (rank == 7) {
        return true;
    }


    vector<shared_ptr<Card>> pile = currCards[suitIndex];
    for (int i = 0; i < pile.size(); i++) {
        if (rank == pile[i]->getRank() + 1 || rank == pile[i]->getRank() - 1) {
            return true;
        }
    }
    return false;
}

void Table::clearTable() {
    for (auto &cardRow : currCards) {
        cardRow.clear();
    }
}

ostream &operator<<(ostream &out, const Table &table) {
    out << "Cards on the table:" << endl;
    for (int i = 0; i < 4; i++) {
        out << suits[i] << " ";
        for (auto card : table.currCards[i]) {
            if (card->getRank() == 1 || card->getRank() > 9) {
                out << card->getDisplayRank();
            } else {
                out << card->getRank();
            }
            out << " ";
        }
        out << endl;
    }
    return out;
}