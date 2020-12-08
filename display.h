#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <vector>
#include <memory>
#include "observer.h"

class Subject;
class Table;
class Card;
class Player;

class Display: public Observer {
    std::shared_ptr<Table> table;
    std::vector<std::shared_ptr<Player>> players;
    int currPlayer;

    public:
      virtual void notify( Subject & whoNotified ) override;

    friend std::ostream &operator<<(std::ostream &out, const Display &display);
};

std::ostream &operator<<(std::ostream &, const Display &);

#endif
