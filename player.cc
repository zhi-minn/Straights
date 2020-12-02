#include "player.h"
#include "table.h"
#include "card.h"
#include <cstddef>
#include <stdexcept>
#include <iostream>
using namespace std;

int Player::convertRank(char rank) {
    switch(rank) {
        case 'A':
            return 1;
        case 'T':
            return 10;
        case 'J':
            return 11;
        case 'Q':
            return 12;
        case 'K':
            return 13;
        default:
            return (int) rank - 48;
    }
}

void Player::validateRank(int rank) {
    if (rank < 1 || rank > 13) {
        throw invalid_argument("Invalid rank\nThis is not a legal play.");
    }
}

shared_ptr<Card> Player::getCard(int rank, char suit) {
    for (auto card : hand) {
        if (card->getRank() == rank && card->getSuit() == suit) {
            return card;
        }
    }
    return nullptr;
}

Player::Player(shared_ptr<Table> table, int playerNum, char playerType)
    : table{table}, playerNumber{playerNum}, playerType{playerType} {}

int Player::findCard(shared_ptr<Card> card) {
    for (size_t i = 0; i < hand.size(); i++) {
        if (*hand[i] == *card) {
            return i;
        }
    }
}

bool Player::has7S() const {
    for (size_t i = 0; i < hand.size(); i++) {
        if (hand[i]->getRank() == 7 && hand[i]->getSuit() == 'S') {
            return true;
        }
    }
    return false;
}

void Player::play(shared_ptr<Card> card) {
    int cardIndex = findCard(card);
    char suit = card->getSuit();
    table->addCard(suit, card);
    hand.erase(hand.begin() + cardIndex);
}

void Player::validateCard(char rank, char suit) {
    int rankConvert = convertRank(rank);
    validateRank(rankConvert);

    shared_ptr<Card> card = getCard(rankConvert, suit);
    if (card != nullptr) {
        play(card);
        cout << "Player" << playerNumber << " plays " << rank << suit << "." << endl;
    } else {
        throw invalid_argument("This is not a legal play.");
    }
}

void Player::addCard(shared_ptr<Card> card) {
    hand.emplace_back(card);
}

void Player::discard(shared_ptr<Card> card) {
    int cardIndex = findCard(card);
    discards.emplace_back(card);
    hand.erase(hand.begin() + cardIndex);
}

void Player::validateDiscard(char rank, char suit) {
    int rankConvert = convertRank(rank);
    validateRank(rankConvert);

    shared_ptr<Card> card = getCard(rankConvert, suit);
    if (card == nullptr) {
        throw invalid_argument("This is not a legal play.");
    } else if (hasLegalPlays()) {
        throw invalid_argument("You have a legal play. You may not discard.");
    } else {
        discard(card);
        cout << "Player" << playerNumber << " discard " << rank << suit << "." << endl;
    }
}

void Player::setLegalPlays() {
    legalPlays.clear();
    if (table->empty()) {
        for (size_t i = 0; i < hand.size(); i++) {
            if (hand[i]->getRank() == 7 && hand[i]->getSuit() == 'S') {
                legalPlays.emplace_back(hand[i]);
                return;
            }
        }
    }

    for (auto card : hand) {
        if (table->checkLegalPlay(card)) {
            legalPlays.emplace_back(card);
        }   
    }
}

bool Player::hasLegalPlays() {
    if (legalPlays.empty()) {
        return false;
    }
    return true;
}

PlayerInfo Player::getInfo() const {
    return PlayerInfo{playerNumber, playerType, score, hand, discards, legalPlays};
}

void Player::tabulateScore() {
    for (auto discard : discards) {
        score += discard->getRank();
    }
}

void Player::update(vector<shared_ptr<Card>> _hand, vector<shared_ptr<Card>> _discards,
                    vector<shared_ptr<Card>> _legalPlays, int _score) {
                        hand = _hand;
                        discards = _discards;
                        legalPlays = _legalPlays;
                        score = _score;
                    }

void Player::clear() {
    hand.clear();
    discards.clear();
    legalPlays.clear();
}