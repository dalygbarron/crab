#ifndef SCENE_H
#define SCENE_H

#include "Graphics.hh"

class Scene;

/**
 * Data structure for defining the transition from one scene to the next.
 */
struct Transition
{
    Scene *scene;
    int stack;
};

/**
 * A single game scene for example the main menu, or the actual part where you play. Each individual
 * menu in the game will also be a scene menu, and they will be arranged in a stack so that scenes
 * will operate on top of other scenes, and then come back to them etc.
 */
class Scene
{
public:
    /**
     * Lets the scene do an update on a user keypress.
     * @param key is the keycode that the user has given.
     * @param transition defines where the game state will go after this frame.
     */
    virtual void update(int key, struct Transition *transition) = 0;

    /**
     * Displays the scene.
     * @param graphics is the graphics system used for drawing.
     */
    virtual void render(Graphics *graphics) = 0;
};


#endif
