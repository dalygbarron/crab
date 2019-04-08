#ifndef TEXT_H
#define TEXT_H

#include "../Widget.hh"
#include "../Graphics.hh"

class Text: public Widget {
    char const *message;
    int colour;

public:
    /**
     * creates the text with actual text it shows.
     * @param message is the text it will display.
     * @param colour  is the colour it will be displayed in.
     */
    Text(char const *message, int colour = Graphics::CYAN) {
        this->message = message;
        this->colour = colour;
        this->width = strlen(message);
        this->height = 1;
    }

    void fit() override {
        // does nothing.
    }

    /**
     * @Override
     */
    void render(Graphics *graphics, int x, int y) override {
        graphics->blitString(this->message, x, y, this->colour);
    }
};

#endif
