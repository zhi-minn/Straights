#ifndef STRATEGY_H
#define STRATEGY_H

#include <memory>
#include <vector>

class Table;
class Card;

class Strategy {
    public:
      virtual ~Strategy() {}
      virtual std::shared_ptr<Card> playStrategy(bool hasLegalPlays, std::shared_ptr<Table> table,
                          std::vector<std::shared_ptr<Card>> legalPlays,
                          std::vector<std::shared_ptr<Card>> hand) = 0;
};

#endif