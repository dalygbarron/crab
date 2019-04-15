#include "Content.hh"

Creature *Content::getCreature(unsigned char index) {
    return new Creature(Content::protoCreatures + index);
}
