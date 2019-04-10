#include "Floor.hh"
#include "Graphics.hh"


Floor::Floor(): tile(0), colour(Colour::WHITE), description("") {
    // does nothing.
}


Floor::Floor(
    unsigned char tile,
    Colour colour,
    const char *description
): tile(tile), colour(colour), description(description) {
    // does nothing.
}
