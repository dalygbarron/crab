#include "Map.hh"

Map::Map(int width, int height) {
    this->walls = new Wall[width * height];
    this->warmths = new unsigned char[width * height * Map::WARMTH_N];
    this->width = width;
    this->height = height;
}

Map::Map(istream *stream) {
    // TODO: load the map from stream.
}

Map::~Map() {
    delete this->walls;
    delete this->warmths;
}

Wall const *Map::getWall(int x, int y) {
    return this->walls[x % this->width + y * this->width];
}

void Map::setWall(int x, int y, Wall const *wall) {
    this->walls[x % this->width + y * this->width] = wall;
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
