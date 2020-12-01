#include "gameState.h"
#include "player.h"
#include <iostream>
using namespace std;

void GameState::setPlayers(vector<shared_ptr<Player>> &_players) {
    players = _players;
}

bool GameState::roundEnd() {
    for (auto player : players) {
        if (player->getHand().size() != 0) {
            return false;
        }
    }
    return true;
}

bool GameState::gameEnd() {
    for (auto player : players) {
        if (player->getScore() >= 80) {
            return true;
        }
    }
    return false;
}

vector<int> GameState::getWinner() {
    vector<int> winnerNumbers;
    for (auto player : players) {
        if (player->getScore() == lowestScore) {
            winnerNumbers.emplace_back(player->getNum());
        }
    }
    return winnerNumbers;
}

void GameState::setCurrPlayer(int playerNum) {
    currPlayer = playerNum;
}

void GameState::setLowestScore() {
    lowestScore = players[0]->getScore();
    for (auto player : players) {
        if (player->getScore() < lowestScore) {
            lowestScore = player->getScore();
        }
    }
}

void GameState::playerTurn() {
    cout << currPlayer << endl;
    shared_ptr<Player> player = players[currPlayer];
    player->setLegalPlays();
    notifyObservers();
}

int GameState::getTurn() const {
    return currPlayer;
}

void GameState::nextTurn() {
    currPlayer++;
    if (currPlayer == 4) {
        currPlayer = 1;
    }
}

Info GameState::getInfo() {
    return Info{players[currPlayer]->getHand(), players[currPlayer]->getLegalPlays()};
}