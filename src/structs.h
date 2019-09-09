#ifndef STRUCTS_H
#define STRUCTS_H

#include "common.h"

struct game_options_t {
     char *title;
     int width;
     int height;
};

struct game_t {
     SDL_Renderer *renderer;
     SDL_Window *window;
     int quit;
     struct game_options_t *options;
     struct state_manager_t statemanager;
};

#endif
