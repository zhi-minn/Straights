#include "playerView.h"
#include "player.h"
#include "subject.h"
#include "info.h"
using namespace std;

void PlayerView::setPlayers(vector<shared_ptr<Player>> _players) {
    players = _players;
}

void PlayerView::notify( Subject &whoNotified ) {

}