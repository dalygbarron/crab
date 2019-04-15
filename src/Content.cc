#include "Content.hh"
#include <sqlite3.h>

#define CONTENT_FILE "content.db"
#define TAG_QUERY "SELECT _category.name FROM tag JOIN _category ON tag.category = _category.id WHERE tag.target = 1"
#define CREATURE_QUERY "SELECT * FROM creature"

int callback(void *NotUsed, int argc, char **argv, char **azColName){
    for(int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

void Content::load() {
    sqlite3 *db;
    char *error = 0;
    int response = sqlite3_open(CONTENT_FILE, &db);
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
    sqlite3_close(db);
}

void Content::free() {
    delete Content::protoCreatures;
    delete Content::protoItems;
    delete Content::floors;
    delete Content::walls;
}

Creature *Content::getCreature(unsigned char index) {
    return new Creature(Content::protoCreatures + index);
}
