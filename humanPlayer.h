#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include <memory>
#include "player.h"

class Table;

class HumanPlayer : public Player {
    public:
      HumanPlayer(std::shared_ptr<Table> table, int playerNum, char playerType);
};

#endif