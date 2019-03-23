#ifndef TEXT_H
#define TEXT_H

#include <string>
#include "../Graphics.hh"

class Text: public Widget {
    char *content;

public:
    /**
     * creates the text with it's bounding area the text it displays.
     * @param w is the width of it's bounding area.
     * @param h is the height of it's bounding area.
     * @param content is the text it will display.
     */
    Text(int w, int h, char *content): Widget(w, h) {
        this->content = content;
    }

    /**
     * displays the text.
     * @param graphics manages the picutrue.
     * @param x is the horizontal location of the text.
     * @param y is the vertical location to put the top of the text.
     */
    void render(Graphics *graphics, int x, int y) {
        graphics->blitString(this->content, x, y, Graphics::CYAN);
    }
};

#endif
