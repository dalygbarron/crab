#ifndef OBSERVER_H
#define OBSERVER_H

#include <forward_list>

/**
 * Abstract class for something that can subscribe to a speaker which will call functionality on the listener when a
 * given event occurs.
 * NB: ONLY for UI purposes.
 */
class Listener {
    int listening = false;

public:
    /**
     * Virtual destructor so it can be extended.
     */
    virtual ~Listener();

    /**
     * Called when the event we are listening for has occured.
     * @param speaker is a pointer to the object that sent the event.
     * @param type      is the type of event that this is.
     * @param parameter is a piece of additional information about the event for example if type represents a keypress,
     *                  then parameter may represent the key code.
     * @return true if we are willing to process this event, or false if we are ignoring it and it should be sent to the
     *         next listener on the speaker's queue, as the top listener on the queue always gets to look first.
     */
    virtual int event(void *speaker, int type, unsigned int parameter) = 0;

    /**
     * Sets whether the listener is listening or not so it knows whether to remove itself from the listener stack upon
     * it's death or not.
     * @param listening is whether or not it is listening.
     */
    void setListening(int listening);
};

namespace Speaker {
    const int EVENT_QUIT = 0;
    const int EVENT_KEY = 1;
    const int EVENT_WIDGET_CLOSE = 2;
    const int EVENT_WIDGET_UPDATE = 3;
    const int EVENT_MAP = 4;

    /**
     * Adds a listener to the list of listeners.
     * @param listener is the listener to add.
     */
    void pushListener(Listener *listener);

    /**
     * Removes a listener from the list.
     */
    void popListener();

    /**
     * Sends a message out to the listeners.
     * @param speaker   is the sender of this message, this makes sure that the speaker does not listen to itself and
     *                  can be used by the listener.
     * @param type      is the event type which is told to the listener.
     * @param parameter is a parameter that goes with the event like if it's a keypress, this will be the key code.
     */
    void speak(void *speaker, int type, unsigned int parameter);
}

#endif
