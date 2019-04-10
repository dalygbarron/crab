#ifndef LEVEL_H
#define LEVEL_H

#include "../Layer.hh"
#include "../Map.hh"
#include "../Player.hh"
#include <iostream>

/**
 * Scene where you play the game for real.
 */
class Level: public Layer
{
    Map *map;
    Player *player;

public:
    Level(Map *map, Position playerPos) {
        this->map = map;
        player = new Player();
        map->addCreature(player, playerPos);
    }

    int event(int type, unsigned int parameter) override {
        if (type != Layer::EVENT_KEY) return false;
        // if (parameter == SDLK_UP) this->y--;
        // if (parameter == SDLK_DOWN) this->y++;
        // if (parameter == SDLK_LEFT) this->x--;
        // if (parameter == SDLK_RIGHT) this->x++;
        return true;
    }

    void render(Graphics *graphics) override {
        Rect mapBox(Position(), Position(graphics->dimensions.y, graphics->dimensions.y));
        graphics->flushGradient(this->map->topColour, this->map->bottomColour);
        graphics->blitString("Tony Abbot", Position(graphics->dimensions.y, 0), Colour::WHITE);
        graphics->blitString("camel rider", Position(graphics->dimensions.y, 1), Colour::WHITE);
        graphics->blitString("+10/20", Position(graphics->dimensions.y, 2), Colour::WHITE);
        graphics->blitString("*4/9", Position(graphics->dimensions.y, 3), Colour::WHITE);
        graphics->blitString("^123/643", Position(graphics->dimensions.y, 4), Colour::WHITE);
        this->map->render(graphics, mapBox, Position(20, 20));
        // graphics->blitTile(0x03, x, y, Colour::RED, this->map->colour);
    }
};


#endif
