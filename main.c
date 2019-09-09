#include "src/common.h"

unsigned draw_state_1(float deltatime)
{
     printf("draw: %f\n", deltatime);
}

int main(void)
{
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

     while(!game.quit) {
          prepareScene();
          STATEMANAGER_update(&game.statemanager, 5.0f);
          updateInput();
          STATEMANAGER_draw(&game.statemanager, 5.0f);
          presentScene();
          SDL_Delay(16);
     }

     cleanup();

     return 0;
}
