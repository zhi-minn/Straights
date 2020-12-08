#include "display.h"
#include "subject.h"
#include "table.h"
#include "card.h"
#include "info.h"
using namespace std;

void Display::notify( Subject & whoNotified ) {
    Info info = whoNotified.getInfo();
    table = info.table;
    playerHand = info.playerHand;
    legalPlays = info.legalPlays;
}

ostream &operator<<(ostream &out, const Display &display) {
    out << *(display.table);    

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