#include "statemanager.h"

int STATEMANAGER_init(struct state_manager_t *sm)
{
     // TODO: make logger
     // printf("DBG >>> STATEMANAGER INIT\n");
     sm->capacity = 3;
     sm->stack = malloc(sm->capacity * sizeof(struct state_t *));
     sm->top = -1;

     return 0;
}

int STATEMANAGER_free(struct state_manager_t *sm)
{
     do {
          STATEMANAGER_pop(sm);
     } while (sm->top > -1);
     free(sm->stack);

     return 0;
}

int STATEMANAGER_scale(struct state_manager_t *sm)
{
     sm->capacity *= 2;
     sm->stack = realloc(sm->stack, sm->capacity * sizeof(struct state_t *));
     return sm->capacity;
}

int STATEMANAGER_push(struct state_manager_t *sm, struct state_t *s)
{
     if(sm->top + 1 == sm->capacity)
          STATEMANAGER_scale(sm);
     sm->top++;
     sm->stack[sm->top] = s;

     if(s->init != NULL)
          s->init();

     return sm->top;
}
     
int STATEMANAGER_pop(struct state_manager_t *sm)
{
     if(sm->top == -1)
          return 0;

     struct state_t *top = STATEMANAGER_top(sm);

     if(top->destroy != NULL)
          top->destroy();

     sm->stack[sm->top] = NULL;
     sm->top--;

     return sm->top;
}

struct state_t *STATEMANAGER_top(struct state_manager_t *sm)
{
     return sm->stack[sm->top];
}

int STATEMANAGER_update(struct state_manager_t *sm, float deltatime)
{
     struct state_t *state = STATEMANAGER_top(sm);
     if(state->update != NULL)
          return state->update(deltatime);

     return 1;
}

int STATEMANAGER_draw(struct state_manager_t *sm, float deltatime)
{
     struct state_t *state = STATEMANAGER_top(sm);
     if(state->draw != NULL)
          return state->draw(deltatime);

     return 1;
}

unsigned int init_state(void)
{
     printf("state created.\n");
     return 0;
}

unsigned int destroy_state(void)
{
     printf("state destroyed.\n");
     return 0;
}

unsigned int update_state(float deltatime)
{
     printf("state update %f.\n", deltatime);
     return 0;
}
