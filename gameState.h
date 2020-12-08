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
      bool gameEnd();

      virtual Info getInfo() override;

      int getTurn() const;
    
      std::vector<int> getWinner();
    
      void nextTurn();

      void playerTurn();

      bool roundEnd();

      void setCurrPlayer(int playerNum);

      void setLowestScore();

      void setPlayers(std::vector<std::shared_ptr<Player>> &);
};

#endif