#include "main.h"

int main(int argc, char *argv[])
{
    atexit(close_sdl);
    init_sdl();
    init_music();
    prepare_demo();
    run_demo();
    /* destroy_demo(); */

    /*
    while (1)
    {
        handle_events();
        draw();
        update();
        SDL_Delay(50);
    }
    */

    return 0;
}

void die(char *message)
{
    fprintf(stderr, "%s: %s", message, SDL_GetError());
    exit(1);
}
