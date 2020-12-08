#include "gameState.h"
#include "player.h"
#include <iostream>
using namespace std;

bool GameState::gameEnd() {
    for (auto player : players) {
        if (player->getInfo().score >= 80) {
            return true;
        }
    }
    return false;
}

Info GameState::getInfo() {
    return Info{players[currPlayer]->getInfo().table, players, currPlayer};
}

int GameState::getTurn() const {
    return currPlayer;
}

vector<int> GameState::getWinner() {
    vector<int> winnerNumbers;
    for (auto player : players) {
        if (player->getInfo().score == lowestScore) {
            winnerNumbers.emplace_back(player->getInfo().number);
        }
    }
    return winnerNumbers;
}

void GameState::nextTurn() {
    currPlayer++;
    if (currPlayer == 4) {
        currPlayer = 0;
    }
}

void GameState::playerTurn() {
    shared_ptr<Player> player = players[currPlayer];
    player->setLegalPlays();
    notifyObservers();
}

bool GameState::roundEnd() {
    for (auto player : players) {
        if (player->getInfo().hand.size() != 0) {
            return false;
        }
    }
    return true;
}

void GameState::setCurrPlayer(int playerNum) {
    currPlayer = playerNum;
}

void GameState::setPlayers(vector<shared_ptr<Player>> &_players) {
    players = _players;
    notifyObservers();
}

void GameState::setLowestScore() {
    lowestScore = players[0]->getInfo().score;
    for (auto player : players) {
        if (player->getInfo().score < lowestScore) {
            lowestScore = player->getInfo().score;
        }
    }
}