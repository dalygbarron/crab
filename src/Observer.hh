#ifndef OBSERVER_H
#define OBSERVER_H

#include <forward_list>

/**
 * Forward definition.
 */
class Speaker;

/**
 * Abstract class for something that can subscribe to a speaker which will call functionality on the listener when a
 * given event occurs.
 */
class Listener {
    std::forward_list<Speaker *> speakers;

public:
    /**
     * Virtual destructor so it can be extended.
     */
    virtual ~Listener();

    /**
     * Called when the event we are listening for has occured.
     * @param type      is the type of event that this is.
     * @param parameter is a piece of additional information about the event for example if type represents a keypress,
     *                  then parameter may represent the key code.
     * @return true if we are willing to process this event, or false if we are ignoring it and it should be sent to the
     *         next listener on the speaker's queue, as the top listener on the queue always gets to look first.
     */
    virtual int event(int type, int parameter) = 0;
};

/**
 * Abstract class for something that reports events to listeners.
 */
class Speaker {
    std::forward_list<Listener *> listeners;

public:
    /**
     * Sends out an event.
     * @param type      is the type of the event.
     * @param parameter is a piece of additional info.
     */
    void speak(int type, int parameter);

    /**
     * Adds a new listener to the top of the priority stack.
     * @param listener is a pointer to the new listener. When an event goes through, the listener most recently added
     *                 will get the first chance to check it out.
     */
    void pushListener(Listener *listener);

    /**
     * Removes the most recently added listener from the stack.
     */
    void popListener();
};

#endif
