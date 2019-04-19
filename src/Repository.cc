#include "Repository.hh"
#include <iostream>
#include "Queries.gen.hh"

sqlite3 *Repository::prepareDatabase(const char *file) {
    sqlite3 *db;
    char *error = 0;
    int response = sqlite3_open(file, &db);
    if (response) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }
    return db;
}

sqlite3_stmt *Repository::prepareStatement(sqlite3 *db, const char *query) {
    sqlite3_stmt *statement;
    int response = sqlite3_prepare_v2(db, query, -1, &statement, 0);
    if (response) {
        std::cerr << "Can't prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(statement);
        return 0;
    }
    return statement;
}

int Repository::processInt(sqlite3 *db, const char *query) {
    sqlite3_stmt *statement = this->prepareStatement(db, query);
    int response = sqlite3_step(statement);
    int count = 0;
    if (response == SQLITE_ROW) {
        count = sqlite3_column_int(statement, 0);
    }
    sqlite3_finalize(statement);
    return count;
}
