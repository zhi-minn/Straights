#include "display.h"
#include "subject.h"
#include "table.h"
#include "card.h"
#include "info.h"
using namespace std;

const vector<string> suits = {"Clubs:", "Diamonds:", "Hearts:", "Spades:"};

void Display::setTable(shared_ptr<Table> _table) {
    table = _table;
}

void Display::notify( Subject & whoNotified ) {
    Info info = whoNotified.getInfo();
    playerHand = info.playerHand;
    legalPlays = info.legalPlays;
}

ostream &operator<<(ostream &out, const Display &display) {
    out << "Cards on the table:" << endl;
    for (int i = 0; i < 4; i++) {
        out << suits[i] << " ";
        for (auto card : display.table->getPile(i)) {
            out << *card << " ";
        }
        out << endl;
    }
    out << "Your hand: ";
    for (auto card : display.playerHand) {
        out << *card << " ";
    }
    out << endl;
    out << "Legal plays: ";
    for (auto card : display.legalPlays) {
        out << *card << " ";
    }
    out << endl;
    return out;
}