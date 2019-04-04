#include "Map.hh"

#include <iostream>
#include "Graphics.hh"
#include "Content.hh"

Map::Map(int width, int height) {
    this->tiles = new unsigned char[width * height * Map::LAYER_N];
    this->width = width;
    this->height = height;
}

Map::Map(std::istream *stream) {
    // TODO: load the map from stream.
}

Map::~Map() {
    delete this->tiles;
}

unsigned char Map::getTile(int x, int y, int z) {
    return this->tiles[this->width * this->height * z + y * this->width + x];
}

void Map::setTile(unsigned char value, int x, int y, int z) {
    this->tiles[this->width * this->height * z + y * this->width + x] = value;
}

const Floor *Map::getFloor(int x, int y) {
    return Content::floors +
        this->tiles[this->width * this->height * Map::LAYER_FLOOR + y * this->width + x];
}


void Map::render(Graphics *graphics, int x, int y, int w, int h, int mx, int my) {
    for (int ix = 0; ix < w; ix++) {
        for (int iy = 0; iy < h; iy++) {
            int tx = (x + ix - (mx - this->width / 2));
            int ty = (y + iy - (my - this->height / 2));
            if (tx < 0 || ty < 0 || tx >= this->width || ty >= this->height) {
                graphics->blitTile(0, ix, iy, 0, 0);
            } else {
                const Floor *floor = Content::floors + this->getTile(tx, ty, Map::LAYER_FLOOR);
                int wallIndex = this->getTile(tx, ty, Map::LAYER_WALL);
                if (wallIndex == 0) {
                    graphics->blitTile(floor->tile, ix, iy, floor->fg, floor->bg);
                } else {
                    const Wall *wall = Content::walls + wallIndex;
                    graphics->blitTile(wall->tile, ix, iy, wall->colour, floor->bg);
                }
            }
        }
    }
}

void Map::microwave(int x, int y) {
    // TODO: Gotta do some pathfinding algorithms here.

}

void output(std::ostream *stream) {
    // TODO: Gotta output the map to the stream/
}
