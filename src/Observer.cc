#include "Observer.hh"


Listener::~Listener() {
    for (Speaker *speaker: this->speakers) speaker->popListener();
}

void Listener::addSpeaker(Speaker *speaker) {
    this->speakers.push_front(speaker);
}

void Listener::removeSpeaker(Speaker *speaker) {
    this->speakers.remove(speaker);
}

Speaker::~Speaker() {
    // does nothing.
}

void Speaker::speak(int type, int parameter) {
    for (Listener *listener: this->listeners) {
        if (listener->event(this, type, parameter)) return;
    }
}

void Speaker::pushListener(Listener *listener) {
    this->listeners.push_front(listener);
    listener->addSpeaker(this);
}

void Speaker::popListener() {
    this->listeners.front()->removeSpeaker(this);
    this->listeners.pop_front();
}
