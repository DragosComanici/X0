#include "Player.hpp"

// Constructor cu parametru
Player::Player(char marker) : marker(marker), playerNumber(marker == 'X' ? 1 : 2) {}

char Player::getMarker() const {
    return marker;
}

void Player::setMarker(char marker) {
    this->marker = marker;
}

int Player::getPlayerNumber() const {
    return playerNumber;
}