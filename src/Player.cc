#include "Player.hh"

#include <iostream>

Player::Player(): Creature(0) {
    // Does nothing.
}

void Player::setMove(Move move) {
    this->nextMove = move;
    this->moveStale = false;
}

Move Player::getMove(Map const *map) {
    if (this->moveStale) std::cerr << "player has no moves" << std::endl;
    this->moveStale = true;
    return this->nextMove;
}
