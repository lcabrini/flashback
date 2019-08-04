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

struct bob_list
{
    struct bob *head;
    int rx;
    int gx;
    int bx;
    int play_time;
    int frame;
    int angle;
    int size;
    int count;
    struct bob_list *next;
};

struct bob *build_bob_list1(void);
struct bob *build_bob_list2(void);
struct bob *build_bob_list3(void);
struct bob *build_bob_list4(void);
struct bob_list *build_bob_lists(void);
void destroy_bob_list(struct bob *list);
//void draw_bobs(void);

#endif /* BOBS_H */
