#include "humanPlayer.h"
#include "card.h"
#include "table.h"
using namespace std;

HumanPlayer::HumanPlayer(shared_ptr<Table> table, int playerNum, char playerType)
    : Player(table, playerNum, playerType) {}

void HumanPlayer::play(shared_ptr<Card> card) {
    int cardIndex = findCard(card);
    char suit = card->getSuit();
    table->addCard(suit, card);
    hand.erase(hand.begin() + cardIndex);
}