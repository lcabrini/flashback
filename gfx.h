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
void update(void);

extern void die(char *message);

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

int bob_count;
struct bob *head_bob;
int angle;
int move_count;
int bob_size;

#endif /* GFX_H */
