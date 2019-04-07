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
    static const int EVENT_QUIT = 0;
    static const int EVENT_KEY = 1;
    static const int EVENT_WIDGET_CLOSE = 2;
    static const int EVENT_WIDGET_UPDATE = 3;
    static const int EVENT_MAP = 4;

    /**
     * Virtual destructor so it can be extended.
     */
    virtual ~Listener();

    /**
     * Adds a speaker to the list of speakers this must be removed from when it is deleted.
     * @param speaker is the speaker to add to the lst.
     */
    void addSpeaker(Speaker *speaker);

    /**
     * removes a certain speaker from the observer.
     * @param speaker is the speaker to be removed.
     */
    void removeSpeaker(Speaker *speaker);

    /**
     * Called when the event we are listening for has occured.
     * @param speaker   is the one sending the event so you can do stuff.
     * @param type      is the type of event that this is.
     * @param parameter is a piece of additional information about the event for example if type represents a keypress,
     *                  then parameter may represent the key code.
     * @return true if we are willing to process this event, or false if we are ignoring it and it should be sent to the
     *         next listener on the speaker's queue, as the top listener on the queue always gets to look first.
     */
    virtual int event(Speaker *speaker, int type, int parameter) = 0;
};

/**
 * Abstract class for something that reports events to listeners.
 */
class Speaker {
    std::forward_list<Listener *> listeners;

public:
    /**
     * needed for polymorphism.
     */
    virtual ~Speaker();

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
