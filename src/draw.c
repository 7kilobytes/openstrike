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

SDL_Texture *loadTexture(char *filename)
{
     SDL_Texture *texture;

     SDL_Log("Loading: %s", filename);
     texture = IMG_LoadTexture(game.renderer, filename);
     if(!texture)
          SDL_Log("Unable to load texture: %s. %s\n", filename, IMG_GetError());

     return texture;
}

void renderTexture(SDL_Texture *texture, int x, int y)
{
     SDL_Rect dst;

     dst.x = x;
     dst.y = y;

     SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
     SDL_RenderCopy(game.renderer, texture, NULL, &dst);
}
