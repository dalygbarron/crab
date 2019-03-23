#include "Widget.hh"
#include "Graphics.hh"

Widget::Widget(int w, int h) {
    this->w = w;
    this->h = h;
}

int Widget::update(int key) {
    return -1;
}
