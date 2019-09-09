#include "src/common.h"

unsigned draw_state_1(float deltatime)
{
     printf("draw: %f\n", deltatime);
}

static void capFrameRate(long *then, float *remainder);

int main(void)
{
     long then;
     float remainder;
     
     memset(&game, 0, sizeof(struct game_t));
     game.options = malloc(sizeof(struct game_options_t *));
     game.options->title = "Open Strike";
     game.options->width = 800;
     game.options->height = 600;
     game.quit = 0;

     STATEMANAGER_init(&game.statemanager);
     struct state_t state_1 = {0};
     state_1.init = init_state;
     state_1.update = update_state;
     state_1.draw = draw_state_1;
     state_1.destroy = destroy_state;
     STATEMANAGER_push(&game.statemanager, &state_1);

     initSDL();

     then = SDL_GetTicks();
     remainder = 0;

     printf("%f\n", then);

     struct entity_t unit = {0};
     unit.x = 100;
     unit.y = 100;
     unit.texture = loadTexture("data/unit.png");

     while(!game.quit) {
          prepareScene();
          STATEMANAGER_update(&game.statemanager, 5.0f);
          updateInput();
          STATEMANAGER_draw(&game.statemanager, 5.0f);
          renderTexture(unit.texture, unit.x, unit.y);
          presentScene();
          /* SDL_Delay(16); */
          capFrameRate(&then, &remainder);
     }

     cleanup();

     return 0;
}

static void capFrameRate(long *then, float *remainder)
{
     long wait;
     long frameTime;

     wait = 16 + *remainder;

     printf("DBG >>> wait: %ld\n", wait);

     *remainder -= (int) *remainder;

     printf("DBG >>> remainder: %ld\n", *remainder);

     frameTime = SDL_GetTicks() - *then;

     printf("DBG >>> frameTime: %ld\n", frameTime);
     wait -= frameTime;

     if(wait < 1)
          wait = 1;

     SDL_Delay(wait);

     *remainder += 0.667;
     *then = SDL_GetTicks();
}
