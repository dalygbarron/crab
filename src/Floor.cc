#include "Floor.hh"
#include "Graphics.hh"


Floor::Floor(): tile(0), colour(Graphics::WHITE), description("") {
    // does nothing.
}


Floor::Floor(
    unsigned char tile,
    unsigned int colour,
    const char *description
): tile(tile), colour(colour), description(description) {
    // does nothing.
}
