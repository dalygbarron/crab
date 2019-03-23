#ifndef TITLE_H
#define TITLE_H

#include "../Scene.hh"
#include "../menus/GameMenu.hh"
#include <iostream>
#include <cstdlib>

class Title: public Scene
{
    int x = 0;
    int y = 0;

public:
    /**
     * Waits for the user to click out of it and little else.
     * @param key is the keypress we have got.
     * @param transition we will use to go to the next scene real soon.
     */
    int update(int key, struct Transition *transition) {
        if (transition->value >= 0) {
            transition->scene;
            return Scene::STACK_NONE;
        } else {
            transition->scene = new GameMenu();
            return Scene::STACK_PUSH;
        }
    }

    /**
     * Displays the title and it's background and it's nice text. it is opaque.
     * @param graphics helps us acheive this goal.
     * @param active   says whether it's the top scene, and if not background isn't drawn.
     */
    void render(Graphics *graphics, int active) {
        for (int i = 0; i < graphics->height; i++) {
            graphics->blitBox(0, i, graphics->width, 1, i / 2);
        }
        if (active) {
            for (int i = 0; i < graphics->height; i++) {
                graphics->blitString("..Liquid Pig Studios Presents..", 10, i, Graphics::WHITE);
            }
        }
    }
};


#endif
