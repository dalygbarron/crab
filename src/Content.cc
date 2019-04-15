#include "Content.hh"
#include <sqlite3.h>

#define CONTENT_FILE "content.db"
#define QUERY "SELECT * FROM tag"

int callback(void *NotUsed, int argc, char **argv, char **azColName){
    for(int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

void Content::load() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc = sqlite3_open(CONTENT_FILE, &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }
    rc = sqlite3_exec(db, QUERY, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL Error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
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
