#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define CENTER_X (SCREEN_WIDTH / 2)
#define CENTER_Y (SCREEN_HEIGHT / 2)

#ifdef DEBUG
#define dprint(...) \
    fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); \
    fprintf(stderr, __VA_ARGS__); \
    fprintf(stderr, "\n");
#else
#define dprint(...)
#endif /* DEBUG */

#endif /* COMMON_H */
