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

    const Floor floors[] = {
        Floor(),
        Floor(0xb0, 0x00ff00, 0x0fa011, "a nice grass")
    };

    const unsigned char WALL_NONE = 0;
    const unsigned char WALL_TREE = 1;
    const Wall walls[] = {
        Wall(),
        Wall(0x01, 0x332300, "a nice tree")
    };
};

#endif
