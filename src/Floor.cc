#include "Floor.hh"


Floor::Floor(): tile(0), fg(0), bg(0), description("") {
    // does nothing.
}


Floor::Floor(
    unsigned char tile,
    unsigned int fg,
    unsigned int bg,
    const char *description
): tile(tile), fg(fg), bg(bg), description(description) {
    // does nothing.
}
