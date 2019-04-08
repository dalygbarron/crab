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
    Generator generator;
    Scene *scene = NULL;
    int kill = false;

    /**
     * Sets the scene that will run, and links it up for this to listen to it's events. Does not delete the old scene
     * because you need to do that before you instantiate the new one so it doesn't add itself as a listener on top
     * before the old ones get delet.
     * @param scene is the scene to run.
     */
    void setScene(Scene *scene);

public:
    /**
     * Sets it up so that the game is listening for quit events.
     * @param argc is the number of commandline arguments TODO improve this.
     */
    Game(int argc);

    int event(void *speaker, int type, unsigned int parameter) override;

    /**
     * Runs the game until it is done.
     */
    void run();
};

#endif
