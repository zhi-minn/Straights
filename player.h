#ifndef PLAYER_H
#define PLAYER_H

#include "subject.h"
#include "info.h"
#include <memory>
#include <vector>

class Table;
class Card;

class Player {
    std::shared_ptr<Table> table;
    std::vector<std::shared_ptr<Card>> hand;
    std::vector<std::shared_ptr<Card>> discards;
    std::vector<std::shared_ptr<Card>> legalPlays;
    int playerNumber;
    int score;

    int convertRank(char rank);
    void validateRank(int rank);
    std::shared_ptr<Card> getCard(int rank, char suit);
    // Finds index of card in hand
    int findCard(std::shared_ptr<Card>);
  
    public:
      // Initialise Player with table and player number
      Player(std::shared_ptr<Table> table, int playerNum);

      // Checks if player has 7S
      bool has7S() const;

      // Sends card to table
      void play(std::shared_ptr<Card>);

      // Validates card to be played
      void validateCard(char rank, char suit);

      // Adds card to hand
      void addCard(std::shared_ptr<Card>);

      // Dicards card
      void discard(std::shared_ptr<Card>);

      // Validates discard
      void validateDiscard(char rank, char suit);

      // Calculates legal plays
      void setLegalPlays();

      // Checks whether any legal plays
      bool hasLegalPlays();

      // Returns legal plays
      std::vector<std::shared_ptr<Card>> getLegalPlays() const;

      // Returns current hand
      std::vector<std::shared_ptr<Card>> getHand() const;

      // Returns player number
      int getNum() const;

      // Returns score
      int getScore() const;

      // Empties hand and discard pile
      void clear();
};

#endif