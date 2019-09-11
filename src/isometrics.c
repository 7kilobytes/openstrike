#include "isometrics.h"

void setupRect(SDL_Rect *rect, int x, int y, int w, int h)
{
     rect->x = x;
     rect->y = y;
     rect->w = w;
     rect->h = h;
}

void convert_to_iso(struct point_t *point)
{
     int x = point->x - point->y;
     int y = (point->x + point->y) / 2;

     point->x = x;
     point->y = y;
}

void convert_to_2d(struct point_t *point)
{
     int x = (2 * point->y + point->x) / 2;
     int y = (2 * point->y - point->x) / 2;

     point->x = x;
     point->y = y;
}
