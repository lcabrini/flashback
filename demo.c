#include "demo.h"

void prepare_demo(void)
{
    struct scene *c, *p;

    demo = add_bobtrail_scene();
    demo->next_scene = NULL;
}

void destroy_demo(void)
{
    struct scene *c, *p;

    c = demo;
    while (c)
    {
       p = c;
       c = c->next_scene;
       free(p);
    }
}

void run_demo(void)
{
    current_scene = demo;
    while (current_scene)
    {
       current_scene->prepare();
       current_scene->scene_flags |= SCENE_RUNNING;
       while (current_scene->scene_flags & SCENE_RUNNING)
       {
           current_scene->perform();
           update();
           SDL_Delay(50);   /* TODO: replace this */
       }

       current_scene->teardown();
       current_scene = current_scene->next_scene;
    }
}
