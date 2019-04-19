#include "Content.hh"
#include <sqlite3.h>
#include "Queries.gen.hh"

void Content::loadFloors(sqlite3 *db) {
    int count = this->processInt(db, Queries::countFloors);
    this->floors = new Floor[count];
    sqlite3_stmt *floors = this->prepareStatement(db, Queries::allFloors);
    int response = sqlite3_step(floors);
    while (response == SQLITE_ROW) {
        int id = sqlite3_column_int(floors, 0);
        this->floors[id - 1].tile = sqlite3_column_int(floors, 1);
        this->floors[id - 1].colour = Colour(sqlite3_column_int(floors, 2));
        this->floors[id - 1].description = (const char *)sqlite3_column_text(floors, 3);
        response = sqlite3_step(floors);
    }
    sqlite3_finalize(floors);
}

void Content::loadWalls(sqlite3 *db) {
    int count = this->processInt(db, Queries::countWalls);
    this->walls = new Wall[count];
    sqlite3_stmt *walls = this->prepareStatement(db, Queries::allWalls);
    int response = sqlite3_step(walls);
    while (response == SQLITE_ROW) {
        int id = sqlite3_column_int(walls, 0);
        this->walls[id - 1].description = (const char *)sqlite3_column_text(walls, 1);
        this->walls[id - 1].tile = sqlite3_column_int(walls, 2);
        this->walls[id - 1].colour = Colour(sqlite3_column_int(walls, 3));
        this->walls[id - 1].blockSight = sqlite3_column_int(walls, 4);
        this->walls[id - 1].blockMove = sqlite3_column_int(walls, 5);
        response = sqlite3_step(walls);
    }
    sqlite3_finalize(walls);
}

void Content::loadCreatures(sqlite3 *db) {
    int count = this->processInt(db, Queries::countCreatures);
    this->protoCreatures = new ProtoCreature[count];
    sqlite3_stmt *creatures = this->prepareStatement(db, Queries::allCreatures);
    int response = sqlite3_step(creatures);
    while (response == SQLITE_ROW) {
        int id = sqlite3_column_int(creatures, 0);
        this->protoCreatures[id - 1].name = (const char *)sqlite3_column_text(creatures, 1);
        this->protoCreatures[id - 1].description = (const char *)sqlite3_column_text(creatures, 2);
        this->protoCreatures[id - 1].tile = sqlite3_column_int(creatures, 3);
        this->protoCreatures[id - 1].colour = Colour(sqlite3_column_int(creatures, 4));
        this->protoCreatures[id - 1].temperament = sqlite3_column_int(creatures, 5);
        this->protoCreatures[id - 1].rating = sqlite3_column_int(creatures, 6);
        this->protoCreatures[id - 1].strength = sqlite3_column_int(creatures, 7);
        this->protoCreatures[id - 1].intelligence = sqlite3_column_int(creatures, 8);
        this->protoCreatures[id - 1].mobility = sqlite3_column_int(creatures, 9);
        response = sqlite3_step(creatures);
    }
    sqlite3_finalize(creatures);
}

void Content::loadItems(sqlite3 *db) {
    // I ain't done items yet so this sits dormant.
}


Content::Content(const char *contentFile) {
    sqlite3 *db = this->prepareDatabase(contentFile);
    if (!db) throw "Fuck, can't open content database.";
    this->loadFloors(db);
    this->loadWalls(db);
    this->loadCreatures(db);
    this->loadItems(db);
    sqlite3_close(db);
}

Content::~Content() {
    delete this->protoCreatures;
    delete this->protoItems;
    delete this->floors;
    delete this->walls;
}

const Floor *Content::getFloor(unsigned char index) const {
    return this->floors + index;
}

const Wall *Content::getWall(unsigned char index) const {
    return this->walls + index;
}

Creature *Content::getCreature(unsigned char index) const {
    return new Creature(protoCreatures + index);
}
