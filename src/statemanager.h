#ifndef ENGINE_STATEMANAGER_H
#define ENGINE_STATEMANAGER_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
     void (*logic)(void);
     void (*draw)(void);
} ref;

struct state_t {
     unsigned int (*init)(void);
     unsigned int (*update)(float deltatime);
     unsigned int (*draw)(float deltatime);
     unsigned int (*destroy)(void);
};

struct state_manager_t {
     struct state_t **stack;
     int capacity;
     int top;
};

int STATEMANAGER_init(struct state_manager_t *sm);
int STATEMANAGER_free(struct state_manager_t *sm);
int STATEMANAGER_scale(struct state_manager_t *sm);
int STATEMANAGER_push(struct state_manager_t *sm, struct state_t *s);
int STATEMANAGER_pop(struct state_manager_t *sm);
struct state_t *STATEMANAGER_top(struct state_manager_t *sm);
int STATEMANAGER_update(struct state_manager_t *sm, float deltatime);
int STATEMANAGER_draw(struct state_manager_t *sm, float deltatime);

unsigned int init_state(void);
unsigned int destroy_state(void);
unsigned int update_state(float deltatime);

#endif
