#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include <memory>
#include "player.h"

class Table;
class Card;

class ComputerPlayer : public Player {
  public:
    ComputerPlayer(std::shared_ptr<Table> table, int playerNum, char playerType);

    ComputerPlayer(std::shared_ptr<Table> table, int playerNum, char playerType,
                    std::vector<std::shared_ptr<Card>> hand,
                    std::vector<std::shared_ptr<Card>> discards,
                    std::vector<std::shared_ptr<Card>> legalPlays,
                    int score);

    void play(std::shared_ptr<Card> = nullptr) override;

    bool specialRank(std::shared_ptr<Card>);
};

#endif