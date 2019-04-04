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
    return this->tiles[width * height * z + y * this->width + x];
}

void Map::setTile(unsigned char value, int x, int y, int z) {
    this->tiles[width * height * z + y * this->width + x] = value;
}

void Map::render(Graphics *graphics, int x, int y, int w, int h, int mx, int my) {
    for (int ix = 0; ix < w; ix++) {
        for (int iy = 0; iy < h; iy++) {
            int tx = (x + ix - (mx - this->width / 2)) % this->width;
            int ty = (y + iy - (my - this->height / 2)) * this->width;
            const Floor *floor = Content::floors + this->getTile(tx, ty, Map::LAYER_FLOOR);
            const Wall *wall = Content::walls + this->getTile(tx, ty, Map::LAYER_WALL);
            graphics->blitTile(floor->tile, ix, iy, floor->fg, floor->bg);
        }
    }
}

void Map::microwave(int x, int y) {
    // TODO: Gotta do some pathfinding algorithms here.

}

void output(std::ostream *stream) {
    // TODO: Gotta output the map to the stream/
}
