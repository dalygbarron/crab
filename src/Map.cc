#include "Map.hh"

Map::Map(int width, int height) {
    this->floors = new *Floor[width * height];
    this->walls = new *Wall[width * height];
    this->warmths = new unsigned char[width * height * Map::WARMTH_N];
    this->width = width;
    this->height = height;
}

Map::Map(istream *stream) {
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
            Tile *tile = this->walls[(x + ix) % this->width + (y + iy) * this->width];
            graphics->blitTile(tile->tile, ix, iy, );

        }
    }

}

unsigned char Map::getWarmth(int x, int y, int type) {
    return this->warmths[type * this->width * this->height + x % this->width + y * this->width];
}

void Map::recalculateWarmth(int x, int y) {
    // TODO: Gotta do some pathfinding algorithms here.

}

void output(ostream *stream) {
    // TODO: Gotta output the map to the stream/
}
