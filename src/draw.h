#ifndef DRAW_H
#define DRAW_H

#include "common.h"

void prepareScene(void);
void presentScene(void);
SDL_Texture *loadTexture(char *filename);
void renderTexture(SDL_Texture *texture, int x, int y);

#endif
