#include "display.h"
#include "subject.h"
#include "table.h"
#include "card.h"
#include "info.h"
#include "player.h"
using namespace std;

void Display::notify( Subject & whoNotified ) {
    Info info = whoNotified.getInfo();
    table = info.table;
    players = info.players;
    currPlayer = info.currPlayer;
}

ostream &operator<<(ostream &out, const Display &display) {
    shared_ptr<Player> player = display.players[display.currPlayer];
    vector<shared_ptr<Card>> hand = player->getInfo().hand;
    vector<shared_ptr<Card>> legalPlays = player->getInfo().legalPlays;

    out << *(display.table);    

    out << "Your hand: ";
    for (auto card : hand) {
        out << *card << " ";
    }
    out << endl;
    out << "Legal plays: ";
    for (auto card : legalPlays) {
        out << *card << " ";
    }
    out << endl;
    return out;
}