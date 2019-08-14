#ifndef FADE_H
#define FADE_H

#include <SDL2/SDL.h>
#include "common.h"

#define FADE_IN 0
#define FADE_OUT 1
#define FADE_DONE 2

SDL_Texture *fade_texture;

int fade_r;
int fade_g;
int fade_b;
int fade_a;
int fade_dir;

extern SDL_Renderer *renderer;
extern SDL_Texture *texture;

void init_fade(void);
void destroy_fade(void);
void fade(void);

#endif /* FADE_H */
