#ifndef SCENE_H
#define SCENE_H

#include "Graphics.hh"

class Scene;

struct Transition
{
    Scene *scene;
    int value;
};

/**
 * A single game scene for example the main menu, or the actual part where you play. Each individual
 * menu in the game will also be a scene menu, and they will be arranged in a stack so that scenes
 * will operate on top of other scenes, and then come back to them etc.
 */
class Scene
{
public:
    static const int STACK_REPLACE = 0;
    static const int STACK_PUSH = -1;
    static const int STACK_POP = -2;
    static const int STACK_CLOSE = -3;
    static const int STACK_NONE = -4;

    /**
     * Lets the scene do an update on a user keypress.
     * @param key is the keycode that the user has given.
     * @param transition defines where the game state will go after this frame.
     * @param
     */
    virtual int update(int key, struct Transition *transition) = 0;

    /**
     * Displays the scene.
     * @param graphics is the graphics system used for drawing.
     * @param active   is a flag to tell the scene if it's the top scene or not so it can look duller or save effort if
     *                 it's just in the background.
     */
    virtual void render(Graphics *graphics, int active = 69) = 0;
};


#endif
