#ifndef GFX_H
#define GFX_H

#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "common.h"
#include "demo.h"

#define SCREEN_TITLE "Flashback"

void init_sdl(void);
void close_sdl(void);
void clear_texture(void);
void set_background(char *image);
void show_background(void);

extern void die(char *message);

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;
SDL_Texture *background;

#endif /* GFX_H */
