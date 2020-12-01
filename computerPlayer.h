#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include <memory>
#include "player.h"

class Table;

class ComputerPlayer : public Player {
    public:
      ComputerPlayer(std::shared_ptr<Table> table, int playerNum);

      void autoPlay();
};

#endif