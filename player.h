#ifndef PLAYER_H
#define PLAYER_H

#include "subject.h"
#include "info.h"
#include <memory>
#include <vector>

class Table;
class Card;

struct PlayerInfo {
  int number;
  char type;
  int score;
  std::vector<std::shared_ptr<Card>> hand;
  std::vector<std::shared_ptr<Card>> discards;
  std::vector<std::shared_ptr<Card>> legalPlays;
  std::shared_ptr<Table> table;
};

class Player {
    int playerNumber;
    char playerType;
    std::vector<std::shared_ptr<Card>> discards;
    int score;

    int convertRank(char rank);
    void validateRank(int rank);
    std::shared_ptr<Card> getCard(int rank, char suit, bool playCard);
  
    protected:
      std::shared_ptr<Table> table;
      std::vector<std::shared_ptr<Card>> hand;
      std::vector<std::shared_ptr<Card>> legalPlays;

      int findCard(std::shared_ptr<Card>);

    public:
      // Initialise Player with table and player number
      Player(std::shared_ptr<Table> table, int playerNum, char playerType);

      // Adds card to hand
      void addCard(std::shared_ptr<Card>);

      // Empties hand and discard pile
      void clear();

      // Dicards card
      void discard(std::shared_ptr<Card>);

      // Returns player type
      PlayerInfo getInfo() const;

      // Checks whether any legal plays
      bool hasLegalPlays();

      // Checks if player has 7S
      bool has7S() const;

      // Sends card to table
      virtual void play(std::shared_ptr<Card>) = 0;

      // Calculates legal plays
      void setLegalPlays();

      // Updates score
      void tabulateScore();

      // Data transfer functions
      void update(std::vector<std::shared_ptr<Card>> hand,
                  std::vector<std::shared_ptr<Card>> discards,
                  std::vector<std::shared_ptr<Card>> legalPlays,
                  int score);

      // Validates card to be played
      void validateCard(char rank, char suit);

      // Validates discard
      void validateDiscard(char rank, char suit);
};

#endif