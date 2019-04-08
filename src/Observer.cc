#include "Observer.hh"


Listener::~Listener() {
    if (this->listening) Speaker::popListener();
}

void Speaker::speak(void *speaker, int type, int parameter) {
    for (Listener *listener: this->listeners) {
        if (listener->event(type, parameter)) return;
    }
}

void Speaker::pushListener(Listener *listener) {
    Speaker::listeners.push_front(listener);
    listener->setListening(true);
}


void Speaker::popListener() {
    Speaker::listeners.front()->setListening(false);
    Speaker::listeners.pop_front();
}
