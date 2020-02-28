#include<stdio.h>                           //CD 311 Veis Onur Șener
#include<stdlib.h>
#include"bmp_header.h"

void Imagine(int **imagine, int H, int L, int bitiextra){
	int i, j, nr = 0;
	//algoritmul de creare a fisierului de tip bmp este asemanator
    //cu cel din functia piesa_T(), doar ca in acest caz se introduc
    //bitii de pixel in functie de valorile imaginii
    bmp *pbmp  = (bmp*)calloc(1,sizeof(bmp));
    if(pbmp == NULL){
        fprintf(stderr, "Nu s-a alocat memorie\n");
        exit(1);
    }
    pbmp->bmp_fileheader.fileMarker1 = 'B';
    pbmp->bmp_fileheader.fileMarker2 = 'M';
    pbmp->bmp_fileheader.unused1 = 0;
    pbmp->bmp_fileheader.unused2 = 0;
    pbmp->bmp_fileheader.imageDataOffset = sizeof(bmp);
    pbmp->bmp_infoheader.biSize =sizeof(bmp_infoheader);
    pbmp->bmp_infoheader.width = L;
    pbmp->bmp_infoheader.height = H + 40;
    pbmp->bmp_infoheader.planes = 1;
    pbmp->bmp_infoheader.bitPix = 24;
    pbmp->bmp_infoheader.biCompression = 0;
    pbmp->bmp_infoheader.biSizeImage = ((pbmp->bmp_infoheader.width * 3) + 
        bitiextra) *pbmp->bmp_infoheader.height;
    pbmp->bmp_infoheader.biXPelsPerMeter = 0;
    pbmp->bmp_infoheader.biYPelsPerMeter = 0;
    pbmp->bmp_infoheader.biClrUsed = 0;
    pbmp->bmp_infoheader.biClrImportant = 0;
    pbmp->bmp_fileheader.bfSize = pbmp->bmp_infoheader.biSizeImage +
    sizeof(bmp);
    
    FILE *fp = fopen("task3.bmp","wb");
    

    Pixel *pbuf = (Pixel*)malloc(pbmp->bmp_infoheader.biSizeImage * 
    sizeof(Pixel));

    if(pbuf == NULL){
        fprintf(stderr, "Nu s-a alocat memorie\n");
        exit(1);
    }

    fwrite (pbmp, 1, sizeof(bmp),fp);
    nr=0;
        for(i=0;i<pbmp->bmp_infoheader.height;i++){
            for(j=0;j<pbmp->bmp_infoheader.width+bitiextra;j++){
                if(j>=L){
                    fputc(0x00,fp);
                    nr=nr+1;
                    continue;
                }
               
                
                if(imagine[H+40-1-i][j]==1){    //negru
                	pbuf[nr].b = 0;
                	pbuf[nr].g = 0;
                	pbuf[nr].r = 0;
                	fputc(pbuf[nr].b,fp);
                	fputc(pbuf[nr].g,fp);
                	fputc(pbuf[nr].r,fp);
                	nr=nr+1;
                }

                if(imagine[H+40-1-i][j]==0){    //alb
                	pbuf[nr].b = 255;
                	pbuf[nr].g = 255;
                	pbuf[nr].r = 255;
                	fputc(pbuf[nr].b,fp);
                	fputc(pbuf[nr].g,fp);
                	fputc(pbuf[nr].r,fp);
                	nr=nr+1;
                }
                if(imagine[H+40-1-i][j]==2){    //albastru
                	pbuf[nr].b = 255;
                	pbuf[nr].g = 0;
                	pbuf[nr].r = 0;
                	fputc(pbuf[nr].b,fp);
                	fputc(pbuf[nr].g,fp);
                	fputc(pbuf[nr].r,fp);
                	nr=nr+1;
                }
                if(imagine[H+40-1-i][j]==3){    //portocaliu
                	pbuf[nr].b = 0;
                	pbuf[nr].g = 140;
                	pbuf[nr].r = 255;
                	fputc(pbuf[nr].b,fp);
                	fputc(pbuf[nr].g,fp);
                	fputc(pbuf[nr].r,fp);
                	nr=nr+1;
                }
                if(imagine[H+40-1-i][j]==4){    //rosu
                	pbuf[nr].b = 0;
                	pbuf[nr].g = 0;
                	pbuf[nr].r = 255;
                	fputc(pbuf[nr].b,fp);
                	fputc(pbuf[nr].g,fp);
                	fputc(pbuf[nr].r,fp);
                	nr=nr+1;
                }
                if(imagine[H+40-1-i][j]==5){    //mov
                	pbuf[nr].b = 255;
                	pbuf[nr].g = 0;
                	pbuf[nr].r = 130;
                	fputc(pbuf[nr].b,fp);
                	fputc(pbuf[nr].g,fp);
                	fputc(pbuf[nr].r,fp);
                	nr=nr+1;
                }
                if(imagine[H+40-1-i][j]==6){    //verde
                	pbuf[nr].b = 0;
                	pbuf[nr].g = 255;
                	pbuf[nr].r = 0;
                	fputc(pbuf[nr].b,fp);
                	fputc(pbuf[nr].g,fp);
                	fputc(pbuf[nr].r,fp);
                	nr=nr+1;
                }
                if(imagine[H+40-1-i][j]==7){    //roz
                	pbuf[nr].b = 255;
                	pbuf[nr].g = 0;
                	pbuf[nr].r = 255;
                	fputc(pbuf[nr].b,fp);
                	fputc(pbuf[nr].g,fp);
                	fputc(pbuf[nr].r,fp);
                	nr=nr+1;
                }
                if(imagine[H+40-1-i][j]==8){    //galben
                	pbuf[nr].b = 0;
                	pbuf[nr].g = 255;
                	pbuf[nr].r = 255;
                	fputc(pbuf[nr].b,fp);
                	fputc(pbuf[nr].g,fp);
                	fputc(pbuf[nr].r,fp);
                	nr=nr+1;
                }
            }
        }
    fclose(fp);
    free(pbmp);
    free(pbuf);
}
