#include "draw.h"

void prepareScene(void)
{
     SDL_SetRenderDrawColor(game.renderer, 41, 41, 41, 255);
     SDL_RenderClear(game.renderer);
}

void presentScene(void)
{
     SDL_RenderPresent(game.renderer);
}
