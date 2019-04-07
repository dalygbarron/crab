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
class Scene: public Listener {
    Widget *gui = NULL;

protected:
    /**
     * Adds a widget that renders in front of the scene, taking control away from it.
     * @param input is needed to hook up the new gui thingy for input listening.
     * @param gui is the new widget to do this with.
     */
    void addGui(Input *input, Widget *gui);

    /**
     * Remove the widget that is currently taking control away from the scene.
     */
    void removeGui();

public:
    virtual ~Scene();

    /**
     * Override
     */
    virtual int event(Speaker *speaker, int type, int parameter) = 0;

    /**
     * Scene's unique rendering functionality. Does not display gui.
     * @param graphics is the graphics system used for drawing.
     */
    virtual void render(Graphics *graphics) = 0;

    /**
     * Renders the scene and any gui to the screen.
     * @param graphics is the graphics system to render with.
     */
    void display(Graphics *graphics);
};

#endif
