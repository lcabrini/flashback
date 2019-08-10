#include "music.h"

void init_music(void)
{
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
        die("Could not initialize mixer");
}

void close_music(void)
{
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}

void play_music(char *track)
{
    music = Mix_LoadMUS(track);
    Mix_PlayMusic(music, -1);
}
