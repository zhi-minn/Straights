#include "controller.h"
#include "table.h"
#include "humanPlayer.h"
#include "computerPlayer.h"
#include "deck.h"
#include "gameState.h"
#include "display.h"
#include "card.h"
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
        players.emplace_back(make_shared<HumanPlayer>(table, playerNum));
    } else {
        players.emplace_back(make_shared<ComputerPlayer>(table, playerNum));
    }
}

void Controller::createDeck() {
    deck->makeCards();
}

void Controller::shuffleDeck() {
    deck->shuffleDeck();
}

void Controller::dealCards() {
    shared_ptr<Player> player1 = findPlayer(1);
    shared_ptr<Player> player2 = findPlayer(2);
    shared_ptr<Player> player3 = findPlayer(3);
    shared_ptr<Player> player4 = findPlayer(4);
    
    for (int i = 0; i < deck->getSize(); i++) {
        if (i <= 12) {
            player1->addCard(deck->getCard(i));
        } else if (i <= 25) {
            player2->addCard(deck->getCard(i));
        } else if (i <= 38) {
            player3->addCard(deck->getCard(i));
        } else {
            player4->addCard(deck->getCard(i));
        }
    }
}

void Controller::roundBegin() {
    deck->shuffleDeck();
    dealCards();
    for (auto player : players) {
        if (player->has7S()) {
            gameState->setCurrPlayer(player->getNum()-1);
            cout << "A new round begins. It's Player" << player->getNum();
            cout << "\'s turn to play." << endl;
            break;
        }
    }
}

void Controller::roundReset() {
    for (auto player : players) {
        player->clear();
    }
}

void Controller::setGameStatePlayers() {
    gameState->setPlayers(players);
}

void Controller::attachDisplay(shared_ptr<Display> &display) {
    gameState->attach(display.get());
}

shared_ptr<Table> Controller::getTable() const {
    return table;
}

void Controller::printDeck() const {
    cout << *deck;
}

void Controller::playerTurn() {
    gameState->playerTurn();
}

void Controller::playCard(char rank, char suit) {
    int turn = gameState->getTurn();
    players[turn]->validateCard(rank, suit);    
    gameState->nextTurn();
}

void Controller::discard(char rank, char suit) {
    int turn = gameState->getTurn();
    players[turn]->validateDiscard(rank, suit);
    gameState->nextTurn();
}