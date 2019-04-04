#include "Map.hh"

#include <iostream>
#include "Graphics.hh"

Map::Map(int width, int height) {
    this->floors = new const Floor*[width * height];
    this->walls = new const Wall*[width * height];
    this->warmths = new unsigned char[width * height * Map::WARMTH_N];
    this->width = width;
    this->height = height;
}

Map::Map(std::istream *stream) {
    // TODO: load the map from stream.
}

Map::~Map() {
    delete this->floors;
    delete this->walls;
    delete this->warmths;
}

Wall const *Map::getWall(int x, int y) {
    return this->walls[x % this->width + y * this->width];
}

void Map::setWall(int x, int y, Wall const *wall) {
    this->walls[x % this->width + y * this->width] = wall;
}

void Map::render(Graphics *graphics, int x, int y, int w, int h, int mx, int my) {
    for (int ix = 0; ix < w; ix++) {
        for (int iy = 0; iy < h; iy++) {
            int tx = (x + ix - (mx - this->width / 2)) % this->width;
            int ty = (y + iy - (my - this->height / 2)) * this->width;
            const Floor *floor = this->floors[(x + ix) % this->width + (y + iy) * this->width];
            const Wall *wall = this->walls[(x + ix) % this->width + (y + iy) * this->width];
            graphics->blitTile(floor->tile, ix, iy, floor->fg, floor->bg);

        }
    }

}

unsigned char Map::getWarmth(int x, int y, int type) {
    return this->warmths[type * this->width * this->height + x % this->width + y * this->width];
}

void Map::recalculateWarmth(int x, int y) {
    // TODO: Gotta do some pathfinding algorithms here.

}

void output(std::ostream *stream) {
    // TODO: Gotta output the map to the stream/
}
