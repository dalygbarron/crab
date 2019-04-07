#include "Widget.hh"
#include <iostream>
#include "Input.hh"

Widget::~Widget() {
    for (Widget *child: this->children) delete child;
}

int Widget::event(int type, int parameter) {
    if (type != Input::EVENT_KEY) return false;
    for (Widget *child: this->children) {
        int response = child->event(type, parameter);
        if (response) return true;
    }
    return true;
}


void Widget::addChild(Widget *child) {
    this->children.push_back(child);
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
