#ifndef TITLE_H
#define TITLE_H

#include "../Scene.hh"
#include <iostream>
#include <cstdlib>
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
    /**
     * Waits for the user to click out of it and little else.
     * @param key is the keypress we have got.
     */
    Scene *logic(Graphics *graphics) {
        MainMenu menu = MainMenu(choices);
        menu.execute(graphics, 10, 10);
        return new Level();
    }

    /**
     * Displays the title and it's background and it's nice text. it is opaque.
     * @param graphics helps us acheive this goal.
     */
    void render(Graphics *graphics) {
        for (int i = 0; i < graphics->height; i++) {
            graphics->blitBox(0, i, graphics->width, 1, i / 2);
        }
        if (this->choice >= 0) graphics->blitString(choices[this->choice], 0, 0, Graphics::CYAN);
    }
};


#endif
