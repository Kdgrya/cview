#pragma once 

#include <stdint.h>

typedef struct BmpMask {
    uint32_t w;
    uint32_t h;
    char byte[54];
    unsigned char* Color_table;
    unsigned char* buffer;
    unsigned char* out_buffer;
    int size;
    int bitDepth;
}BmpMask;

typedef struct bmp
{
    FILE* Fin;
    FILE* Fout;
}bmp;

int i;
int opcion;

int cargar_imagen(const char* Fname, BmpMask* bm);
void rotar_imagen(BmpMask* bm, int dr);
void BMP_quit(BmpMask* bm);

