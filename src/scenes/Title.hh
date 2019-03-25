#ifndef TITLE_H
#define TITLE_H

#include "../Scene.hh"
#include <iostream>
#include <cstdlib>
#include "../widgets/Text.hh"

class Title: public Scene
{
    Text bongo = Text("helloooe");
    int x = 0;
    int y = 0;

public:
    /**
     * Waits for the user to click out of it and little else.
     * @param key is the keypress we have got.
     */
    Scene *logic(int key) {
        x += 2;
        y += 1;
        return this;
    }

    /**
     * Displays the title and it's background and it's nice text. it is opaque.
     * @param graphics helps us acheive this goal.
     */
    void render(Graphics *graphics) {
        for (int i = 0; i < graphics->height; i++) {
            graphics->blitBox(0, i, graphics->width, 1, i / 2);
        }
        graphics->blitCharacter(y, x, y, Graphics::RED);
        bongo.render(graphics, 2, 2, 10, 1);
    }
};


#endif
