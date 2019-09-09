#include "init.h"
#include "common.h"

int initSDL(void)
{
     int rendererFlags, windowFlags;

     rendererFlags = SDL_RENDERER_ACCELERATED;
     windowFlags = 0;

     if(SDL_Init(SDL_INIT_VIDEO) < 0) {
          SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
          STATEMANAGER_free(&game.statemanager);
          return 1;
     }

     game.window = SDL_CreateWindow(game.options->title,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    game.options->width,
                                    game.options->height,
                                    windowFlags);

     SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
     game.renderer = SDL_CreateRenderer(game.window, -1, rendererFlags);

     IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

     return 0;
}

int cleanup(void)
{
     
     STATEMANAGER_free(&game.statemanager);
     SDL_DestroyRenderer(game.renderer);
     SDL_DestroyWindow(game.window);
     SDL_Quit();
     return 0;
}
