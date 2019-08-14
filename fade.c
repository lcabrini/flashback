#include "fade.h"

void init_fade(void)
{
    fade_r = 0;
    fade_g = 0;
    fade_b = 0;
    fade_a = 255;
    fade_dir = FADE_IN;

    fade_texture = SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_ARGB8888,
            SDL_TEXTUREACCESS_TARGET,
            SCREEN_WIDTH,
            SCREEN_HEIGHT);
    SDL_SetTextureBlendMode(fade_texture, SDL_BLENDMODE_BLEND);
}

void destroy_fade(void)
{
    if (fade_texture)
        SDL_DestroyTexture(fade_texture);
}

void fade(void)
{
    if (fade_dir == FADE_DONE)
        return;

    SDL_SetRenderTarget(renderer, fade_texture);
    SDL_SetRenderDrawColor(renderer, fade_r, fade_g, fade_b, fade_a);
    SDL_RenderClear(renderer);
    SDL_SetRenderTarget(renderer, texture);
    SDL_RenderCopy(renderer, fade_texture, NULL, NULL);
    SDL_SetRenderTarget(renderer, NULL);

    if (fade_dir == FADE_IN)
    {
        fade_r += 50;
        fade_g += 50;
        fade_b += 50;

        if (fade_r > 255)
        {
            fade_dir = FADE_OUT;
            fade_r = 255;
            fade_g = 255;
            fade_b = 255;
        }
    }
    else if (fade_dir == FADE_OUT)
    {
        fade_a -= 5;

        if (fade_a < 1)
        {
            fade_dir = FADE_DONE;
        }
    }
}
