#ifndef _INFO_H
#define _INFO_H

#include <memory>
#include <vector>

class Card;

struct Info {
    std::vector<std::shared_ptr<Card>> playerHand;
    std::vector<std::shared_ptr<Card>> legalPlays;
};

#endif
