#include "bobs.h"

struct bob *build_bob_list(void)
{
    struct bob *h;
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

    c->next = h;
    return h;
}

void destroy_bob_list(struct bob *list)
{
}

void draw_bobs(void)
{
}
