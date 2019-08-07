#include "bobtrail.h"
#include <stdio.h>

struct scene *create_bobtrail_scene()
{
    struct scene *s;

    s = malloc(sizeof(struct scene *));
    s->prepare = &prepare_bobtrail_scene;
    s->perform = &perform_bobtrail_scene;
    s->teardown = &teardown_bobtrail_scene;
    return s;
}

void prepare_bobtrail_scene(void)
{
    struct bobtrail *c, *p;
    int i;

    c = malloc(sizeof(struct bobtrail *));
    c->head = build_path1();
    current_bobtrail = c;
    c->rx = 10;
    c->gx = 10;
    c->bx = 0;
    c->play_time = 150;
    c->angle = 0;
    p = c;

    c = malloc(sizeof(struct bobtrail *));
    c->head = build_path2();
    c->rx = 0;
    c->gx = 0;
    c->bx = 10;
    c->play_time = 90;
    c->angle = 0;
    p->next = c;
    p = c;

    c = malloc(sizeof(struct bobtrail *));
    c->head = build_path3();
    c->rx = 10;
    c->gx = 0;
    c->bx = 10;
    c->play_time = 250;
    c->angle = 0;
    p->next = c;
    p = c;

    c = malloc(sizeof(struct bobtrail *));
    c->head = build_path4();
    c->rx = 0;
    c->gx = 10;
    c->bx = 0;
    c->play_time = 150;
    p->next = c;
    p = c;

    c->next = h;
}

void perform_bobtrail_scene(void)
{

    /* TODO */
}

void teardown_bobtrail_scene(void)
{
    /* TODO */
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
        y = SCREEN_HEIGHT - CENTER_Y + CENTER_Y * cos(r / 2) * 
            sin(r) * sin(r);
        c = malloc(sizeof(struct path *));
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
        y = SCREEN_HEIGHT - CENTER_Y + (CENTER_Y - 50) * cos(r);
        c = malloc(sizeof(struct path *));
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
        y = SCREEN_HEIGHT - CENTER_Y + CENTER_Y * cos(r * 2) * cos(r);
        c = malloc(sizeof(struct path *));
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
        y = SCREEN_HEIGHT - CENTER_Y + CENTER_Y * sin(r*2) * cos(r);
        c = malloc(sizeof(struct path *));
        c->x = x;
        c->y = y;
        if (!h) h = c;
        if (p) p->next = c;
        p = c;
    }

    c->next = h;
    return h;
}
