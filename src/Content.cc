#include "Content.hh"
#include <sqlite3.h>

#define TAG_QUERY "SELECT category FROM tag LEFT JOIN creature ON tag.creature = creature.id WHERE creature.id = ?"
#define CREATURE_QUERY "SELECT creature.id FROM creature WHERE creature.id = ?"

void loadCreatures(sqlite3 *db) {

}



Content::Content(const char *contentFile) {
    sqlite3 *db;
    char *error = 0;
    int response = sqlite3_open(contentFile, &db);
    if (response) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }
    response = sqlite3_exec(db, CREATURE_QUERY, callback, 0, &error);
    if (response != SQLITE_OK) {
        std::cerr << "SQL Error: " << error << std::endl;
        sqlite3_free(error);
    }
    std::cout << sqlite3_execScalar(db, "SELECT COUNT(*) FROM creature") << " rows." << std::endl;
    sqlite3_close(db);
}

Content::~Content() {
    delete this->protoCreatures;
    delete this->protoItems;
    delete this->floors;
    delete this->walls;
}

const Floor *Content::getFloor(unsigned char index) const {
    return this->floors[index];
}

const Floor *Content::getWall(unsigned char index) const {
    return this->walls[index];
}

Creature *Content::getCreature(unsigned char index) const {
    return new Creature(protoCreatures + index);
}
