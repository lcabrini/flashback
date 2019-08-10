#include "bobtrail.h"
#include <stdio.h>

struct scene *create_bobtrail_scene()
{
    struct scene *s;

    s = calloc(1, sizeof(struct scene));
    s->prepare = &prepare_bobtrail_scene;
    s->perform = &perform_bobtrail_scene;
    s->teardown = &teardown_bobtrail_scene;
    return s;
}

void prepare_bobtrail_scene(void)
{
    struct bobtrail *c, *p;
    int i;

    fading_bobtrail = NULL;

    c = calloc(1, sizeof(struct bobtrail));
    c->head = build_path1();
    current_bobtrail = c;
    c->rx = 10;
    c->gx = 10;
    c->bx = 0;
    c->play_time = 150;
    c->angle = 0;
    p = c;

    c = calloc(1, sizeof(struct bobtrail));
    c->head = build_path2();
    c->rx = 0;
    c->gx = 0;
    c->bx = 10;
    c->play_time = 90;
    c->angle = 0;
    p->next = c;
    p = c;

    c = calloc(1, sizeof(struct bobtrail));
    c->head = build_path3();
    c->rx = 10;
    c->gx = 0;
    c->bx = 10;
    c->play_time = 250;
    c->angle = 0;
    p->next = c;
    p = c;

    c = calloc(1, sizeof(struct bobtrail));
    c->head = build_path4();
    c->rx = 0;
    c->gx = 10;
    c->bx = 0;
    c->play_time = 150;
    p->next = c;
    p = c;

    c->next = current_bobtrail;

    set_background("bobtrail-bg.jpg");
    play_music("bobtrail-music.mp3");
}

void perform_bobtrail_scene(void)
{
    clear_texture();
    show_background();
    if (fading_bobtrail)
        draw_fading_bobtrail();
    draw_current_bobtrail();
}

void teardown_bobtrail_scene(void)
{
    struct bobtrail *c, *p;

    dprint("Tearing down bobtrail scene");
    c = current_bobtrail;
    while (c)
    {
        destroy_path(c->head);
        p = c;
        c = c->next;
        p->next = NULL;
        free(p);
    }

    dprint("Done tearing down bobtrail scene");
}

void destroy_path(struct path *head)
{
    struct path *c, *p;

    dprint("Destroying path");
    c = head;
    while (c)
    {
        p = c;
        if (c) c = c->next;
        if (p)
        {
            dprint("destroy path: (%d, %d)\n", p->x, p->y);
            p->next = NULL;
            free(p);
        }
    }

    dprint("Done destroying path");
}

struct path *build_path1(void)
{
    struct path *h, *c, *p;
    int a;
    float r;
    int x, y;

    h = p = NULL;
    for (a = 0; a < 360; a += 3)
    {
        r = a * M_PI / 180.0;
        x = CENTER_X + CENTER_X * sin(2 * r) * cos(3 * r);
        y = SCREEN_HEIGHT - (CENTER_Y + CENTER_Y * cos(r / 2) * sin(r) 
                * sin(r));
        c = calloc(1, sizeof(struct path));
        c->x = x;
        c->y = y;
        if (!h) h = c;
        if (p) p->next = c;
        p = c;
    }

    c->next = h;
    return h;
}

struct path *build_path2(void)
{
    struct path *h, *c, *p;
    int a;
    float r;
    int x, y;

    h = p = NULL;
    for (a = 0; a < 360; a += 3)
    {
        r = a * M_PI / 180.0;
        x = CENTER_X + (CENTER_X - 50) * sin(r);
        y = SCREEN_HEIGHT - (CENTER_Y + (CENTER_Y - 50) * cos(r));
        c = calloc(1, sizeof(struct path));
        c->x = x;
        c->y = y;
        if (!h) h = c;
        if (p) p->next = c;
        p = c;
    }

    c->next = h;
    return h;
}

struct path *build_path3(void)
{
    struct path *h, *c, *p;
    int a;
    float r;
    int x, y;

    h = p = NULL;
    for (a = 0; a < 360; a += 3)
    {
        r = a * M_PI / 180.0;
        x = CENTER_X + CENTER_X * sin(r / 2) * sin(r);
        y = SCREEN_HEIGHT - (CENTER_Y + CENTER_Y * cos(r * 2) * cos(r));
        c = calloc(1, sizeof(struct path));
        c->x = x;
        c->y = y;
        if (!h) h = c;
        if (p) p->next = c;
        p = c;
    }

    c->next = h;
    return h;
}

struct path *build_path4(void)
{
    struct path *h, *c, *p;
    int a;
    float r;
    int x, y;

    h = p = NULL;
    for (a = 0; a < 360; a += 3)
    {
        r = a * M_PI / 180.0;
        x = CENTER_X + CENTER_X * sin(r) * sin(r) * cos(r / 3);
        y = SCREEN_HEIGHT - (CENTER_Y + CENTER_Y * sin(r*2) * cos(r));
        c = calloc(1, sizeof(struct path));
        c->x = x;
        c->y = y;
        if (!h) h = c;
        if (p) p->next = c;
        p = c;
    }

    c->next = h;
    return h;
}

void draw_current_bobtrail(void)
{
    draw_bobtrail(
            current_bobtrail->head,
            current_bobtrail->count,
            current_bobtrail->size,
            current_bobtrail->rx,
            current_bobtrail->gx,
            current_bobtrail->bx,
            current_bobtrail->angle);
    current_bobtrail->head = current_bobtrail->head->next;
    if (current_bobtrail->count < TRAIL_LENGTH)
        current_bobtrail->count += 1;
    current_bobtrail->angle += ROTATION;
    if (current_bobtrail->angle > 359)
        current_bobtrail->angle -= 359;
    current_bobtrail->frame += 1;

    if (current_bobtrail->frame > current_bobtrail->play_time)
    {
        fading_bobtrail = current_bobtrail;
        current_bobtrail = current_bobtrail->next;
        current_bobtrail->size = MAX_BOB_SIZE;
        current_bobtrail->count = 1;
        current_bobtrail->frame = 0;
    }
}

void draw_fading_bobtrail(void)
{
    draw_bobtrail(
            fading_bobtrail->head,
            fading_bobtrail->count,
            fading_bobtrail->size,
            fading_bobtrail->rx,
            fading_bobtrail->gx,
            fading_bobtrail->bx,
            fading_bobtrail->angle);
    fading_bobtrail->head = fading_bobtrail->head->next;
    fading_bobtrail->size -= SIZE_STEP;
    fading_bobtrail->angle += ROTATION;
    if (fading_bobtrail->angle > 359)
        fading_bobtrail->angle -= 359;
    if (fading_bobtrail->size < 1)
        fading_bobtrail = NULL;
}

void draw_bobtrail(struct path *path, int count, int to_size, int rx, 
        int gx, int bx, int angle)
{
    SDL_Texture *t;
    SDL_Rect sr, dr;
    int s;
    int i;

    t = SDL_CreateTexture(
            renderer, 
            SDL_PIXELFORMAT_ARGB8888,
            SDL_TEXTUREACCESS_TARGET,
            MAX_BOB_SIZE,
            MAX_BOB_SIZE);
    s = 1;

    for (i = 0; i < count; ++i)
    {
        SDL_SetRenderTarget(renderer, t);
        SDL_SetRenderDrawColor(renderer, i * rx, i * gx, i * bx, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderTarget(renderer, texture);

        sr.x = 0;
        sr.y = 0;
        sr.w = s;
        sr.h = s;

        dr.x = path->x;
        dr.y = path->y;
        dr.w = s;
        dr.h = s;

        SDL_RenderCopyEx(renderer, t, &sr, &dr, angle, NULL, 0);
        if (s < to_size) ++s;
        path = path->next;
    }

    SDL_DestroyTexture(t);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_SetRenderTarget(renderer, NULL);
}
