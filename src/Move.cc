#include "Move.hh"

Move::Move(): actor(0), target(0), action(Move::ACTION_INVALID), parameter(0) {
    // does nothing.
}

Move::Move(
    Creature *actor,
    unsigned char action,
    unsigned int parameter
): actor(actor), target(0), action(action), parameter(parameter) {
    // does nothing rn.
};


Move::Move(
    Creature *actor,
    Mob *target,
    unsigned char action,
    unsigned int parameter
): actor(actor), target(target), action(action), parameter(parameter) {
    // also does nothing rn.
};
