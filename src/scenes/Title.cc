#include "Title.hh"
#include "../Scene.hh"
#include <string>
#include <cstdlib>

Title(std::string *word)
{
    this->word = word;
}

void update(int key, struct Transition *transition)
{
    transition->scene = this;
}

void render(Graphics *graphics)
{
    graphics->flush(rand() % 0xffffff);
    graphics->frame();
}
