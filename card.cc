#include "card.h"
using namespace std;

Card::Card(char suit, int rank): suit{suit}, rank{rank} {}

char Card::getSuit() const {
    return suit;
}

int Card::getRank() const {
    return rank;
}

bool operator==(const Card &c1, const Card &c2) {
    if (c1.getSuit() == c2.getSuit() && c1.getRank() == c2.getRank()) {
        return true;
    }
    return false;
}

ostream &operator<<(ostream & out, const Card & c) {
    int rank = c.getRank();
    char suit = c.getSuit();
    char displayRank;
    if (rank == 1) {
        displayRank = 'A';
    } else if (rank == 10) {
        displayRank = 'T';
    } else if (rank == 11) {
        displayRank = 'J';
    } else if (rank == 12) {
        displayRank = 'Q';
    } else if (rank == 13) {
        displayRank = 'K';
    }
    if (rank == 1 | rank > 9) {
        out << displayRank;
    } else {
        out << rank;
    }
    out << suit;
    return out;
}