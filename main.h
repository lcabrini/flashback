#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <SDL2/SDL.h>

void die(char *message);

extern void init_sdl(void);
extern void close_sdl(void);
extern void init_music(void);
extern void update(void);
extern void prepare_demo(void);
extern void run_demo(void);
extern void destroy_demo(void);

#endif /* MAIN_H */
