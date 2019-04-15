#include "Creature.hh"

ProtoCreature::ProtoCreature() {
    // does nothing.
}

ProtoCreature::ProtoCreature(
    int maxHealth,
    int maxMana,
    unsigned char tile,
    Colour colour,
    unsigned char temperament
) {
}

Creature::Creature(const ProtoCreature *prototype): prototype(prototype) {
    // does nothing.
}

Move Creature::getMove(const Map *map) {
    return Move(this, Move::ACTION_WALK, rand() % 8);
}
