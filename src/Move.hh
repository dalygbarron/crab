#ifndef MOVE_H
#define MOVE_H

/**
 * Forward declarations.
 */
class Creature;
class Mob;

/**
 * Represents a creature's action upon the map which modifies the state of the game.
 */
class Move {
public:
    static const unsigned char ACTION_WALK = 0x00;
    static const unsigned char ACTION_SKIP = 0xfe;
    static const unsigned char ACTION_INVALID = 0xff;

    static const int DIR_N = 0;
    static const int DIR_NE = 1;
    static const int DIR_E = 2;
    static const int DIR_SE = 3;
    static const int DIR_S = 4;
    static const int DIR_SW = 5;
    static const int DIR_W = 6;
    static const int DIR_NW = 7;
    static const int DIR_NONE = 8;

    Creature *actor;
    Mob *target;
    unsigned char action;
    int parameter;

    /**
     * Default constructor for your enjoyment.
     */
    Move();

    /**
     * Creates the move for cases where there is just an action and a parameter.
     * @param actor     is the creature doing the move.
     * @param action    is the action they are doing.
     * @param parameter is a parameter to the action for example a direction to a move.
     */
    Move(Creature *actor, unsigned char action, unsigned int parameter);

    /**
     * Creates the move for cases where there is a target.
     * @param actor    is the creature doing the move.
     * @param target   is the target of the move.
     * @param action   is the action performed.
     * @param paramter is a parameter to the action.
     */
    Move(Creature *actor, Mob *target, unsigned char action, unsigned int parameter);
};

#endif
