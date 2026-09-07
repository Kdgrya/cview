#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pintor.h"


void iniciar(sdl_config *config)
{
	SDL_Init(SDL_INIT_VIDEO);
	config->ventana = SDL_CreateWindow("Mi Imagen",
					    SDL_WINDOWPOS_CENTERED,
					    SDL_WINDOWPOS_CENTERED,
					    640, 480, 0);

	config->render = SDL_CreateRenderer(config->ventana, -1, 0);
	pintar()

}


void pintar(BmpMask* bm, sdl_config *config)
{
	SDL_Rect texr; texr.x = WIDTH/2; texr.y = HEIGHT/2; texr.w = w*2; texr.h = h*2; 
	while (1)
	{
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				break;
			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
				break;						
		}
		
	}

	SDL_RenderClear(config->render);
	SDL_RenderCopy(config->render,bm->out_buffer,NULL,&texr);
	SDL_RenderPresent(config->render);
	SDL_Delay(6000);
}


void SDL_Quit(sdl_config *config) {
	free(config);
}


