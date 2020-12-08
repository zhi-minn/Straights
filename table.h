#ifndef TABLE_H
#define TABLE_H

#include <memory>
#include <vector>

class Card;

class Table {
    std::vector<std::vector<std::shared_ptr<Card>>> currCards;

    static bool sortByRank(std::shared_ptr<Card> c1, std::shared_ptr<Card> c2);

    public:
      // Initialise table
      Table();

      // Adds card to currCards (pile)
      void addCard(char suit, std::shared_ptr<Card>);

      // Checks card whether legal
      bool checkLegalPlay(std::shared_ptr<Card>);

      // Clears table
      void clearTable();

      // Checks whether table empty
      bool empty();

      // Sets up table suit piles
      void initialise();
    
    friend std::ostream &operator<<(std::ostream &, const Table &);
};

std::ostream &operator<<(std::ostream &, const Table &);

#endif