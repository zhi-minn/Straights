#include "gameState.h"
#include "player.h"
#include <iostream>
using namespace std;

void GameState::setPlayers(vector<shared_ptr<Player>> &_players) {
    players = _players;
}

bool GameState::roundEnd() {
    for (auto player : players) {
        if (player->getInfo().hand.size() != 0) {
            return false;
        }
    }
    return true;
}

bool GameState::gameEnd() {
    for (auto player : players) {
        if (player->getInfo().score >= 80) {
            return true;
        }
    }
    return false;
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

void GameState::setCurrPlayer(int playerNum) {
    currPlayer = playerNum;
}

void GameState::setLowestScore() {
    lowestScore = players[0]->getInfo().score;
    for (auto player : players) {
        if (player->getInfo().score < lowestScore) {
            lowestScore = player->getInfo().score;
        }
    }
}

void GameState::playerTurn() {
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
        currPlayer = 0;
    }
}

Info GameState::getInfo() {
    return Info{players[currPlayer]->getInfo().hand, players[currPlayer]->getInfo().legalPlays};
}