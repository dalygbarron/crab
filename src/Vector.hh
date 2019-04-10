#ifndef VECTOR_H
#define VECTOR_H

/**
 * Represents a location in 2d space.
 */
class Position {
public:
    short x;
    short y;

    /**
     * default constructor for origin.
     */
    Position();

    /**
     * Constructs a position for you.
     * @param x is the horizontal component.
     * @param y is the vertical component.
     */
    Position(short x, short y);

    /**
     * Addition operator.
     * @param other is the other position to add on to this one.
     * @return the new position.
     */
    Position operator+(Position other);

    /**
     * Subtraction operator.
     * @param other is the other position to remove from this one.
     * @return the new position.
     */
    Position operator-(Position other);

    /**
     * Multiplication operator.
     * @param other is the other position to multiply this one by.
     * @return the new position.
     */
    Position operator*(Position other);

    /**
     * Division operator.
     * @param other is the other position to divide this one by.
     * @return the new position.
     */
    Position operator/(Position other);

    /**
     * Multiplication operator with float.
     * @param other is the other position to multiply this one by.
     * @return the new position.
     */
    Position operator*(float other);

    /**
     * Division operator with float.
     * @param other is the other position to divide this one by.
     * @return the new position.
     */
    Position operator/(float other);
};

/**
 * Represents a rectangle in 2d space.
 */
class Rect {
public:
    Position pos;
    Position size;

    /**
     * Default constructor for origin rect with no size.
     */
    Rect();

    /**
     * Makes a nice rect.
     * @param pos  is the position of the rect's top left corner.
     * @param size is the size of the rect.
     */
    Rect(Position pos, Position size);

    /**
     * Tells you if a given point is inside this rect.
     * @param position is the point to check.
     * @return true if it is and false otherwise.
     */
    int contains(Position position);
};

#endif
