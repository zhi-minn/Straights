#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>
#include <vector>
#include "subject.h"
#include "info.h"

class Subject;
class Player;

class GameState : public Subject {
    int currPlayer;
    int lowestScore;
    std::vector<std::shared_ptr<Player>> players;

    public:
      void setPlayers(std::vector<std::shared_ptr<Player>> &);

      bool roundEnd();

      bool gameEnd();

      std::vector<int> getWinner();

      void setCurrPlayer(int playerNum);

      void setLowestScore();

      void playerTurn();

      int getTurn() const;

      void nextTurn();

      virtual Info getInfo() override;
};

#endif