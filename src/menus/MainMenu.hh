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
 * TODO: this class should either be made more generalised or less generalised but right now it's in a dumb middle
 *       ground where it seems completely pointless.
 */
class MainMenu: public Tall {

public:
    /**
     * Creates your nice main menu.
     * @param choices is the list of choices you can have.
     */
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

    void render(Graphics *graphics, int x, int y) override {
        for (Widget *content: this->contents) content->render(graphics, x, y);
    }
};


#endif
