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
      
      void announceWinners();

      void makePlayers();

      void addPlayer(char type, int playerNum);

      char playerType();

      void createDeck();

      void shuffleDeck();

      void dealCards();

      void roundBegin();

      bool roundEnd();

      void roundReset();

      bool gameEnd();

      void setGameStatePlayers();

      std::vector<std::shared_ptr<Player>> getPlayers() const;

      void attachDisplay(std::shared_ptr<Display> &);

      std::shared_ptr<Table> getTable() const;

      void printDeck() const;

      void playerTurn();

      bool isComputerTurn();

      void autoplayComputer();

      void nextTurn();

      void ragequit();

      void playCard(char suit, char rank);

      void discard(char suit, char rank);

      void tabulateScore();
};

#endif