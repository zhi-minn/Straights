#ifndef _INFO_H
#define _INFO_H

#include <memory>
#include <vector>

class Card;
class Table;
class Player;

struct Info {
    std::shared_ptr<Table> table;
    std::vector<std::shared_ptr<Player>> players;
    int currPlayer;
};

#endif
