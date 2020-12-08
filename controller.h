#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <memory>

class Table;
class Player;
class GameState;
class Deck;
class Display;
class ScoreView;

class Controller {
    int seed;
    std::shared_ptr<Table> table;
    std::vector<std::shared_ptr<Player>> players;
    std::shared_ptr<GameState> gameState;
    std::shared_ptr<Deck> deck;

    public:
      Controller(int seed);
      
      void addPlayer(char type, int playerNum);;
      
      void announceWinners();

      void attachObservers(std::shared_ptr<Display> &, std::shared_ptr<ScoreView> &);

      void autoplayComputer(); 

      void createDeck();

      void dealCards();

      void discard(char suit, char rank);

      bool gameEnd();

      std::vector<std::shared_ptr<Player>> getPlayers() const;

      std::shared_ptr<Table> getTable() const;

      bool isComputerTurn();

      void makePlayers();

      void nextTurn();

      void playCard(char suit, char rank);

      void playerTurn();

      void printDeck() const;

      void ragequit();

      void roundBegin();

      bool roundEnd();

      void roundReset();

      void setGameStatePlayers();

      void shuffleDeck();

      void tabulateScore();
};

#endif