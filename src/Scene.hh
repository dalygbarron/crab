#ifndef SCENE_H
#define SCENE_H

#include "Observer.hh"
#include "Graphics.hh"

/**
 * A single game scene for example the main menu, or the actual part where you play. Each individual
 * menu in the game will also be a scene menu, and they will be arranged in a stack so that scenes
 * will operate on top of other scenes, and then come back to them etc.
 */
class Scene: public Listener {
    Widget *gui = NULL;

    /**
     * Actually does the scene's self sorting out logic.
     * @return the next scene. same for same, new one for new scene, and null for end game.
     */
    virtual Scene *logic() = 0;

public:
    virtual ~Scene();

    /**
     * Override
     */
    virtual int event(int type, int parameter) = 0;

    /**
     * Sorts out the scene's gui widgets and then does it's logic.
     * @return the next scene. same for same, new one for new scene, and null for end game.
     */
    Scene *update();

    /**
     * Displays the scene.
     * @param graphics is the graphics system used for drawing.
     */
    virtual void render(Graphics *graphics) = 0;
};

#endif
