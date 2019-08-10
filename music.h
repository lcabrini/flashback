#ifndef MUSIC_H
#define MUSIC_H

#include <SDL2/SDL_mixer.h>

void init_music(void);
void close_music(void);
void play_track(char *track);

Mix_Music *music;
#endif /* MUSIC_H */
