#include "Wall.hh"
#include "Graphics.hh"

Wall::Wall(): tile(0), colour(), description(""), blockSight(0), blockMove(0) {
    // does nothing.
}

Wall::Wall(
    unsigned char tile,
    Colour colour,
    const char *description
): tile(tile), colour(colour), description(description), blockSight(0), blockMove(0) {
    // does nothing.
}
