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
    Prototype *prototypes;
    Floor *floors;
    Wall *walls;
};

#endif
