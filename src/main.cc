#include <string>
#include <SDL2/SDL.h>
#include "Graphics.hh"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 768

int main() {
	// Starting things up.
	std::string bongo = "bingo bongo game time";
	std::string file = "bing.bmp";
	Graphics george(&bongo, SCREEN_WIDTH, SCREEN_HEIGHT, &file);
	// Main loop.
	int running = 69;
	while (running)
	{
		SDL_Event e;
		while(SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT) running = 0;
			else if (e.type == SDL_KEYDOWN)
			{
				george.blitTile(1, 2, 3, 0xff0000, 0x00ff00);
				george.frame();
			}
        }
	}
	return 0;
}
