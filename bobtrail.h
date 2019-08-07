#ifndef BOBTRAIL_H
#define BOBTRAIL_H

#include <stdlib.h>
#include <math.h>
#include "common.h"
#include "demo.h"

struct path
{
    int x;
    int y;
    int a;
    struct path *next;
};

struct bobtrail
{
    struct path *head;
    int rx;
    int gx;
    int bx;
    int play_time;
    int frame;
    int angle;
    int size;
    int count;
    struct bobtrail *next;
};

struct scene *create_bobtrail_scene(void);
void prepare_bobtrail_scene(void);
void perform_bobtrail_scene(void);
void teardown_bobtrail_scene(void);
struct path *build_path1(void);
struct path *build_path2(void);
struct path *build_path3(void);
struct path *build_path4(void);
void destroy_bobtrails(void);

struct bobtrail *current_bobtrail;

#endif /* BOBS_H */
