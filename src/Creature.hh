#ifndef CREATURE_H
#define CREATURE_H

#include "Mob.hh"
#include "Move.hh"
#include "Map.hh"
#include "Graphics.hh"

/**
 * Prototypal creature that stores unchanging properties of a given kind of creature.
 */
class ProtoCreature {
    char *name;
    char *description;
    int constitution;
    int intelligence;
    int strength;
    int mobility;
    unsigned char tile;
    Colour colour;
    unsigned char temperament;

public:
    static const unsigned char TEMPERAMENT_THING = 0;
    static const unsigned char TEMPERAMENT_GRUNT = 1;
    static const unsigned char TEMPERAMENT_N = 2;

    static const unsigned char BONUS_NONE = 0;
    static const unsigned char BONUS_SWOLE = 1;
    static const unsigned char BONUS_RED = 2;

    /**
     * Blank constructor for nothing creature.
     */
    ProtoCreature();

    /**
     * Creates you a protocreature. TODO: might not work like this if these can vary.
     * @param maxHealth   is the prototype's max health.
     * @param maxMana     is the prototype's max mana.
     * @param tile        is the prototype's display tile.
     * @param colour      is the colour of the prototypal creature.
     * @param temperament is the temperament that creatres of this type will have.
     */
    ProtoCreature(int maxHealth, int maxMana, unsigned char tile, Colour colour, unsigned char temperament);
};

/**
 * A living breathing creature in the game which walks around in the level and shit.
 */
class Creature: public Mob {
    const ProtoCreature *prototype;
    unsigned short timer = 0;

public:
    /**
     * Makes the creature by giving it a prototype to instantiate.
     * @param prototype is the prototypal creature this one is based on.
     */
    Creature(const ProtoCreature *prototype);

    /**
     * Asks the creature what they would like to do this turn.
     * @param Map is the map that they are in as it is at the time of their move.
     */
    virtual Move getMove(Map const *map);
};

#endif
