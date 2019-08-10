#include "gfx.h"

void init_sdl(void)
{
    int wf = 0;
    int rf = SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE;
    int tf = SDL_TEXTUREACCESS_TARGET;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        die("Unable to initialize SDL");
    }

    IMG_Init(IMG_INIT_JPG);

    window = SDL_CreateWindow(
            SCREEN_TITLE,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            wf);
    if (!window)
        die("Could not create window");

    renderer = SDL_CreateRenderer(window, -1, rf);
    if (!renderer)
        die("Could not create renderer");

    texture = SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_ARGB8888,
            tf,
            SCREEN_WIDTH,
            SCREEN_HEIGHT);
    if (!texture)
        die("Could not create texture");

    background = NULL;
}

void close_sdl(void)
{
    if (demo)
        demo->teardown();

    IMG_Quit();
    close_music();

    if (texture)
        SDL_DestroyTexture(texture);

    if (renderer)
        SDL_DestroyRenderer(renderer);

    if (window)
        SDL_DestroyWindow(window);
}

void clear_texture(void)
{
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void set_background(char *image)
{
    SDL_Surface *s;

    if (background)
        SDL_DestroyTexture(background);

    s = IMG_Load(image);
    background = SDL_CreateTextureFromSurface(renderer, s);
    SDL_FreeSurface(s);
}

void show_background(void)
{
    SDL_SetRenderTarget(renderer, texture);
    SDL_RenderCopy(renderer, background, NULL, NULL);
    //SDL_RenderPresent(renderer);
}

void update(void)
{
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}
