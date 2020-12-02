#include "scoreView.h"
#include "player.h"
#include "card.h"
#include <iostream>
using namespace std;

void ScoreView::setPlayers(vector<shared_ptr<Player>> _players) {
    players = _players;
}

ostream &operator<<(ostream &out, const ScoreView &scoreView) {
    for (auto player : scoreView.players) {
        PlayerInfo info = player->getInfo();
        int roundScore = 0;

        out << "Player" << info.number << "\'s discards: ";
        for (auto discard : info.discards) {
            out << *discard << " ";
            roundScore += discard->getRank();
        }
        out << endl;

        out << "Player" << info.number << "\'s score: ";
        out << info.score << " + " << roundScore << " = " << info.score + roundScore << endl;
    }
    return out;
}