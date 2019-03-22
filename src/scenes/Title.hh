#ifndef TITLE_H
#define TITLE_H

#include "../Scene.hh"
#include <string>

class Title: public Scene
{
    std::string *word;
    int x = 0;
    int y = 0;

public:
    /**
     * Creates teh title scene.
     * @param word is the word written as the title.
     */
    Title(std::string *word);

    /**
     * Waits for the user to click out of it and little else.
     * @param key is the keypress we have got.
     * @param transition we will use to go to the next scene real soon.
     */
    void update(int key, struct Transition *transition);

    /**
     * Displays the title and it's background and it's nice text. it is opaque.
     * @param graphics helps us acheive this goal.
     */
    void render(Graphics *graphics);
};


#endif
