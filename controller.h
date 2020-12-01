#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <memory>

class Table;
class Player;
class GameState;
class Deck;
class Display;

class Controller {
    int seed;
    std::shared_ptr<Table> table;
    std::vector<std::shared_ptr<Player>> players;
    std::shared_ptr<GameState> gameState;
    std::shared_ptr<Deck> deck;

    public:
      Controller(int seed);
      
      void addPlayer(char type, int playerNum);

      void createDeck();

      void shuffleDeck();

      void dealCards();

      void roundBegin();

      void roundReset();

      void setGameStatePlayers();

      void attachDisplay(std::shared_ptr<Display> &);

      std::shared_ptr<Table> getTable() const;

      void printDeck() const;

      void playerTurn();

      void playCard(char suit, char rank);

      void discard(char suit, char rank);
};

#endif