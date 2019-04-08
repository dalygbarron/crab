#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "../widgets/Tall.hh"
#include <iostream>
#include "../Graphics.hh"
#include "../widgets/HBox.hh"
#include "../widgets/ListSelector.hh"
#include "../widgets/Text.hh"

/**
 * This is the menu where you choose whether to play or whatever.
 */
class MainMenu: public Tall {


public:
    MainMenu(char const **choices) {
        HBox *box = new HBox();
        ListSelector *selector = new ListSelector();
        ListSelector *other = new ListSelector();
        for (int i = 0; i < 5; i++) { // TODO: magic number.
            selector->addContent(new Text(choices[i]));
            other->addContent(new Text(choices[i]));
        }
        box->addContent(selector);
        box->addContent(other);
        this->addContent(box);
    }

    void render(Graphics *graphics, int x, int y) {
        for (Widget *content: this->contents) content->render(graphics, x, y);
    }
};


#endif
