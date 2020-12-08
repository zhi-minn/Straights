#include "computerPlayer.h"
#include "card.h"
#include "table.h"
#include "defaultStrat.h"
#include <iostream>
using namespace std;

ComputerPlayer::ComputerPlayer(shared_ptr<Table> table, int playerNum, char playerType)
    : Player(table, playerNum, playerType) {
        setStrategy(make_unique<DefaultStrategy>());
    }

ComputerPlayer::ComputerPlayer(shared_ptr<Table> table, int playerNum, char playerType,
                      vector<shared_ptr<Card>> hand,
                      vector<shared_ptr<Card>> discards,
                      vector<shared_ptr<Card>> legalPlays,
                      int score)
    : Player(table, playerNum, playerType) {
        update(hand, discards, legalPlays, score);
        setStrategy(make_unique<DefaultStrategy>());
    }

void ComputerPlayer::play(shared_ptr<Card> card) {
    if (hasLegalPlays()) {
        shared_ptr<Card> card = strategy->playStrategy(true, table, legalPlays, hand);
        table->addCard(card->getSuit(), card);
        hand.erase(hand.begin() + findCard(card));

        cout << ">Player" << getInfo().number << " plays ";
        if (specialRank(card)) {
            cout << card->getDisplayRank();
        } else {
            cout << card->getRank();
        }
        cout << card->getSuit() << "." << endl;
    } else {
        shared_ptr<Card> card = strategy->playStrategy(false, table, legalPlays, hand);
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

void ComputerPlayer::setStrategy(unique_ptr<Strategy> _strategy) {
    strategy.reset();
    strategy = move(_strategy);
}

bool ComputerPlayer::specialRank(shared_ptr<Card> card) {
    if (card->getRank() == 1 || card->getRank() > 9) {
        return true;
    }
    return false;
}