#include "Widget.hh"
#include <iostream>
#include "Input.hh"

Widget::~Widget() {
    for (Widget *content: this->contents) delete content;
}

int Widget::event(void *speaker, int type, unsigned int parameter) {
    for (Widget *content: this->contents) {
        int used = content->event(speaker, type, parameter);
        if (used) return true;
    }
    return false;
}

void Widget::addContent(Widget *content) {
    this->contents.push_back(content);
    this->fit();
}

int Widget::getWidth() {
    return this->width;
}

int Widget::getHeight() {
    return this->height;
}

void Widget::render(Graphics *graphics) {
    this->render(graphics, 0, 0);
}
