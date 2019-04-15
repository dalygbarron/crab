#include "Creature.hh"

ProtoCreature::ProtoCreature(): maxHealth(0), maxMana(0), tile(0), colour(), temperament(0) {
    // does nothing.
}

ProtoCreature::ProtoCreature(
    int maxHealth,
    int maxMana,
    unsigned char tile,
    Colour colour,
    unsigned char temperament
): maxHealth(maxHealth), maxMana(maxMana), tile(tile), colour(colour), temperament(temperament) {
    // Does nothing.
}

Creature::Creature(const ProtoCreature *prototype): prototype(prototype) {
    // does nothing.
}

Move Creature::getMove(const Map *map) {
    return Move(this, Move::ACTION_WALK, rand() % 8);
}
