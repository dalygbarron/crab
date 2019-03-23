#include <iostream>
#include <deque>
#include <SDL2/SDL.h>
#include "Graphics.hh"
#include "Scene.hh"
#include "scenes/Title.hh"

#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 48

int main(int argc, char *argv) {
	// Starting things up.
	Graphics george("Space CRAB", SCREEN_WIDTH, SCREEN_HEIGHT, argc > 1, "bing.png");
	std::deque<Scene *> scenes;
	scenes.push_back(new Title());
	// Main loop.
	int running = 69;
	Transition transition;
	transition.value = -1;
	while (running) {
		std::cout << "tick" << std::endl;
		SDL_Event e;
		// Render scenes in stack.
		for (Scene *scene: scenes) scene->render(&george, scenes.back() == scene);
		george.frame();
		// get events for scene update.
		while(69) {
			if (SDL_PollEvent(&e) == 0) {
				continue;
			} else {
				if (e.type == SDL_QUIT || scenes.empty()) {
					running = 0;
				} else if (e.type == SDL_KEYDOWN) {
					int type = scenes.back()->update(e.key.keysym.sym, &transition);
					if (type >= 0) {
						scenes.pop_back();
						scenes.push_back(transition.scene);
						transition.value = type;
					} else if (type == Scene::STACK_PUSH) {
						scenes.push_back(transition.scene);
						transition.value = -1;
					} else if (type == Scene::STACK_POP) {
						scenes.pop_back();
					} else if (type == Scene::STACK_CLOSE) {
						running = 0;
					}
				} else {
					continue;
				}
				break;
			}
        }
	}
	return 0;
}
