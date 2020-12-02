#ifndef TABLE_H
#define TABLE_H

#include <memory>
#include <vector>

class Card;

class Table {
    std::vector<std::vector<std::shared_ptr<Card>>> currCards;

    public:
      // Initialise table
      Table();

      // Sets up table suit piles
      void initialise();

      // Adds card to currCards (pile)
      void addCard(char suit, std::shared_ptr<Card>);
    
      // Checks whether table empty
      bool empty();

      // Checks card whether legal
      bool checkLegalPlay(std::shared_ptr<Card>);

      // Clears table
      void clearTable();
    
    friend std::ostream &operator<<(std::ostream &, const Table &);
};

std::ostream &operator<<(std::ostream &, const Table &);

#endif