#include "Map.hh"

#include <iostream>
#include "Graphics.hh"
#include "Content.hh"
#include "Vector.hh"

Map::Map(Position dimensions): dimensions(dimensions) {
    this->tiles = new unsigned char[dimensions.x * dimensions.y * Map::LAYER_N];
}

Map::Map(std::istream *stream): dimensions() {
    // TODO: load the map from stream. and the dimensions bit is obviously wrong as well.
}

Map::~Map() {
    delete this->tiles;
}

unsigned char Map::getTile(Position position, int z) const {
    return this->tiles[this->dimensions.x * this->dimensions.y * z + position.y * this->dimensions.x + position.x];
}

const Floor *Map::getFloor(Position position) const {
    return Content::floors +
        this->tiles[
            this->dimensions.x * this->dimensions.y * Map::LAYER_FLOOR + position.y * this->dimensions.x + position.x
        ];
}

void Map::setTile(unsigned char value, Position position, int z) {
    this->tiles[this->dimensions.x * this->dimensions.y * z + position.y * this->dimensions.x + position.x] = value;
}

void Map::addCreature(Creature *creature, Position position) {
    this->creatures.push_front(creature);
    creature->setPosition(position);
}

void Map::applyMove(Move move) {
    switch (move.action) {
        case Move::ACTION_WALK:
            this->walk(move.actor, move.parameter);
            return;
        case Move::ACTION_SKIP:
            return;
        case Move::ACTION_INVALID:
            std::cerr << "invalid action!" << std::endl;
            return;
    }
}

void Map::update() {
    for (Creature *creature: this->creatures) this->applyMove(creature->getMove(this));
}

void Map::render(Graphics *graphics, Rect rect, Position middle) {
    Rect bounds(Position(), this->dimensions);
    Position camera = middle - rect.size / 2;
    // render tiles.
    for (int ix = rect.pos.x; ix < rect.pos.x + rect.size.x; ix++) {
        for (int iy = rect.pos.y; iy < rect.pos.y + rect.size.y; iy++) {
            Position iteration(ix, iy);
            Position tile = iteration + camera;
            if (bounds.contains(tile)) {
                const Floor *floor = Content::floors + this->getTile(tile, Map::LAYER_FLOOR);
                int wallIndex = this->getTile(tile, Map::LAYER_WALL);
                if (wallIndex == 0) {
                    graphics->blitCharacter(floor->tile, iteration, floor->colour);
                } else {
                    const Wall *wall = Content::walls + wallIndex;
                    graphics->blitCharacter(wall->tile, iteration, wall->colour);
                }
            }
        }
    }
    // Render creatures.
    for (Creature *creature: this->creatures) {
        Position pos = creature->getPosition() - camera;
        if (rect.contains(pos)) graphics->blitTile(3, pos, Colour::RED, this->topColour);
    }
}

void Map::microwave(Position position) {
    // TODO: Gotta do some pathfinding algorithms here.

}

void Map::output(std::ostream *stream) {
    // TODO: Gotta output the map to the stream/
}

void Map::walk(Creature *actor, int direction) {
    Position pos = actor->getPosition();
    if (direction == Move::DIR_N) {
        pos.y--;
    } else if (direction == Move::DIR_NE) {
        pos.x++;
        pos.y--;
    } else if (direction == Move::DIR_E) {
        pos.x++;
    } else if (direction == Move::DIR_SE) {
        pos.x++;
        pos.y++;
    } else if (direction == Move::DIR_S) {
        pos.y++;
    } else if (direction == Move::DIR_SW) {
        pos.x--;
        pos.y++;
    } else if (direction == Move::DIR_W) {
        pos.x--;
    } else if (direction == Move::DIR_NW) {
        pos.x--;
        pos.y--;
    }
    unsigned char wall = this->getTile(pos, Map::LAYER_WALL);
    if (wall) return;
    // TODO: collision detection and hand to hand combat.
    actor->setPosition(pos);
}
