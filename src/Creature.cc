#include "Creature.hh"

ProtoCreature::ProtoCreature(int maxHealth, int maxMana): maxHealth(maxHealth), maxMana(maxMana) {
    // Does nothing.
}

Creature::Creature(unsigned char prototype) {
    this->prototype = prototype;
}

Move Creature::getMove(const Map *map) {
    return Move();
}
