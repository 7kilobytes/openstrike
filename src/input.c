#include "input.h"

void updateInput(void)
{
     SDL_Event event;

     while(SDL_PollEvent(&event)) {
          switch(event.type) {
          case SDL_QUIT:
               game.quit = 1;
               break;
          case SDL_KEYUP:
               switch(event.key.keysym.sym) {
               case SDLK_ESCAPE:
                    game.quit = 1;
                    break;
               default:
                    break;
               }
          default:
               break;
          }
     }
}
