#include "pintor.h"
#include "bmp.h"

#include <stdio.h>

int main(void)
{
	sdl_config conf;
	BmpMask* bm;
	printf("IMAGE BMP VIEWER. \n"
	"\n"
	"USAGE: %s Write the image name or path in the console |"
	"\n"
	"Enter the Image Name  \n");

	cargar_imagen(scanf("%d", &nombre),bm);

	printf("IMAGE BMP VIEWER. \n"
	"\n"
	"Desea rotar la imagen?"
	"\n"
	"1: Derecha \n"
	"2: Izquierda \n"
	"3: 180 Grados \n"
	"4: SAlir \n"

	if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            system("cls");
            continue;
    }
	else if (opcion == 4)
	{
		exit(bm);
	}
	

	else()
	{
		rotar_imagen(bm,opcion);
	}
	
}

static void exit(BmpMask* bm, sdl_config* conf; ){
    BMP_quit(bm);
    SDL_Quit(conf);
};
