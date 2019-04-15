#ifndef GAME_H
#define GAME_H

#include "Layer.hh"
#include "Graphics.hh"
#include "Content.hh"
#include "Generator.hh"

/**
 * Represents a ui event.
 * Temporary event storage in queue.
 */
class Event {
public:
    Layer *notifier;
    int type;
    unsigned int parameter;
};

#define EVENT_QUEUE_SIZE 16

/**
 * Represents the status of the running game as a whole.
 */
class Game: public Layer {
    Graphics graphics;
    Generator generator;
    int kill = false;
    int queued = 0;
    Event eventQueue[EVENT_QUEUE_SIZE];

    /**
     * Processes user input from SDL.
     */
    void input();

    /**
     * Goes through the list of queued events and fires them all off.
     */
    void runEvents();

    virtual void queueEvent(Layer *notifier, int type, unsigned int parameter) override;

public:
    /**
     * Sets it up so that the game is listening for quit events.
     * @param argc is the number of commandline arguments TODO improve this.
     */
    Game(int argc);

    /**
     * When the game is over we must delete some stuff.
     */
    ~Game();

    /**
     * Runs the game until it is done.
     */
    void run();

    virtual int event(int type, unsigned int parameter) override;

    void render(Graphics *graphics) override;
};

#endif
