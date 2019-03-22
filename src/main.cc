#include <deque>
#include <string>
#include <SDL2/SDL.h>
#include "Graphics.hh"
#include "Scene.hh"
#include "scenes/Title.hh"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 768

int main() {
	// Starting things up.
	std::string bongo = "bingo bongo game time";
	std::string file = "bing.png";
	Graphics george(&bongo, SCREEN_WIDTH, SCREEN_HEIGHT, &file);
	std::deque<Scene *> scenes;
	scenes.push_back(new Title(&bongo));
	// Main loop.
	int running = 69;
	while (running) {
		SDL_Event e;
		Transition transition;
		// Render scenes in stack.
		for (Scene *scene: scenes) scene->render(&george);
		// get events for scene update.
		while(69) {
			if (SDL_PollEvent(&e) == 0) {
				continue;
			} else {
				if (e.type == SDL_QUIT) {
					running = 0;
				} else if (e.type == SDL_KEYDOWN) {
					scenes.back()->update(e.key.keysym.sym, &transition);
					if (!transition.scene) {
						scenes.pop_back();
					} else if (transition.scene != scenes.back()) {
						scenes.push_back(transition.scene);
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
