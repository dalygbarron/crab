#ifndef ASSETS_H
#define ASSETS_H

#include "inipp.hh"

/**
 * This is where functions for the loading of various types will be.
 */
class Assets {
	Prototype prototypes[];

public:
	/**
	 * Creates the assets object and preloads all data and builds
	 * all the stuff we want.
	 */
	Assets();

	/**
	 * Creates a new creature based on the name of a given prototypal
	 * creature.
	 * @param name is the name of the prototype to base it on.
	 * @return the freshly created creature which is brand new.
	 */
	Creature *createCreature(string name);

	/**
	 * Gets a pointer to a certain kind of floor.
	 * @param name is the name by which to find the desired floor.
	 */
	const Floor *getFloor(const char *name);

	const Wall *getWall(const char *name);


};

#endif
