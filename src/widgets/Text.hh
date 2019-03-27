#ifndef TEXT_H
#define TEXT_H

#include "../Widget.hh"
#include "../Graphics.hh"

class Text: public Widget {
    char const *content;
    int colour;

public:
    /**
     * creates the text with actual text it shows.
     * @param content is the text it will display.
     */
    Text(char const *content, int colour = Graphics::CYAN) {
        this->content = content;
        this->colour = colour;
        this->width = strlen(content);
        this->height = 1;
    }

    void fit() {
        // does nothing.
    }

    /**
     * @Override
     */
    void render(Graphics *graphics, int x, int y) {
        graphics->blitString(this->content, x, y, this->colour);
    }
};

#endif
