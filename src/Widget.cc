#include "Widget.hh"
#include <iostream>
#include "Input.hh"

Widget::~Widget() {
    if (this->gui) delete this->gui;
    for (Widget *child: this->children) delete child;
}

int Widget::event(Speaker *speaker, int type, int parameter) {
    if (type == Listener::EVENT_KEY) {
        for (Widget *child: this->children) {
            int used = child->event(speaker, type, parameter);
            if (used) return true;
        }
    }
    return false;
}

void Widget::addGui(Input *input, Widget *gui) {
    if (this->gui) delete this->gui;
    this->gui = gui;
    input->pushListener(gui);
    gui->pushListener(this);
}

void Widget::removeGui() {
    if (this->gui) {
        delete this->gui;
        this->gui = NULL;
    }
}

void Widget::setParent(Widget *parent) {
    this->parent = parent;
}

void Widget::addChild(Widget *child) {
    this->children.push_back(child);
    child->setParent(this);
    this->fit();
}

int Widget::getNChildren() {
    return this->children.size();
}

int Widget::getWidth() {
    return this->width;
}

int Widget::getHeight() {
    return this->height;
}

void Widget::parentSpeak(int type, int parameter) {
    if (this->parent) parent->parentSpeak(type, parameter);
    else this->speak(type, parameter);
}
