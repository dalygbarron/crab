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
    // TODO: implement.
}


void Map::render(Graphics *graphics, Rect rect, Position middle) {
    Rect bounds(Position(), this->dimensions);
    Position camera = middle - this->dimensions / 2;
    // render tiles.
    for (int ix = 0; ix < rect.size.x; ix++) {
        for (int iy = 0; iy < rect.size.y; iy++) {
            Position iteration(ix, iy);
            Position tile = rect.pos + iteration - camera;
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
        Position pos = creature->getPosition();
        graphics->blitCharacter(3, pos - camera, Colour::RED);
    }
}

void Map::microwave(Position position) {
    // TODO: Gotta do some pathfinding algorithms here.

}

void output(std::ostream *stream) {
    // TODO: Gotta output the map to the stream/
}
