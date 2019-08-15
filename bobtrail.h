#ifndef BOBTRAIL_H
#define BOBTRAIL_H

#include <stdlib.h>
#include <math.h>
#include "common.h"
#include "demo.h"

#define MAX_BOB_SIZE 50
#define SIZE_STEP 2
#define ROTATION 10
#define TRAIL_LENGTH 25

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
struct path *build_yellow_path(void);
struct path *build_blue_path(void);
struct path *build_magenta_path(void);
struct path *build_green_path(void);
struct path *build_red_path(void);
void destroy_path(struct path *head);
void draw_current_bobtrail(void);
void draw_fading_bobtrail(void);
void draw_bobtrail(struct path *path, int count, int to_size, int rx,
        int gx, int bx, int angle);

extern void clear_texture(void);
extern void set_background(char *image);
extern void show_background(void);
extern void init_fade(void);
extern void destroy_fade(void);
extern void fade(void);
extern void play_music(char *track);

struct bobtrail *current_bobtrail;
struct bobtrail *fading_bobtrail;

extern SDL_Renderer *renderer;
extern SDL_Texture *texture;

#endif /* BOBTRAIL_H */
