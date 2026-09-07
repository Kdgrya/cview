#pragma once
#include <stdint.h>
#include <SDL.h>
#include <SDL/SDL_image.h>
#include "bmp.h"


static char String_Program_Title[256];

typedef struct
{
	SDL_Window* ventana;
	SDL_Renderer* render;
} sdl_config;

void iniciar();
void DRAW_VIEW(void);
void SET_DIM_VIEW();
void SET_FLIP_VIEW();

void SDL_Quit(sdl_config *config);
