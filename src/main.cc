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
	// Main loop.
	while (69) {
		std::cout << "scene go" << std::endl;
		Scene *newScene;
		try {
			newScene = scene->execute(&george);
		} catch (int i) {
			return i;
		}
		if (newScene == NULL) {
			delete scene;
			break;
		} else if (newScene != scene) {
			delete scene;
			scene = newScene;
		}
	}
	return 0;
}
