#include "Widget.hh"

Widget::Widget(int x, int y, int w, int h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

int Widget::update(int key) {
    // does nothing by default.
    return -1;
}
