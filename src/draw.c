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
     SDL_Rect src;

     dst.x = x;
     dst.y = y;

     src.x = 0;
     src.y = 0;

     SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);

     /* printf("TEXTURE DBG >>> x: %d, y: %d, w: %d, h:%d\n", src.x, src.y, src.w, src.h); */

     src.w = 128;
     src.h = 64;

     dst.w = 128;
     dst.h = 64;

     /* src.x = 4 * 128; */
     /* src.y = 2 * 64; */

     /* src.w = 128; */
     /* src.h = 64; */
     

     SDL_RenderCopy(game.renderer, texture, &src, &dst);

     /* printf("TEXTURE COPY DBG >>> SRC: x: %d, y: %d, w: %d, h:%d\n", src.x, src.y, src.w, src.h); */
     printf("TEXTURE COPY DBG >>> DST: x: %d, y: %d, w: %d, h:%d\n", dst.x, dst.y, dst.w, dst.h);

     /* SDL_Rect dst = {0}; */

     /* SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h); */
     /* printf("TEXTURE DBG >>> x: %d, y: %d, w: %d, h:%d\n", dst.x, dst.y, dst.w, dst.h); */

     /* dst.w = 128; */
     /* dst.h = 64; */

     /* SDL_RenderCopy(game.renderer, texture, &dst, &dst); */
}
