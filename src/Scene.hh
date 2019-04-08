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
class Scene: public Listener, public Layer {
    Widget *gui = NULL;

    virtual int event(void *speaker, int type, int parameter) override = 0;

    virtual void render(Graphics *graphics) override = 0;

public:
    virtual ~Scene();

    /**
     * Adds a widget that renders in front of the scene, taking control away from it.
     * @param input is needed to hook up the new gui thingy for input listening.
     * @param gui is the new widget to do this with.
     */
    void addGui(Input *input, Widget *gui);

    /**
     * Remove the widget that is currently taking control away from the scene.
     */
    void removeGui(Input *input);
};

#endif
