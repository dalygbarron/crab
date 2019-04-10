#ifndef TEXT_H
#define TEXT_H

#include "../Widget.hh"
#include "../Graphics.hh"

class Text: public Widget {
    char const *content;
    Colour colour;

public:
    /**
     * creates the text with actual text it shows.
     * @param content is the text it will display.
     */
    Text(char const *content, Colour colour = Colour::CYAN) {
        this->content = content;
        this->colour = colour;
        this->dimensions.x = strlen(content);
        this->dimensions.y = 1;
        // TODO: dimensions calculation is not right.
    }

    void fit() override {
        // does nothing.
    }

    void render(Graphics *graphics, Position pos) override {
        graphics->blitString(this->content, pos, this->colour);
    }
};

#endif
