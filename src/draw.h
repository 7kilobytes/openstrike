#ifndef DRAW_H
#define DRAW_H

#include "common.h"

/* struct texture_t { */
/*      int x; */
/*      int y; */
/*      int width; */
/*      int height; */
/*      double angle; */
/*      SDL_Point *center; */
/*      SDL_Rect *cliprect; */
/*      SDL_RenderFlip fliptype; */
/*      SDL_Texture *texture; */
/* }; */

struct rect_t {
     int x;
     int y;
     int w;
     int h;
};

void prepareScene(void);
void presentScene(void);
SDL_Texture *loadTexture(char *filename);
void renderTexture(SDL_Texture *texture, int x, int y);

#endif
