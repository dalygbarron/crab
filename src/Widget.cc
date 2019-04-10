#include "Widget.hh"
#include <iostream>

Widget::~Widget() {
    for (Widget *content: this->contents) delete content;
}

void Widget::addContent(Widget *content) {
    this->contents.push_back(content);
    content->container = this;
    this->fit();
}

int Widget::getWidth() {
    return this->width;
}

int Widget::getHeight() {
    return this->height;
}

void Widget::containerEvent(int type, unsigned int parameter) {
    if (this->container) this->container->containerEvent(type, parameter);
    else this->queueEvent(this, type, parameter);
}

void Widget::render(Graphics *graphics) {
    this->render(graphics, 0, 0);
}

int Widget::event(int type, unsigned int parameter) {
    for (Widget *content: this->contents) {
        if(content->event(type, parameter)) return true;
    }
    return false;
}
