#ifndef MOB_H
#define MOB_H

#include "Vector.hh"

/**
 * Represents something that can move around a level.
 */
class Mob {
    Position position;

public:
    /**
     * gives you the mob's position.
     * @return the position.
     */
    Position getPosition();

    /**
     * Sets the mob's position.
     * @param position is the new position to use.
     */
    void setPosition(Position position);

};

#endif
