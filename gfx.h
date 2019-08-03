#ifndef GFX_H
#define GFX_H

#include <math.h>
#include <SDL2/SDL.h>
#include "bobs.h"
#include "common.h"

#define SCREEN_TITLE "Flashback"

void init_sdl(void);
void close_sdl(void);
void draw(void);
void draw_bobs(struct bob *bobs, int count, int to_size, int rx, int gx, 
        int bx, int angle);
void update(void);

extern void die(char *message);

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

int bob_count;
//struct bob *head_bob;
struct bob_list *bob_lists;
struct bob_list *current_bob_list;
struct bob_list *fading_bob_list;
int angle;
int move_count;
int bob_size;

#endif /* GFX_H */
