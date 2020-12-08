#ifndef DEFAULT_STRAT_H
#define DEFAULT_STRAT_H

#include "strategy.h"

class Table;
class Card;

class DefaultStrategy : public Strategy {
    public:
      std::shared_ptr<Card> playStrategy(bool hasLegalPlays, std::shared_ptr<Table> table,
                        std::vector<std::shared_ptr<Card>> legalPlays,
                        std::vector<std::shared_ptr<Card>> hand) override;
};

#endif