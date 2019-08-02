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

    bob_count = 1;
    head_bob = build_bob_list();
    angle = 0;
    bob_size = 50;
    move_count = 0;
}

void close_sdl(void)
{
    if (texture)
        SDL_DestroyTexture(texture);

    if (renderer)
        SDL_DestroyRenderer(renderer);

    if (window)
        SDL_DestroyWindow(window);
}

void draw(void)
{
    struct bob *c;
    int i;
    int x, y;
    int a;
    float r;
    int w;
    //SDL_Rect sr, dr;
    //SDL_Texture *t;

    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    /* TEMP */

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    c = head_bob;
    a = 0;
    w = 0;
    /*
    for (i = 0; i < bob_count; ++i)
    {
        r = 3.14159 * i / 180;
        x = (int)(400 + 
                400 * sin(r * 2) * cos(r * 3));
        y = (int)(SCREEN_HEIGHT - 300 + 
                300 * cos(r / 2) * sin(r) * sin(r));
        //s.x = x;
        //s.y = y;
        //s.w = 30;
        //s.h = 30;
        
        SDL_SetRenderTarget(renderer, t);
        if (i % 3 == 0)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        else if (i % 2 == 0)
            SDL_SetRenderDrawColor(renderer, 60, 60, 255, 255);
        else 
            SDL_SetRenderDrawColor(renderer, 180, 180, 255, 255);
        SDL_SetRenderDrawColor(renderer, i*10, i*10, 0, 255);
        SDL_RenderClear(renderer);
        

        SDL_SetRenderTarget(renderer, texture);
        sr.x = 0;
        sr.y = 0;
        sr.w = w;
        sr.h = w;

        dr.x = c->x;
        dr.y = c->y;
        dr.w = w;
        dr.h = w;

        SDL_RenderCopyEx(
                renderer,
                t,
                &sr,
                &dr,
                angle,
                NULL,
                0);
        //rot += 2;
        //SDL_RenderDrawPoint(renderer, x, y);
        c = c->next;
        if (w < bob_size) ++w;
    }
    */
    /* END TEMP */

    draw_bobs(head_bob, bob_count, bob_size, 10, 10, 0, angle);

    head_bob = head_bob->next;
    if (bob_count < 25) ++bob_count;
    angle += 10;
    if (angle > 359)
        angle = angle - 359;
    ++move_count;
    if (move_count > 150)
       --bob_size;
}

void draw_bobs(struct bob *bobs, int count, int to_size, int rx, int gx, 
        int bx, int angle)
{
    SDL_Texture *t;
    SDL_Rect sr, dr;
    int w;
    int i;

    t = SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_ARGB8888,
            SDL_TEXTUREACCESS_TARGET,
            50,
            50);
    w = 0;

    for (i = 0; i < count; ++i)
    {
        SDL_SetRenderTarget(renderer, t);
        SDL_SetRenderDrawColor(renderer, i * rx, i * gx, i * bx, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderTarget(renderer, texture);

        sr.x = 0;
        sr.y = 0;
        sr.w = w;
        sr.h = w;

        dr.x = bobs->x;
        dr.y = bobs->y;
        dr.w = w;
        dr.h = w;

        SDL_RenderCopyEx(renderer, t, &sr, &dr, angle, NULL, 0);
        bobs = bobs->next;
        if (w < to_size) ++w;
    }

    SDL_DestroyTexture(t);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_SetRenderTarget(renderer, NULL);
}

void update(void)
{
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}
