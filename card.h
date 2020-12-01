#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
    char suit;
    int rank;

    public:
      Card(char suit, int rank);
      char getSuit() const;
      int getRank() const;

    friend std::ostream & operator<<(std::ostream &, const Card &);
};

bool operator==(const Card &c1, const Card &c2);

std::ostream & operator<<(std::ostream &, const Card &);

#endif