#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "../Widget.hh"
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
public:
    MainMenu() {
        char *choices[] = {"New Game", "Load Game", "Guide", "Piss", "Quit"};
        for (int i = 0; i < 5; i++) { // TODO: magic number.
            selector.addChild(new Text(choices[i]));
        }
        frame.addChild(selector);
    }

    int logic(Graphics *graphics) {


    }

    void render(Graphics *graphics, int x, int y, int w, int h) {
        frame.render(graphics, x, y, w, h);
    }
};


#endif
