#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.hh"

class Player: public Creature {
    Move nextMove;
    int moveStale = true;

public:
    /**
     * Default constructor.
     */
    Player();

    /**
     * Since the player is just player controlled, you must tell them what move you want them to do before you ask them.
     * @param move is the move you want them to perform.
     */
    void setMove(Move move);

    virtual Move getMove(Map const *map) override;
};

#endif
