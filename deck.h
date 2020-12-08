#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <memory>
#include <vector>

class Card;

class Deck {
    std::vector<std::shared_ptr<Card>> cards;
    int seed;

    public:
      Deck(int seed);

      std::shared_ptr<Card> getCard(int pos) const;

      int getSize();

      void makeCards();

      void shuffleDeck();

    friend std::ostream & operator<<(std::ostream &, const Deck &);
};

std::ostream & operator<<(std::ostream &, const Deck &);

#endif