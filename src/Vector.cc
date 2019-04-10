#include "Vector.hh"

Position::Position() {
    this->x = 0;
    this->y = 0;
}

Position::Position(short x, short y) {
    this->x = x;
    this->y = y;
}

Position Position::operator+(const Position other) {
    Position pos;
    pos.x = this->x + other.x;
    pos.y = this->y + other.y;
    return pos;
}

Position Position::operator-(const Position other) {
    Position pos;
    pos.x = this->x - other.x;
    pos.y = this->y - other.y;
    return pos;
}

Position Position::operator*(const Position other) {
    Position pos;
    pos.x = this->x * other.x;
    pos.y = this->y * other.y;
    return pos;
}

Position Position::operator/(const Position other) {
    Position pos;
    pos.x = this->x / other.x;
    pos.y = this->y / other.y;
    return pos;
}

Position Position::operator*(float other) {
    Position pos;
    pos.x = this->x * other;
    pos.y = this->y * other;
    return pos;
}

Position Position::operator/(float other) {
    Position pos;
    pos.x = this->x / other;
    pos.y = this->y / other;
    return pos;
}

Rect::Rect(): pos(), size() {
    // doesn't need to do anything I think.
}

Rect::Rect(Position pos, Position size): pos(pos), size(size) {
    // does nothing here.
}

int Rect::contains(Position position) {
    return !(
        position.x < 0 || position.x >= this->pos.x + this->size.x || position.y < 0 ||
            position.y >= this->pos.y + this->size.y
    );
}
