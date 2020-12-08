#include "defaultStrat.h"
#include "table.h"
#include "card.h"
using namespace std;

shared_ptr<Card> DefaultStrategy::playStrategy(bool hasLegalPlays, shared_ptr<Table> table,
                                    vector<shared_ptr<Card>> legalPlays,
                                    vector<shared_ptr<Card>> hand) {
    if (hasLegalPlays) {
        return legalPlays[0];
    } else {
        return hand[0];
    }
}