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
    const ProtoCreature protoCreatures[] = {};

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
};

#endif
