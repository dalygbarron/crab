#include "Wall.hh"

Wall::Wall(): tile(0), colour(0), description(""), blockSight(0), blockMove(0) {
    // does nothing.
}

Wall::Wall(
    unsigned char tile,
    unsigned int colour,
    const char *description
): tile(tile), colour(colour), description(description), blockSight(0), blockMove(0) {
    // does nothing.
}
