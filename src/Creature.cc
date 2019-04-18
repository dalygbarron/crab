#include "Creature.hh"

ProtoCreature::ProtoCreature() {
    // does nothing.
}

Creature::Creature(const ProtoCreature *prototype): prototype(prototype) {
    // does nothing.
}

Move Creature::getMove(const Map *map) {
    return Move(this, Move::ACTION_WALK, rand() % 8);
}
