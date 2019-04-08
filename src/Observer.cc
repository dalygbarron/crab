#include "Observer.hh"
#include <iostream>
#include <forward_list>


Listener::~Listener() {
    if (this->listening) {
        Speaker::popListener();
        std::cout << "out" << std::endl;
    }
}

void Listener::setListening(int listening) {
    this->listening = listening;
}

std::forward_list<Listener *> listeners;

void Speaker::pushListener(Listener *listener) {
    listeners.push_front(listener);
    listener->setListening(true);
}

void Speaker::popListener() {
    listeners.front()->setListening(false);
    listeners.pop_front();
}

void Speaker::speak(void *speaker, int type, unsigned int parameter) {
    for (Listener *listener: listeners) {
        if (listener == speaker) continue;
        if (listener->event(speaker, type, parameter)) return;
    }
}
