#include <stdio.h>          //CD 311 Veis Onur Șener
#include <stdlib.h>
#include <string.h>
#include "bmp_header.h"
#include "functii.h"

void piesa_J(){
      int i,nr,j; 
    
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
    pbmp->bmp_infoheader.width = 40;
    pbmp->bmp_infoheader.height = 50;
    pbmp->bmp_infoheader.planes = 1;
    pbmp->bmp_infoheader.bitPix = 24;
    pbmp->bmp_infoheader.biCompression = 0;
    pbmp->bmp_infoheader.biSizeImage = pbmp->bmp_infoheader.width * 
        pbmp->bmp_infoheader.height * 3;
    pbmp->bmp_infoheader.biXPelsPerMeter = 0;
    pbmp->bmp_infoheader.biYPelsPerMeter = 0;
    pbmp->bmp_infoheader.biClrUsed = 0;
    pbmp->bmp_infoheader.biClrImportant = 0;
    pbmp->bmp_fileheader.bfSize = pbmp->bmp_infoheader.biSizeImage +
    sizeof(bmp);
    FILE *fp = fopen("piesa_J.bmp","wb");
    Pixel *pbuf = (Pixel*)malloc(pbmp->bmp_infoheader.biSizeImage * 
        sizeof(Pixel));
    if(pbuf == NULL){
        fprintf(stderr, "Nu s-a alocat memorie\n");
        exit(1);
    }
    fwrite (pbmp, 1, sizeof(bmp),fp);
        nr=0;
        for(i=0;i<pbmp->bmp_infoheader.height;i++){
            for(j=0;j<pbmp->bmp_infoheader.width;j++){
                
                if((i>=10)&&(i<20)&&(j>=10)&&(j<30)){
                    pbuf[nr].b = 255;
                    pbuf[nr].g = 0;
                    pbuf[nr].r = 255;
                    fputc(pbuf[nr].b,fp);
                    fputc(pbuf[nr].g,fp);
                    fputc(pbuf[nr].r,fp);
                    nr=nr+1;
                    continue;
                }

                if((i>=20)&&(i<40)&&(j>=20)&&(j<30)){
                    pbuf[nr].b = 255;
                    pbuf[nr].g = 0;
                    pbuf[nr].r = 255;
                    fputc(pbuf[nr].b,fp);
                    fputc(pbuf[nr].g,fp);
                    fputc(pbuf[nr].r,fp);
                    nr=nr+1;

                    continue;
                }
                
                pbuf[nr].b = 255;
                pbuf[nr].g = 255;
                pbuf[nr].r = 255;
                fputc(pbuf[nr].b,fp);
                fputc(pbuf[nr].g,fp);
                fputc(pbuf[nr].r,fp);
                nr=nr+1;            
            }
        }
     

    fclose(fp);
    
 FILE *fp180 = fopen("piesa_J_180.bmp","wb");
    fwrite (pbmp, 1, sizeof(bmp),fp180);
    nr=0;
        for(i=0;i<pbmp->bmp_infoheader.height;i++){
            for(j=0;j<pbmp->bmp_infoheader.width;j++){
                
                if((i>=10)&&(i<30)&&(j>=10)&&(j<20)){
                    pbuf[nr].b = 255;
                    pbuf[nr].g = 0;
                    pbuf[nr].r = 255;
                    fputc(pbuf[nr].b,fp180);
                    fputc(pbuf[nr].g,fp180);
                    fputc(pbuf[nr].r,fp180);
                    nr=nr+1;
                    continue;
                }

                if((i>=30)&&(i<40)&&(j>=10)&&(j<30)){
                    pbuf[nr].b = 255;
                    pbuf[nr].g = 0;
                    pbuf[nr].r = 255;
                    fputc(pbuf[nr].b,fp180);
                    fputc(pbuf[nr].g,fp180);
                    fputc(pbuf[nr].r,fp180);
                    nr=nr+1;

                    continue;
                }

                
                pbuf[nr].b = 255;
                pbuf[nr].g = 255;
                pbuf[nr].r = 255;
                fputc(pbuf[nr].b,fp180);
                fputc(pbuf[nr].g,fp180);
                fputc(pbuf[nr].r,fp180);
                nr=nr+1;            
            }
        }

    fclose(fp180);
    free(pbmp);
    free(pbuf);



    bmp *pbmp90  = (bmp*)calloc(1,sizeof(bmp));
    if(pbmp90 == NULL){
        fprintf(stderr, "Nu s-a alocat memorie\n");
        exit(1);
    }
    pbmp90->bmp_fileheader.fileMarker1 = 'B';
    pbmp90->bmp_fileheader.fileMarker2 = 'M';
    pbmp90->bmp_fileheader.unused1 = 0;
    pbmp90->bmp_fileheader.unused2 = 0;
    pbmp90->bmp_fileheader.imageDataOffset = sizeof(bmp);
    pbmp90->bmp_infoheader.biSize =sizeof(bmp_infoheader);
    pbmp90->bmp_infoheader.width = 50;
    pbmp90->bmp_infoheader.height = 40;
    pbmp90->bmp_infoheader.planes = 1;
    pbmp90->bmp_infoheader.bitPix = 24;
    pbmp90->bmp_infoheader.biCompression = 0;
    pbmp90->bmp_infoheader.biSizeImage = ((pbmp90->bmp_infoheader.width * 3) +
        2) *pbmp90->bmp_infoheader.height;
    pbmp90->bmp_infoheader.biXPelsPerMeter = 0;
    pbmp90->bmp_infoheader.biYPelsPerMeter = 0;
    pbmp90->bmp_infoheader.biClrUsed = 0;
    pbmp90->bmp_infoheader.biClrImportant = 0;
    pbmp90->bmp_fileheader.bfSize = pbmp90->bmp_infoheader.biSizeImage +
    sizeof(bmp);
    FILE *fp90 = fopen("piesa_J_90.bmp","wb");
    Pixel *pbuf90 = (Pixel*)malloc(pbmp90->bmp_infoheader.biSizeImage * 
        sizeof(Pixel));
    if(pbuf90 == NULL){
        fprintf(stderr, "Nu s-a alocat memorie\n");
        exit(1);
    }
    nr=0;
    fwrite (pbmp90, 1, sizeof(bmp),fp90);
    for(i=0;i<pbmp90->bmp_infoheader.height;i++){
            for(j=0;j<pbmp90->bmp_infoheader.width+2;j++){
                
                if((i>=10)&&(i<30)&&(j>=10)&&(j<20)){
                    pbuf90[nr].b = 255;
                    pbuf90[nr].g = 0;
                    pbuf90[nr].r = 255;
                    fputc(pbuf90[nr].b,fp90);
                    fputc(pbuf90[nr].g,fp90);
                    fputc(pbuf90[nr].r,fp90);
                    nr=nr+1;
                    continue;
                }

                if((i>=10)&&(i<20)&&(j>=20)&&(j<40)){
                    pbuf90[nr].b = 255;
                    pbuf90[nr].g = 0;
                    pbuf90[nr].r = 255;
                    fputc(pbuf90[nr].b,fp90);
                    fputc(pbuf90[nr].g,fp90);
                    fputc(pbuf90[nr].r,fp90);
                    nr=nr+1;
                    continue;
                }

                if(j>=50){
                    fputc(0x00,fp90);
                    nr=nr+1;
                    continue;
                }

                pbuf90[nr].b = 255;
                pbuf90[nr].g = 255;
                pbuf90[nr].r = 255;
                fputc(pbuf90[nr].b,fp90);
                fputc(pbuf90[nr].g,fp90);
                fputc(pbuf90[nr].r,fp90);
                nr=nr+1;    
            }
        }
    fclose(fp90);
    
    FILE *fp270 = fopen("piesa_J_270.bmp","wb");
    fwrite (pbmp90, 1, sizeof(bmp),fp270);
    nr=0;
    for(i=0;i<pbmp90->bmp_infoheader.height;i++){
            for(j=0;j<pbmp90->bmp_infoheader.width+2;j++){
                
                if((i>=20)&&(i<30)&&(j>=10)&&(j<30)){
                    pbuf90[nr].b = 255;
                    pbuf90[nr].g = 0;
                    pbuf90[nr].r = 255;
                    fputc(pbuf90[nr].b,fp270);
                    fputc(pbuf90[nr].g,fp270);
                    fputc(pbuf90[nr].r,fp270);
                    nr=nr+1;
                    continue;
                }

                if((i>=10)&&(i<30)&&(j>=30)&&(j<40)){
                    pbuf90[nr].b = 255;
                    pbuf90[nr].g = 0;
                    pbuf90[nr].r = 255;
                    fputc(pbuf90[nr].b,fp270);
                    fputc(pbuf90[nr].g,fp270);
                    fputc(pbuf90[nr].r,fp270);
                    nr=nr+1;
                    continue;
                }

                if(j>=50){
                    fputc(0x00,fp270);
                    nr=nr+1;
                    continue;
                }

                pbuf90[nr].b = 255;
                pbuf90[nr].g = 255;
                pbuf90[nr].r = 255;
                fputc(pbuf90[nr].b,fp270);
                fputc(pbuf90[nr].g,fp270);
                fputc(pbuf90[nr].r,fp270);
                nr=nr+1;    
            }
        }
    fclose(fp270);
    free(pbmp90);
    free(pbuf90);

}