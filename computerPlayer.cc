#include "computerPlayer.h"
#include "card.h"
#include <iostream>
using namespace std;

ComputerPlayer::ComputerPlayer(shared_ptr<Table> table, int playerNum, char playerType)
    : Player(table, playerNum, playerType) {}

ComputerPlayer::ComputerPlayer(shared_ptr<Table> table, int playerNum, char playerType,
                      vector<shared_ptr<Card>> hand,
                      vector<shared_ptr<Card>> discards,
                      vector<shared_ptr<Card>> legalPlays,
                      int score)
    : Player(table, playerNum, playerType) {
        update(hand, discards, legalPlays, score);
    }

void ComputerPlayer::autoplay() {
    if (hasLegalPlays()) {
        shared_ptr<Card> card = getInfo().legalPlays[0];
        play(card);

        cout << ">Player" << getInfo().number << " plays ";
        if (specialRank(card)) {
            cout << card->getDisplayRank();
        } else {
            cout << card->getRank();
        }
        cout << card->getSuit() << "." << endl;
    } else {
        shared_ptr<Card> card = getInfo().hand[0];
        discard(card);

        cout << ">Player" << getInfo().number << " discards ";
        if (specialRank(card)) {
            cout << card->getDisplayRank();
        } else {
            cout << card->getRank();
        }
        cout << card->getSuit() << "." << endl;
    }
}

bool ComputerPlayer::specialRank(shared_ptr<Card> card) {
    if (card->getRank() == 1 || card->getRank() > 9) {
        return true;
    }
    return false;
}