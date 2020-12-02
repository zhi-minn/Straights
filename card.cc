#include "card.h"
using namespace std;

Card::Card(char suit, int rank): suit{suit}, rank{rank} {}

char Card::getSuit() const {
    return suit;
}

int Card::getRank() const {
    return rank;
}

char Card::getDisplayRank() const {
    if (rank == 1) {
        return 'A';
    } else if (rank == 10) {
        return 'T';
    } else if (rank == 11) {
        return 'J';
    } else if (rank == 12) {
        return 'Q';
    } else {
        return 'K';
    }
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

    if (rank == 1 || rank > 9) {
        out << c.getDisplayRank();
    } else {
        out << rank;
    }
    out << suit;
    return out;
}