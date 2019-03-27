#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "../Widget.hh"
#include <iostream>
#include "../Graphics.hh"
#include "../widgets/HBox.hh"
#include "../widgets/ListSelector.hh"
#include "../widgets/Text.hh"

/**
 * This is the menu where you choose whether to play or whatever.
 */
class MainMenu: public Widget {


public:
    MainMenu(char const **choices) {
        HBox *box = new HBox();
        ListSelector *selector = new ListSelector();
        ListSelector *other = new ListSelector();

        for (int i = 0; i < 5; i++) { // TODO: magic number.
            selector->addChild(new Text(choices[i]));
            other->addChild(new Text(choices[i]));
        }
        box->addChild(selector);
        box->addChild(other);
        this->addChild(box);
    }

    void render(Graphics *graphics, int x, int y) {
        for (Widget *child: this->children) child->render(graphics, x, y);
    }
};


#endif
