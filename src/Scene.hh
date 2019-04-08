#ifndef SCENE_H
#define SCENE_H

#include "Widget.hh"
#include "Observer.hh"
#include "Graphics.hh"

/**
 * A single game scene for example the main menu, or the actual part where you play. Each individual
 * menu in the game will also be a scene menu, and they will be arranged in a stack so that scenes
 * will operate on top of other scenes, and then come back to them etc.
 */
class Scene: public Layer {
public:
    virtual ~Scene();

    virtual int event(void *speaker, int type, unsigned int parameter) override = 0;

    virtual void render(Graphics *graphics) override = 0;
};

#endif
