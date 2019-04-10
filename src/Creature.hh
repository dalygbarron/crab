#ifndef CREATURE_H
#define CREATURE_H

#include "Mob.hh"
#include "Move.hh"
#include "Map.hh"

/**
 * Prototypal creature that stores unchanging properties of a given kind of creature.
 */
class ProtoCreature {
    const int maxHealth;
    const int maxMana;

public:
    /**
     * Creates you a protocreature. TODO: might not work like this if these can vary.
     * @param maxHealth is the prototype's max health.
     * @param maxMana   is the prototype's max mana.
     */
    ProtoCreature(int maxHealth, int maxMana);

};

/**
 * A living breathing creature in the game which walks around in the level and shit.
 */
class Creature: public Mob {
    unsigned char prototype;
    unsigned short timer = 0;

public:
    /**
     * Makes the creature by giving it a prototype to instantiate.
     * @param prototype is the index of the creature's prototype.
     */
    Creature(unsigned char prototype);

    /**
     * Asks the creature what they would like to do this turn.
     * @param Map is the map that they are in as it is at the time of their move.
     */
    virtual Move getMove(Map const *map);
};

#endif
