#ifndef _INFO_H
#define _INFO_H

#include <memory>
#include <vector>

class Card;
class Table;

struct Info {
    std::shared_ptr<Table> table;
    std::vector<std::shared_ptr<Card>> playerHand;
    std::vector<std::shared_ptr<Card>> legalPlays;
};

#endif
