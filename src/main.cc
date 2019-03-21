#include <SDL2/SDL.h>
#include "Graphics.hh"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main() {
	Graphics("bingo bongo game time", SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_Delay(2000);

	return 0;
}
