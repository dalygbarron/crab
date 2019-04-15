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
    const Floor floors[] = {};
    const Wall walls[] = {};

    /**
     * Loads all the game content out of the files and keeps it here.
     */
    void load();

    /**
     * Deletes all the game content again.
     */
    void free();

    /**
     * Create an instance of a creature based on a prototype which is given by it's index in the array of creatures.
     * @param index is the proto creature you have chosen to proceed with.
     * @return the new creature. It is now yours and you must delete it in due time.
     */
    Creature *getCreature(unsigned char index);
};

#endif
