#include "Observer.hh"


Listener::~Listener() {
    for (Speaker *speaker: this->speakers) speaker->popListener();
}

void Speaker::speak(int type, int parameter) {
    for (Listener *listener: this->listeners) {
        if (listener->event(type, parameter)) return;
    }
}

void Speaker::pushListener(Listener *listener) {
    this->listeners.push_front(listener);
}

void Speaker::popListener() {
    this->listeners.pop_front();
}
