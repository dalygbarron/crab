#ifndef LEVEL_H
#define LEVEL_H

#include "../Scene.hh"
#include "../Map.hh"

class Level: public Scene
{
    Map *map;
    int x = 0;
    int y = 0;

public:
    Level(Map *map) {
        this->map = map;
    }

    /**
     * Waits for the user to click out of it and little else.
     * @param key is the keypress we have got.
     */
    Scene *logic(Graphics *graphics) {
        int key = graphics->input();
        if (key == SDLK_UP) this->y--;
        if (key == SDLK_DOWN) this->y++;
        if (key == SDLK_LEFT) this->x--;
        if (key == SDLK_RIGHT) this->x++;
        return this;
    }

    /**
     * Displays the title and it's background and it's nice text. it is opaque.
     * @param graphics helps us acheive this goal.
     */
    void render(Graphics *graphics) {
        for (int i = 0; i < graphics->height; i++) {
            graphics->blitBox(0, i, graphics->width, 1, i);
        }
        graphics->blitCharacter(y, x, y, Graphics::RED);
    }
};


#endif
