PROG := $(shell basename $(shell pwd))
CC = gcc
SDL_CFLAGS = `sdl2-config --cflags`
SDL_MIXER_CFLAGS = `pkg-config SDL2_mixer --cflags`
CFLAGS = $(SDL_CFLAGS) $(SDL_MIXER_CFLAGS)
SDL_LDFLAGS = `sdl2-config --libs` -lm
SDL_MIXER_LDFLAGS = `pkg-config SDL2_mixer --libs`
LDFLAGS = $(SDL_LDFLAGS) $(SDL_MIXER_LDFLAGS)
SRC := $(wildcard *.c)
DEPS:= common.h
OBJ := $(SRC:.c=.o)

all: $(OBJ)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJ)

.PHONY: debug
debug: CFLAGS += -DDEBUG
debug: all

%.o: %.c %.h $(DEPS) 
	$(CC) -c $(CFLAGS) -o $@ $<
clean:
	$(RM) $(OBJ) $(PROG)
