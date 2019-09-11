#ifndef ISOMETRICS_H
#define ISOMETRICS_H

#include "common.h"

struct point_t {
     int x;
     int y;
};

void setupRect(SDL_Rect *rect, int x, int y, int w, int h);
void convert_to_iso(struct point_t *point);
void convert_to_2d(struct point_t *point);

#endif
