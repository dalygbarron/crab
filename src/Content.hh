#ifndef CONTENT_H
#define CONTENT_H

#include "Repository.hh"
#include "Creature.hh"
#include "Item.hh"
#include "Floor.hh"
#include "Wall.hh"

/**
 * Contains creative type data about the game.
 */
class Content: public Repository {
    ProtoCreature *protoCreatures;
    ProtoItem *protoItems;
    Floor *floors;
    Wall *walls;

    /**
     * Loads in all the floors at the start.
     * @param db is the sqlite database for reading in data with.
     */
    void loadFloors(sqlite3 *db);

    /**
     * Loads in all the walls at the start.
     * @param db is the sqlite database for reading in data with.
     */
    void loadWalls(sqlite3 *db);

    /**
     * Loads in all the creatures at the start.
     * @param db is the sqlite database for reading in data with.
     */
    void loadCreatures(sqlite3 *db);

    /**
     * Loads in all the items at the start.
     * @param db is the sqlite database for reading in data with.
     */
    void loadItems(sqlite3 *db);

public:
    /**
     * Loads all the game content out of the files and keeps it here.
     * @param contentFile is the sqlite db containing the game's data.
     */
    Content(const char *contentFile);

    /**
     * Deletes all the game content again.
     */
    ~Content();

    /**
     * Gives you a floor tile prototype.
     * @param index is the index of the floor you want in the content db.
     * @return a const pointer to the floor tile so you can look at it's properties.
     */
    const Floor *getFloor(unsigned char index) const;

    /**
     * Gives you a wall tile prototyype.
     * @param index is the index of the wall you want in the content db.
     * @return a const pointer to the wall you chose.
     */
    const Wall *getWall(unsigned char index) const;

    /**
     * Create an instance of a creature based on a prototype which is given by it's index in the array of creatures.
     * @param index is the proto creature you have chosen to proceed with.
     * @return the new creature. It is now yours and you must delete it in due time.
     */
    Creature *getCreature(unsigned char index) const;
};

#endif
