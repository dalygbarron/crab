#include "Map.hh"

#include <iostream>
#include <queue>
#include "Graphics.hh"
#include "Content.hh"
#include "Vector.hh"

#define SINK_RADIUS 25
#define LIGHT_RADIUS 25

Map::Map(Position dimensions): dimensions(dimensions) {
    this->tiles = new unsigned char[dimensions.x * dimensions.y * Map::LAYER_N];
    this->light = new Colour[dimensions.x * dimensions.y];
}

Map::Map(std::istream *stream): dimensions() {
    // TODO: load the map from stream. and the dimensions bit is obviously wrong as well.
}

Map::~Map() {
    delete this->tiles;
    delete this->light;
}

Colour Map::getLight(Position pos) const {
    return this->light[pos.y * this->dimensions.x + pos.x];
}

void Map::setLight(Position pos, Colour colour) {
    this->light[pos.y * this->dimensions.x + pos.x] = colour;
}

unsigned char Map::getTile(Position pos, int z) const {
    return this->tiles[this->dimensions.x * this->dimensions.y * z + pos.y * this->dimensions.x + pos.x];
}

const Floor *Map::getFloor(Position pos) const {
    return Content::floors +
        this->tiles[
            this->dimensions.x * this->dimensions.y * Map::LAYER_FLOOR + pos.y * this->dimensions.x + pos.x
        ];
}

void Map::setTile(unsigned char value, Position pos, int z) {
    this->tiles[this->dimensions.x * this->dimensions.y * z + pos.y * this->dimensions.x + pos.x] = value;
}

void Map::addCreature(Creature *creature, Position pos) {
    this->creatures.push_front(creature);
    creature->setPosition(pos);
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

void Map::microwave(Position pos) {
    // clear byte maps with large value.
    memset(
        this->tiles + this->dimensions.x * this->dimensions.y * Map::LAYER_SINK,
        0xff,
        sizeof(unsigned char) * this->dimensions.x * this->dimensions.y * 3
    );
    // clear light map with darkness.
    memset(this->light, 0, sizeof(Colour) * this->dimensions.x * this->dimensions.y);
    // calculate new values.
    this->pathing(pos);
    this->lighting(pos);
}

void Map::pathing(Position pos) {
    Position offsets[] = {
        Position(-1, 0),
        Position(1, 0),
        Position(0, -1),
        Position(0, 1),
        Position(-1, -1),
        Position(1, -1),
        Position(1, 1),
        Position(-1, 1)
    };
    std::queue<Position> visit;
    this->setTile(0, pos, Map::LAYER_SINK);
    visit.push(pos);
    while (!visit.empty()) {
        pos = visit.front();
        visit.pop();
        unsigned char value = this->getTile(pos, Map::LAYER_SINK);
        for (Position offset: offsets) {
            if (!this->getTile(pos + offset, Map::LAYER_WALL) && this->getTile(pos + offset, Map::LAYER_SINK) > value + 1 && value < SINK_RADIUS) {
                this->setTile(value + 1, pos + offset, Map::LAYER_SINK);
                visit.push(pos + offset);
            }
        }
    }
    // TODO: cardinal map. Maybe think if I need to do it at all actually.
}

void Map::lighting(Position pos) {
    this->lightScan(pos, -1, 1, 1, 0);
    this->lightScan(pos, -1, 1, 1, 1);
    this->lightScan(pos, -1, 1, 1, 2);
    this->lightScan(pos, -1, 1, 1, 3);
}

void Map::lightScan(Position pos, float startSlope, float endSlope, int iteration, int direction) {
    int dead = false;
    for (int i = iteration; i < LIGHT_RADIUS && !dead; i++) {
        int scanStart = i * startSlope;
        int scanEnd = i * endSlope;
        int blocked = true;
        int clearStart = scanStart;
        for (int c = scanStart; c <= scanEnd; c++) {
            Position current;
            if (direction == 0) current = pos + Position(c, 0 - i);
            else if (direction == 1) current = pos + Position(0 - c, i);
            else if (direction == 2) current = pos + Position(0 - i, 0 - c);
            else if (direction == 3) current = pos + Position(i, c);
            this->setLight(current, Colour::WHITE - Colour(i * 10, i * 10, i * 10));
            this->setTile(true, current, Map::LAYER_SEEN);
            this->setTile(true, current, Map::LAYER_FOV);
            int wall = this->getTile(current, Map::LAYER_WALL);
            if (wall) {
                dead = true;
                if (!blocked) {
                    float innerStart = clearStart / (float)i;
                    float innerEnd = (c - 1) / (float)i;
                    this->lightScan(pos, innerStart, innerEnd, i + 1, direction);
                }
                blocked = true;
            } else {
                if (blocked) {
                    clearStart = c;
                    blocked = false;
                }
            }
        }
        // one last go for when it reaches the end with a single blockage and no new window.
        if (!blocked && dead) {
            this->lightScan(pos, clearStart / (float)i, scanEnd / (float)i, i + 1, direction);
        }
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
                if (this->getTile(tile, Map::LAYER_SEEN)) {
                    Colour light = this->getLight(tile);
                    const Floor *floor = Content::floors + this->getTile(tile, Map::LAYER_FLOOR);
                    int wallIndex = this->getTile(tile, Map::LAYER_WALL);
                    if (wallIndex == 0) {
                        //float height = this->getTile(tile, Map::LAYER_SINK);
                        //graphics->blitTile(0, iteration, floor->colour, Colour(Colour::RED, Colour::NAVY, height / SINK_RADIUS));
                        graphics->blitCharacter(floor->tile, iteration, floor->colour * light);
                    } else {
                        const Wall *wall = Content::walls + wallIndex;
                        graphics->blitCharacter(wall->tile, iteration, wall->colour * light);
                    }
                }
            }
        }
    }
    // Render creatures.
    for (Creature *creature: this->creatures) {
        Position pos = creature->getPosition() - camera;
        if (rect.contains(pos)) graphics->blitTile(3, pos, Colour::RED, this->bg);
    }
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
