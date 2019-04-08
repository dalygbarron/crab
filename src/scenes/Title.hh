#ifndef TITLE_H
#define TITLE_H

#include "../Scene.hh"
#include <iostream>
#include <cstdlib>
#include "../Observer.hh"
#include "../widgets/Text.hh"
#include "../menus/MainMenu.hh"
#include "../scenes/Level.hh"

/**
 * Title Screen scene which shows the main menu and nice stuff like that.
 */
class Title: public Scene
{
    char const *choices[5] = {"New Game", "Load Game", "Guide", "Credits", "Quit"};
    int choice = -1;
    int x = 0;
    int y = 0;

public:

    Title(Input *input) {
        this->pushLayer(new MainMenu(choices));
    }

    int event(void *speaker, int type, unsigned int parameter) {
        if (type == Speaker::EVENT_WIDGET_CLOSE) {
            std::cout << 9 <<std::endl;
            Speaker::speak(this, Speaker::EVENT_MAP, 2487);
            return true;
        }
        return false;
    }

    void render(Graphics *graphics) {
        for (int i = 0; i < graphics->height; i++) graphics->blitBox(0, i, graphics->width, 1, i);
        if (this->choice >= 0) graphics->blitString(choices[this->choice], 0, 0, Graphics::CYAN);
    }
};


#endif
