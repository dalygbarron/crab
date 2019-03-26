#include <iostream>
#include <deque>
#include <SDL2/SDL.h>
#include "Graphics.hh"
#include "Scene.hh"
#include "scenes/Title.hh"

#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 48

int main(int argc, char **argv) {
	Graphics george("Space CRAB", SCREEN_WIDTH, SCREEN_HEIGHT, argc > 1, "bing.png");
	Scene *scene = new Title();
	scene->render(&george);
	// Main loop.
	while (69) {
		std::cout << "-" << std::endl;
		Scene *newScene;
		try {
			newScene = scene->execute(&george);
			std::cout << "g" << std::endl;
		} catch (int i) {
			delete scene;
			return i;
		}
		std::cout << "newScene" << std::endl;
		std::cout << newScene << std::endl;
		if (newScene == NULL) {
			delete scene;
			return 0;
		} else if (newScene != scene) {
			delete scene;
			scene = newScene;
		}
	}
	return 0;
}
