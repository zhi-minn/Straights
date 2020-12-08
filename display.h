#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <vector>
#include <memory>
#include "observer.h"

class Subject;
class Table;
class Card;

class Display: public Observer {
    std::shared_ptr<Table> table;
    std::vector<std::shared_ptr<Card>> playerHand;
    std::vector<std::shared_ptr<Card>> legalPlays;

    public:
      virtual void notify( Subject & whoNotified ) override;

    friend std::ostream &operator<<(std::ostream &out, const Display &td);
};

std::ostream &operator<<(std::ostream &, const Display &);

#endif
