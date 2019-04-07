#ifndef GAME_H
#define GAME_H

#include "Observer.hh"
#include "Scene.hh"
#include "Graphics.hh"
#include "Input.hh"

/**
 * Represents the status of the running game as a whole.
 */
class Game: public Listener {
    Graphics graphics;
    Input input;
    Scene *scene;
    int kill = false;

public:
    /**
     * Sets it up so that the game is listening for quit events.
     * @param argc is the number of commandline arguments TODO improve this.
     */
    Game(int argc);

    /**
     * Override
     */
    int event(Speaker *speaker, int type, int parameter);

    /**
     * Runs the game until it is done.
     */
    void run();
};

#endif
