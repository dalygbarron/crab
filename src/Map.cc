#include "Map.hh"

#include <iostream>
#include <queue>
#include "Graphics.hh"
#include "Content.hh"
#include "Vector.hh"

#define SINK_RADIUS 25
#define LIGHT_RADIUS 25

Map::Map(Position dimensions): dimensions(dimensions) {
    this->layerSize = dimensions.x * dimensions.y;
    this->floors = new Floor const *[this->layerSize];
    this->walls = new Wall const *[this->layerSize];
    this->layers = new unsigned char[this->layerSize * Map::LAYER_N];
    this->light = new Colour[this->layerSize];
}

Map::~Map() {
    delete this->floors;
    delete this->walls;
    delete this->layers;
    delete this->light;
    for (Creature *creature: this->creatures) delete creature;
}

Colour Map::getLight(Position pos) const {
    return this->light[pos.y * this->dimensions.x + pos.x];
}

void Map::setLight(Position pos, Colour colour) {
    this->light[pos.y * this->dimensions.x + pos.x] = colour;
}

void Map::setFloor(const Floor *floor, Position pos) {
    this->floors[pos.y * this->dimensions.x + pos.x] = floor;
}

const Floor *Map::getFloor(Position pos) const {
    return this->floors[pos.y * this->dimensions.x + pos.x];
}

void Map::setWall(const Wall *wall, Position pos) {
    this->walls[pos.y * this->dimensions.x + pos.x] = wall;
}

const Wall *Map::getWall(Position pos) const {
    return this->walls[pos.y * this->dimensions.x + pos.x];
}

void Map::setTile(unsigned char value, Position pos, int z) {
    this->layers[this->layerSize * z + pos.y * this->dimensions.x + pos.x] = value;
}

unsigned char Map::getTile(Position pos, int z) const {
    return this->layers[this->layerSize * z + pos.y * this->dimensions.x + pos.x];
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


void Map::pathing(Position pos) {
    // clear old data.
    memset(this->layers + Map::LAYER_PATH_OFFSET * this->layerSize, 0xff, sizeof(unsigned char) * this->layerSize * Map::LAYER_PATH_N);
    // algorithm
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
    this->setTile(0, pos, Map::LAYER_PATH_SINK);
    visit.push(pos);
    while (!visit.empty()) {
        pos = visit.front();
        visit.pop();
        unsigned char value = this->getTile(pos, Map::LAYER_PATH_SINK);
        for (Position offset: offsets) {
            const Wall *wall = this->getWall(pos + offset);
            unsigned char current = this->getTile(pos + offset, Map::LAYER_PATH_SINK);
            if (!wall && current > value + 1 && value < SINK_RADIUS) {
                this->setTile(value + 1, pos + offset, Map::LAYER_PATH_SINK);
                visit.push(pos + offset);
            }
        }
    }
    // TODO: cardinal map. Maybe think if I need to do it at all actually.
}

void Map::lighting(Position pos) {
    // clear old memory and set up
    memset(this->layers + Map::LAYER_VIEW_OFFSET * this->layerSize, false, sizeof(unsigned char) * this->layerSize * Map::LAYER_VIEW_N);
    for (Creature *creature: this->creatures) this->setTile(true, creature->getPosition(), Map::LAYER_VIEW_TEMP);
    // algorithm,.
    this->lightScan(pos, -1, 1, 1, 0);
    this->lightScan(pos, -1, 1, 1, 1);
    this->lightScan(pos, -1, 1, 1, 2);
    this->lightScan(pos, -1, 1, 1, 3);
    this->setLight(pos, Colour::WHITE);
    this->setTile(true, pos, Map::LAYER_VIEW_FOV);
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
            this->setLight(current, Colour::WHITE - Colour(i * 10 - abs(c), i * 10 - abs(c), i * 10 - abs(c)));
            this->setTile(true, current, Map::LAYER_SEEN);
            this->setTile(true, current, Map::LAYER_VIEW_FOV);
            int wall = this->getWall(current) || this->getTile(current, Map::LAYER_VIEW_TEMP);
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
                    Colour light = this->getLight(tile) + this->ambientLight;
                    int visible = this->getTile(tile, Map::LAYER_VIEW_FOV);
                    const Floor *floor = this->getFloor(tile);
                    const Wall *wall = this->getWall(tile);
                    if (!wall) graphics->blitCharacter(floor->tile, iteration, visible ? floor->colour * light : Colour::DARK_GREY);
                    else graphics->blitCharacter(wall->tile, iteration, visible ? wall->colour * light : Colour::GREY);
                }
            }
        }
    }
    // Render creatures.
    for (Creature *creature: this->creatures) {
        Position tile = creature->getPosition();
        Position pos = creature->getPosition() - camera;
        Colour light = this->getLight(tile);
        int view = this->getTile(tile, Map::LAYER_VIEW_FOV);
        if (rect.contains(pos) && view) graphics->blitTile(3, pos, Colour::RED * light, this->bg);
    }
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
    if (this->getWall(pos)) return;
    // TODO: collision detection and hand to hand combat.
    actor->setPosition(pos);
}
