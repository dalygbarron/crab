#ifndef TITLE_H
#define TITLE_H

#include "../Layer.hh"
#include <iostream>
#include <cstdlib>
#include "../Layer.hh"
#include "../widgets/Text.hh"
#include "../menus/MainMenu.hh"
#include "../scenes/Level.hh"

/**
 * Title Screen scene which shows the main menu and nice stuff like that.
 */
class Title: public Layer
{
    char const *choices[5] = {"New Game", "Load Game", "Guide", "Credits", "Quit"};
    int choice = -1;
    int x = 0;
    int y = 0;

public:

    Title() {
        this->pushLayer(new MainMenu(choices));
    }

    int event(int type, unsigned int parameter) override {
        if (type == Layer::EVENT_WIDGET_CLOSE) {
            this->queueEvent(this, Layer::EVENT_MAP, 462378);
            return true;
        }
        return false;
    }

    void render(Graphics *graphics) override {
        for (int i = 0; i < graphics->height; i++) graphics->blitBox(0, i, graphics->width, 1, i);
        if (this->choice >= 0) graphics->blitString(choices[this->choice], 0, 0, Graphics::CYAN);
    }
};


#endif
