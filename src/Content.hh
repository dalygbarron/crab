#ifndef CONTENT_H
#define CONTENT_H

#include "Creature.hh"
#include "Item.hh"
#include "Floor.hh"
#include "Wall.hh"

/**
 * Contains creative type data about the game.
 */
namespace Content {
    const unsigned char CREATURE_NONE = 0;
    const unsigned char CREATURE_RAT = 1;
    const unsigned char CREATURE_N = 2;
    const ProtoCreature protoCreatures[] = {
        ProtoCreature(),
        ProtoCreature(10, 10, 0x36, Colour::BLUE, ProtoCreature::TEMPERAMENT_THING)
    };

    const ProtoItem protoItems[] = {};

    const unsigned char FLOOR_GRASS = 0;
    const unsigned char FLOOR_N = 1;
    const Floor floors[] = {
        Floor(0xb0, Colour(19, 112, 50), "a nice grass")
    };

    const unsigned char WALL_NONE = 0;
    const unsigned char WALL_TREE = 1;
    const unsigned char WALL_N = 2;
    const Wall walls[] = {
        Wall(),
        Wall(0x05, Colour(51, 35, 0), "a nice tree")
    };

    /**
     * Create an instance of a creature based on a prototype which is given by it's index in the array of creatures.
     * @param index is the proto creature you have chosen to proceed with.
     * @return the new creature. It is now yours and you must delete it in due time.
     */
    Creature *getCreature(unsigned char index);
};

#endif
