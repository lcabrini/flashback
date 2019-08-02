#ifndef BOBS_H
#define BOBS_H

#include <stdlib.h>
#include <math.h>
#include "common.h"

struct bob
{
    int x;
    int y;
    int a;
    struct bob *next;
};

struct bob *build_bob_list(void);
void destroy_bob_list(struct bob *list);
void draw_bobs(void);

#endif /* BOBS_H */
