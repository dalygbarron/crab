#ifndef TITLE_H
#define TITLE_H

#include "../Scene.hh"
#include <iostream>
#include <cstdlib>
#include "../Observer.hh"
#include "../widgets/Text.hh"
#include "../menus/MainMenu.hh"
#include "../scenes/Level.hh"

class Title: public Scene
{
    char const *choices[5] = {"New Game", "Load Game", "Guide", "Credits", "Quit"};
    int choice = -1;
    int x = 0;
    int y = 0;

public:

    Title(Input *input) {
        this->addGui(input, new MainMenu(choices));
    }

    int event(Speaker *speaker, int type, int parameter) {
        if (type == Listener::EVENT_WIDGET_CLOSE) {
            std::cout << parameter << std::endl;
            this->removeGui();
            return true;
        }
        return false;
    }

    /**
     * Displays the title and it's background and it's nice text. it is opaque.
     * @param graphics helps us acheive this goal.
     */
    void render(Graphics *graphics) {
        for (int i = 0; i < graphics->height; i++) graphics->blitBox(0, i, graphics->width, 1, i);
        if (this->choice >= 0) graphics->blitString(choices[this->choice], 0, 0, Graphics::CYAN);
    }
};


#endif
