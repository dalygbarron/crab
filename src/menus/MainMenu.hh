#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "../Widget.hh"
#include <iostream>
#include "../Graphics.hh"
#include "../widgets/Frame.hh"
#include "../widgets/ListSelector.hh"
#include "../widgets/Text.hh"

/**
 * This is the menu where you choose whether to play or whatever.
 */
class MainMenu: public Widget {
    Frame frame = Frame(Graphics::NAVY);
    ListSelector selector = ListSelector();
    char *choices[5] = {"New Game", "Load Game", "Guide", "Piss", "Quit"};

public:
    MainMenu() {
        for (int i = 0; i < 5; i++) { // TODO: magic number.
            selector.addChild(new Text(this->choices[i]));
        }
        frame.addChild(&selector);
    }

    int logic(Graphics *graphics) {
        graphics->input();
        return -1;
    }

    void render(Graphics *graphics, int x, int y, int w, int h) {
        frame.render(graphics, x, y, w, h);
    }
};


#endif
