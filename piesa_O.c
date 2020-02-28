#include <stdio.h>				//CD 311 Veis Onur Șener
#include <stdlib.h>
#include <string.h>
#include "functii.h"
#include "bmp_header.h"

void piesa_O(){
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
    pbmp->bmp_infoheader.height = 40;
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
    FILE *fp = fopen("piesa_O.bmp","wb");
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
    			
    			if((i>=10)&&(i<30)&&(j>=10)&&(j<30)){
    				pbuf[nr].b = 0;
    				pbuf[nr].g = 255;
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
    
    FILE *fp90 = fopen("piesa_O_90.bmp","wb");

    fwrite (pbmp, 1, sizeof(bmp),fp90);
    fwrite(pbuf,1,pbmp->bmp_infoheader.biSizeImage,fp90);
    fclose(fp90);

    FILE *fp180 = fopen("piesa_O_180.bmp","wb");

    fwrite (pbmp, 1, sizeof(bmp),fp180);
    fwrite(pbuf,1,pbmp->bmp_infoheader.biSizeImage,fp180);
    fclose(fp180);

    FILE *fp270 = fopen("piesa_O_270.bmp","wb");

    fwrite (pbmp, 1, sizeof(bmp),fp270);
    fwrite(pbuf,1,pbmp->bmp_infoheader.biSizeImage,fp270);
    fclose(fp270);


    free(pbmp);
    free(pbuf);


}