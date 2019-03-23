#ifndef SCENE_H
#define SCENE_H

#include "Graphics.hh"

class Scene;

/**
 * Data structure for defining the transition from one scene to the next.
 * The type code is used to determine how to exit the current scene. If it is >= 0 then the scene is
 * replaced with the scene stored in scene and the given value is sent to the next scene in the
 * value field. If it is -1 the new scene stored in scene is used. If it is -2 the program closes,
 * and if it is -3 then nothing happens.
 */
struct Transition
{
    Scene *scene;
    int type;
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
    static const int STACK_CLOSE = -2;
    static const int STACK_NONE = -3;

    /**
     * Lets the scene do an update on a user keypress.
     * @param key is the keycode that the user has given.
     * @param transition defines where the game state will go after this frame.
     */
    virtual void update(int key, struct Transition *transition) = 0;

    /**
     * Displays the scene.
     * @param graphics is the graphics system used for drawing.
     * @param active   is a flag to tell the scene if it's the top scene or not so it can look duller or save effort if
     *                 it's just in the background.
     */
    virtual void render(Graphics *graphics, int active = 69) = 0;
};


#endif
