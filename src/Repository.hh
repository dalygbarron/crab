#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <sqlite3.h>


/**
 * Generic database access class.
 * Intended to have two child classes; Content, and Persistence.
 */
class Repository {
protected:
    /**
     * Loads a database from a file and if there are problems it tries to fail peacefully. Logs errors to stdout.
     * @param file is the filename at which there is the database.
     * @return a pointer to the sqlite database or null if it could not be opened.
     */
    sqlite3 *prepareDatabase(const char *file);

    /**
     * Prepares an sql statement and fails peacefully if necessary. Logs errors to stdout.
     * @param db    is the database we are working on.
     * @param query is the sql query we are preparing.
     * @return the prepared statement object or null if it failed.
     */
    sqlite3_stmt *prepareStatement(sqlite3 *db, const char *query);

    /**
     * Runs a single number query and returns the result to you. technically you can run it for multiple value queries
     * too but it is not going to do you much good.
     * @param db    is the database you are using.
     * @param query is the query.
     * @return first column of first row of query response as an int. Returns 0 if there is a fuckup.
     */
    int processInt(sqlite3 *db, const char *query);
};

#endif
