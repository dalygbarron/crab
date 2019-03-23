#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "../Scene.hh"
#include <forward_list>
#include "../widgets/ListSelector.hh"
#include "../widgets/Text.hh"

/**
 * This is the menu where you choose whether you want to play or quit or something else etc.
 */
class GameMenu: public Scene {
    ListSelector *list;

public:
    /**
     * Creates the menu and the stuff it holds within.
     */
    GameMenu() {
        std::forward_list<Widget *> *choices = new std::forward_list<Widget *>();
        choices->push_front(new Text(20, 1, "Quit"));
        choices->push_front(new Text(20, 1, "Credits"));
        choices->push_front(new Text(20, 1, "Options"));
        choices->push_front(new Text(20, 1, "Guide"));
        choices->push_front(new Text(20, 1, "Load Game"));
        choices->push_front(new Text(20, 1, "New Game"));
        list = new ListSelector(20, 6, choices);
    }

    /**
     * Frees the selection list.
     */
    ~GameMenu() {
        delete list;
    }

    /**
     * Updates the menu and it's widgets and stuff.
     * @param key is the keypress from the player to the menu.
     * @param transition defines what the menu has made of this keypress.
     */
    int update(int key, struct Transition *transition) {
        int choice = this->list->update(key);
        if (choice >= 0) {
            transition->value = choice;
            return Scene::STACK_POP;
        }
        return Scene::STACK_NONE;
    }

    /**
     * displays the menu.
     * @param graphics is the drawing thingy.
     * @param active is whether this menu is currently active. If not it's a good idea to dull it.
     */
    void render(Graphics *graphics, int active = 69) {
        graphics->blitBox(14, 19, 21, 7, Graphics::NAVY);
        graphics->blitString("CRAB LAND @it@ih@ie GAME", 14, 19, Graphics::ORANGE);
        list->render(graphics, 15, 20);
    }


};

#endif
