#ifndef DEMO_H
#define DEMO_H

#include <stdlib.h>
#include <SDL2/SDL.h>

#define SCENE_RUNNING 1

struct scene 
{
    void (*prepare)(void);
    void (*perform)(void);
    void (*teardown)(void);
    unsigned char scene_flags;
    struct scene *next_scene;
};

void prepare_demo(void);
void destroy_demo(void);
void run_demo(void);

extern struct scene *add_bobtrail_scene(void);
extern void update(void);

struct scene *demo;
struct scene *current_scene;

#endif /* DEMO_H */
