#ifndef SCENE_H
#define SCENE_H

#include "Graphics.hh"

/**
 * A single game scene for example the main menu, or the actual part where you play. Each individual
 * menu in the game will also be a scene menu, and they will be arranged in a stack so that scenes
 * will operate on top of other scenes, and then come back to them etc.
 */
class Scene {
    /**
     * Does stuff.
     */
    virtual Scene *logic(int key) = 0;

    /**
     * Displays the scene.
     * @param graphics is the graphics system used for drawing.
     */
    virtual void render(Graphics *graphics) = 0;

public:
    /**
     * Lets the scene do an update on a user keypress.
     * @param graphics is used for rendering.
     */
    Scene *execute(Graphics *graphics);
};

#endif
