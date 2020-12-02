#include "humanPlayer.h"
using namespace std;

HumanPlayer::HumanPlayer(shared_ptr<Table> table, int playerNum, char playerType)
    : Player(table, playerNum, playerType) {}