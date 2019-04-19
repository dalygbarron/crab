#ifndef LEVEL_H
#define LEVEL_H

#include "../Layer.hh"
#include "../Map.hh"
#include "../Player.hh"
#include "../Content.hh"
#include "../Creature.hh"
#include <iostream>

/**
 * Scene where you play the game for real.
 */
class Level: public Layer
{
    Map *map;
    Player *player;

    /**
     * Runs a game turn.
     * @param move is the player's move in this turn.
     */
    void turn(Move move) {
        this->map->applyMove(move);
        this->map->pathing(this->player->getPosition());
        this->map->update();
        this->map->lighting(this->player->getPosition());
    }

public:
    Level(Map *map, Position playerPos) {
        this->map = map;
        player = new Player();
        map->addCreature(player, playerPos);
        this->map->lighting(this->player->getPosition());
    }

    int event(int type, unsigned int parameter) override {
        if (type != Layer::EVENT_KEY) return false;
        else if (parameter == SDLK_UP) this->turn(Move(this->player, Move::ACTION_WALK, Move::DIR_N));
        else if (parameter == SDLK_DOWN) this->turn(Move(this->player, Move::ACTION_WALK, Move::DIR_S));
        else if (parameter == SDLK_LEFT) this->turn(Move(this->player, Move::ACTION_WALK, Move::DIR_W));
        else if (parameter == SDLK_RIGHT) this->turn(Move(this->player, Move::ACTION_WALK, Move::DIR_E));
        return true;
    }

    void render(Graphics *graphics) override {
        Rect mapBox(Position(), Position(graphics->dimensions.y, graphics->dimensions.y));
        graphics->flush(this->map->bg);
        graphics->blitString("\x03""Tony Abbot", Position(graphics->dimensions.y, 0), Colour::WHITE);
        graphics->blitString("\xe3""Chinese FB-69", Position(graphics->dimensions.y, 1), Colour::WHITE);
        graphics->blitString("+10/20", Position(graphics->dimensions.y, 2), Colour::WHITE);
        graphics->blitString("*4/9", Position(graphics->dimensions.y, 3), Colour::WHITE);
        graphics->blitString("^123/643", Position(graphics->dimensions.y, 4), Colour::WHITE);
        this->map->render(graphics, mapBox, this->player->getPosition());
    }
};


#endif
