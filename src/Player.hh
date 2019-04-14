#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.hh"

/**
 * Represents the player character. They are special because they only give out skip moves, as their moves are handled
 * by the level layer.
 */
class Player: public Creature {
public:
    /**
     * Default constructor to set prototype automatiically.
     */
    Player();

    virtual Move getMove(Map const *map) override;
};

#endif
