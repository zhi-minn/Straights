#ifndef PLAYER_VIEW_H
#define PLAYER_VIEW_H

#include "observer.h"
#include <vector>
#include <memory>

class Player;

class PlayerView : public Observer {
    std::vector<std::shared_ptr<Player>> players;
    int playerTurn;

    public:
      void setPlayers(std::vector<std::shared_ptr<Player>>);

      virtual void notify( Subject &whoNotified ) override;
};

#endif