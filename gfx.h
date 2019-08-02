#ifndef GFX_H
#define GFX_H

#include <SDL2/SDL.h>
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

#endif /* GFX_H */
