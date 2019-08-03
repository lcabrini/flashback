#include "bobs.h"
#include <stdio.h>

struct bob *build_bob_list1(void)
{
    struct bob *h = NULL;
    struct bob *c;
    struct bob *p = NULL;
    float r;
    int a;
    int i;
    int x, y;

    a = 0;
    for (i = 0; i <360; i += 3)
    {
        r = i * M_PI / 180.0;
        x = 400 + 400 * sin(2 * r) * cos(3 * r);
        y = SCREEN_HEIGHT - 300 + 300 * cos(r / 2) * sin(r) * sin(r);
        c = malloc(sizeof(struct bob *));
        c->x = x;
        c->y = y;
        c->a = a;
        a += 5;
        if (a > 359) a -= 359;
        if (!h) h = c;
        if (p) p->next = c;
        p = c;
    }

printf("list1: x: %d, y: %d\n", h->x, h->y);
    c->next = h;
    return h;
}

struct bob *build_bob_list2(void)
{
    struct bob *h = NULL;
    struct bob *c;
    struct bob *p = NULL;
    float r;
    int a;
    int i;
    int x, y;

    a = 0;
    for (i = 0; i < 359; i += 3)
    {
        r = i * M_PI / 180.0;
        x = 400 + 350 * sin(r);
        y = SCREEN_HEIGHT - 300 + 250 * cos(r);
        c = malloc(sizeof(struct bob *));
        c->x = x;
        c->y = y;
        c->a = a;
        a += 5;
        if (a > 359) a -= 359;
        if (!h) h = c;
        if (p) p->next = c;
        p = c;
    }

    c->next = h;
    return h;
}

struct bob_list *build_bob_lists(void)
{
    struct bob_list *h;
    struct bob_list *c;
    struct bob_list *p = NULL;
    int i;

    c = malloc(sizeof(struct bob_list *));
    c->head = build_bob_list1();
    h = c;
    c->rx = 10;
    c->gx = 10;
    c->bx = 0;
    c->play_time = 150;
    c->angle = 0;
    p = c;
printf("building: x: %d, y: %d\n", c->head->x, c->head->y);

    c = malloc(sizeof(struct bob_list *));
    c->head = build_bob_list2();
    c->rx = 0;
    c->gx = 0;
    c->bx = 10;
    c->play_time = 90;
    c->angle = 0;
    p->next = c;
    p = c;

    c->next = h;
    return h;
}

void destroy_bob_list(struct bob *list)
{
}

/*
void draw_bobs(void)
{
}
*/
