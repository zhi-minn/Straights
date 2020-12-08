#include "controller.h"
#include "table.h"
#include "humanPlayer.h"
#include "computerPlayer.h"
#include "deck.h"
#include "gameState.h"
#include "display.h"
#include "scoreView.h"
#include "card.h"
#include "strategy.h"
#include <assert.h>
#include <iostream>
using namespace std;

Controller::Controller(int seed): seed{seed} {
    table = make_shared<Table>();
    gameState = make_shared<GameState>();
    deck = make_shared<Deck>(seed);
}

void Controller::addPlayer(char type, int playerNum) {
    assert(type == 'c' || type == 'h');
    if (type == 'h') {
        players.emplace_back(make_shared<HumanPlayer>(table, playerNum, type));
    } else {
        players.emplace_back(make_shared<ComputerPlayer>(table, playerNum, type));
    }
}

void Controller::announceWinners() {
    vector<int> winnerNumbers = gameState->getWinner();
    for (auto number : winnerNumbers) {
        cout << "Player" << number << " wins!" << endl;
    }
}

void Controller::attachObservers(shared_ptr<Display> &display, shared_ptr<ScoreView> &sv) {
    gameState->attach(display.get());
    gameState->attach(sv.get());
}

void Controller::autoplayComputer() {
    shared_ptr<Player> player = players[gameState->getTurn()];
    dynamic_pointer_cast<ComputerPlayer>(player)->play();
}

void Controller::createDeck() {
    deck->makeCards();
}

void Controller::dealCards() {
    
    for (int i = 0; i < deck->getSize(); i++) {
        if (i <= 12) {
            players[0]->addCard(deck->getCard(i));
        } else if (i <= 25) {
            players[1]->addCard(deck->getCard(i));
        } else if (i <= 38) {
            players[2]->addCard(deck->getCard(i));
        } else {
            players[3]->addCard(deck->getCard(i));
        }
    }
}

void Controller::discard(char rank, char suit) {
    int turn = gameState->getTurn();
    players[turn]->validateDiscard(rank, suit);
    gameState->nextTurn();
}

bool Controller::gameEnd() {
    return gameState->gameEnd();
}

vector<shared_ptr<Player>> Controller::getPlayers() const {
    return players;
}

shared_ptr<Table> Controller::getTable() const {
    return table;
}

bool Controller::isComputerTurn() {
    shared_ptr<Player> player = players[gameState->getTurn()];
    if (player->getInfo().type == 'c') {
        return true;
    }
    return false;
}

void Controller::makePlayers() {
    char inp;
    for (int i = 1; i <= 4; i++) {
        cout << "Is Player" << i << " a human(h) or a computer(c)?" << endl;
        cout << ">";
        cin >> inp;
        addPlayer(inp, i);
    }
}

void Controller::nextTurn() {
    gameState->nextTurn();
}

void Controller::playCard(char rank, char suit) {
    int turn = gameState->getTurn();
    players[turn]->validateCard(rank, suit);    
    gameState->nextTurn();
}

void Controller::playerTurn() {
    gameState->playerTurn();
}

void Controller::printDeck() const {
    cout << *deck;
}

void Controller::ragequit() {
    cout << "Player" << gameState->getTurn()+1 << " ragequits. ";
    cout << "A computer will now take over." << endl;
    
    PlayerInfo info = players[gameState->getTurn()]->getInfo();
    vector<shared_ptr<Card>> hand = info.hand;
    vector<shared_ptr<Card>> discards = info.discards;
    vector<shared_ptr<Card>> legalPlays = info.legalPlays;
    shared_ptr<Player> computer = make_shared<ComputerPlayer>(table, info.number,
                                                            'c', hand, discards,
                                                            legalPlays, info.score);
    players[info.number-1] = computer;
    gameState->setPlayers(players);
    autoplayComputer();
    gameState->nextTurn();
}

void Controller::roundBegin() {
    deck->shuffleDeck();
    dealCards();
    for (auto player : players) {
        if (player->has7S()) {
            gameState->setCurrPlayer(player->getInfo().number-1);
            cout << "A new round begins. It's Player" << player->getInfo().number;
            cout << "\'s turn to play." << endl;
            break;
        }
    }
}

bool Controller::roundEnd() {
    return gameState->roundEnd();
}

void Controller::roundReset() {
    for (auto player : players) {
        player->clear();
    }
    table->clearTable();
}

void Controller::setGameStatePlayers() {
    gameState->setPlayers(players);
}

void Controller::shuffleDeck() {
    deck->shuffleDeck();
}

void Controller::tabulateScore() {
    for (auto player : players) {
        player->tabulateScore();
    }
    gameState->setLowestScore();
}