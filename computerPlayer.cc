#include "computerPlayer.h"
using namespace std;

ComputerPlayer::ComputerPlayer(shared_ptr<Table> table, int playerNum)
    : Player(table, playerNum) {}

void ComputerPlayer::autoPlay() {
    if (hasLegalPlays()) {
        play(getLegalPlays()[0]);
    } else {
        discard(getHand()[0]);
    }
}