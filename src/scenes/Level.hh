#ifndef LEVEL_H
#define LEVEL_H

#include "../Layer.hh"
#include "../Map.hh"
#include <iostream>

/**
 * Scene where you play the game for real.
 */
class Level: public Layer
{
    Map *map;
    int x = 0;
    int y = 0;

public:
    Level(Map *map) {
        this->map = map;
    }

    int event(int type, unsigned int parameter) override {
        if (type != Layer::EVENT_KEY) return false;
        if (parameter == SDLK_UP) this->y--;
        if (parameter == SDLK_DOWN) this->y++;
        if (parameter == SDLK_LEFT) this->x--;
        if (parameter == SDLK_RIGHT) this->x++;
        return true;
    }

    void render(Graphics *graphics) override {
        graphics->flush(this->map->colour);
        graphics->blitString("Tony Abbot", graphics->height, 0, Graphics::WHITE);
        graphics->blitString("camel rider", graphics->height, 1, Graphics::WHITE);
        graphics->blitString("+10/20", graphics->height, 2, Graphics::WHITE);
        graphics->blitString("*4/9", graphics->height, 3, Graphics::WHITE);
        graphics->blitString("^123/643", graphics->height, 4, Graphics::WHITE);
        this->map->render(graphics, 0, 0, graphics->height, graphics->height, 20, 20);
        graphics->blitTile(0x03, x, y, Graphics::RED, this->map->colour);
    }
};


#endif
