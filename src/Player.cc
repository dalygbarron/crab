#include "Player.hh"

Player::Player(): Creature(0) {
    // does nothing here.
}

Move Player::getMove(Map const *map) {
    return Move(this, Move::ACTION_SKIP, 0);
}
