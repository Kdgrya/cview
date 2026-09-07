#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int Cargar_imagen(char Fname, BmpMask* bm, bmp* bp )
{
    snprintf(Fname, sizeof(Fname), "%.bpm");
     bp->Fin = fopen(Fname,"rb");
     bp->Fout = fopen(Fname, "w+");

    if (FIn==NULL){
        printf("I Cannot find the File, SRRY");
    }

    Process_Image(bp->Fin, bp->Fout);

}

void Process_Image(FILE *FIn, FILE *FOut, BmpMask* bm,bmp* bp)
{
    for(i = 0;i<54;i++){     // read 54 byte header
        bm->byte[i] = getc(bp->FIn); 
    }
    fwrite(bm->byte, sizeof(unsigned char),54,bp->Fout);

    bm->h = *(int*)&bm->byte[18];
    bm->w = *(int*)&bm->byte[22];
    bm->bitDepth = *(int*)&byte[28];

    printf("width: %d\n",bm->w);
	printf("height: %d\n",bm->h );

    bm->size = bm->h * bm->w;
    bm->buffer = (unsigned char*) malloc (bm->size * sizeof(unsigned char));
    bm->out_buffer = (unsigned char*) malloc (bm->size * sizeof(unsigned char));

    fread(bm->buffer, sizeof(unsigned char), size);

}

void rotate_image(BmpMask* bm, int dr){

    switch (dr)
    {
        case 1:
            left(bm);
            break;
        case 2:
            rigth(bm);
            break;
        case 3:
            mid(bm);
            break;
        default:
            printf("\nOpcion invalida. Intente de nuevo.\n");
            break;
    }
}

void left(BmpMask* bm){
    for (int i=0;i<bm->w;i++){
        for (int j=0;j<bm->h;j++)
        {
            bm->out_buffer[(bm->w - 1 - i) * bm->h + j] = bm->buffer[j * bm->w + i];
        }
    }
}

void rigth(BmpMask* bm){
    for (int i=0;i<bm->w;i++){
        for (int j=0;j<bm->h;j++)
        {
            bm->out_buffer[i * bm->h + (bm->h - 1 - j)] = bm->buffer[j * bm->w + i];
        }
    }
}

void mid(BmpMask* bm){
    for (int i=0;i<bm->w;i++){
        for (int j=0;j<bm->h;j++)
        {
            bm->out_buffer[(bm->h - 1 - j) * bm->w + (bm->w - 1 - i)] = bm->buffer[j * bm->w + i];
        }
    }
}

void BMP_quit(){

}