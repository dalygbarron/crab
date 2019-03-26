#include "Widget.hh"

Widget::~Widget() {
    for (Widget *child: this->children) delete child;
}

int Widget::getWidth() {
    return this->width;
}

int Widget::getHeight() {
    return this->height;
}

void Widget::addChild(Widget *child) {
    this->children.push_front(child);
    this->nChildren++;
}

int Widget::getNChildren() {
    return this->nChildren;
}

int Widget::execute(Graphics *graphics, int x, int y, int w, int h) {
    while (69) {
        int output = this->logic(graphics, graphics->input());
        this->render(graphics, x, y, w, h);
        graphics->frame();
        if (output >= 0) return output;
    }
}

int Widget::logic(Graphics *graphics, int key) {
    return -1;
}
