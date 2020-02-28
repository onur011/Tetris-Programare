#include<stdio.h>               //CD 311 Veis Onur Șener
#include<stdlib.h>
#include"bmp_header.h"
#include"functii.h"

void task4(){
    int nr = 0, i, j, N, l, rotatie, coloana, H, L, bitiextra;
    unsigned char pad;
    char numepiesa[2];
    //se deschide fisierul cerinta4.bmp pentru a se citi din el
    FILE *fp1 = fopen("cerinta4.bmp","rb");
		
    bmp *pbmp  = (bmp*)calloc(1,sizeof(bmp));

    if(pbmp == NULL){
        fprintf(stderr, "Nu s-a alocat memorie\n");
        exit(1);
    }
    //se citesc fileheaderul si infoheaderul fisierului bmp
    fread(pbmp, 1,sizeof(bmp),fp1);
    //se calculeaza paddingul
    bitiextra= (pbmp->bmp_infoheader.biSizeImage / pbmp->bmp_infoheader.height)
    - (pbmp->bmp_infoheader.width * 3);

    if(bitiextra == 4)
    bitiextra = 0;

	Pixel *pbuf = (Pixel*)malloc(pbmp->bmp_infoheader.biSizeImage * 
    sizeof(Pixel));

    if(pbuf == NULL){
        fprintf(stderr, "Nu s-a alocat memorie\n");
        exit(1);
    }
	//se citesc bitii de pixel si sunt introdusi intr-un vector de tip Pixel
	for(i = 0;i < pbmp->bmp_infoheader.height; i++){
		for(j = 0;j< (pbmp->bmp_infoheader.width + bitiextra); j++){
				if(j >= pbmp->bmp_infoheader.width){
					fread(&pad,sizeof(unsigned char),1,fp1);
					nr=nr+1;
					continue;
				}            	
            	fread(&pbuf[nr].b,sizeof(unsigned char),1,fp1);
            	fread(&pbuf[nr].g,sizeof(unsigned char),1,fp1);
            	fread(&pbuf[nr].r,sizeof(unsigned char),1,fp1);
            	nr = nr + 1;
       }
	}

	H = pbmp->bmp_infoheader.height - 40;
	L = pbmp->bmp_infoheader.width;

    int ** imagine=(int **) malloc ((H + 40)*sizeof (int*));
    
    if(imagine == NULL){
      fprintf(stderr, "Nu s-a alocat memorie\n");
      exit(1);
    }
    
    for (i = 0; i < H + 40; i++){
      
        imagine[i] = (int*) calloc (L + bitiextra,sizeof (int));
        if(imagine[i] == NULL){
            fprintf(stderr, "Nu s-a alocat memorie\n");
            exit(1);
        }
    }

	nr = 0;
    //se creaza matricea imagine plecand de la vectorul de pixeli
    for(i = 0;i < pbmp->bmp_infoheader.height; i++){
        for(j = 0;j< (pbmp->bmp_infoheader.width + bitiextra); j++){
            	
            if(j >= pbmp->bmp_infoheader.width){
            	nr = nr + 1;
            	continue;
            }

            if((pbuf[nr].b == 0) && (pbuf[nr].g == 0) && 
            (pbuf[nr].r == 0)){
            	imagine[H + 40 - 1 - i][j] = 1;
            	nr = nr + 1;
            	continue;
            }

        	if((pbuf[nr].b == 255) && (pbuf[nr].g == 255) && 
        	(pbuf[nr].r == 255)){
        		imagine[H + 40 - 1 - i][j] = 0;
          		nr = nr + 1;
           		continue;
           	}
                	
            if((pbuf[nr].b == 255) && (pbuf[nr].g == 0) && 
          	(pbuf[nr].r == 0)){
           		imagine[H + 40 - 1 - i][j] = 2;
           		nr = nr + 1;
           		continue;
           	}

           	if((pbuf[nr].b == 0) && (pbuf[nr].g == 140) && 
           	(pbuf[nr].r == 255)){
           		imagine[H + 40 - 1 - i][j] = 3;
           		nr = nr + 1;
           		continue;
           	}

           	if((pbuf[nr].b == 0) && (pbuf[nr].g == 0) && 
           	(pbuf[nr].r == 255)){
           		imagine[H + 40 - 1 - i][j] = 4;
           		nr = nr + 1;
           		continue;
           	}

           	if((pbuf[nr].b == 255) && (pbuf[nr].g == 0) && 
           	(pbuf[nr].r == 130)){
           		imagine[H + 40 - 1 - i][j] = 5;
           		nr = nr + 1;
           		continue;
           	}

           	if((pbuf[nr].b == 0) && (pbuf[nr].g == 255) && 
           	(pbuf[nr].r == 0)){
           		imagine[H + 40 - 1 - i][j] = 6;
           		nr = nr + 1;
           		continue;
           	}

           	if((pbuf[nr].b == 255) && (pbuf[nr].g == 0) && 
           	(pbuf[nr].r == 255)){
           		imagine[H + 40 - 1 - i][j] = 7;
           		nr = nr + 1;
           		continue;
           	}

           	if((pbuf[nr].b == 0) && (pbuf[nr].g == 255) && 
           	(pbuf[nr].r == 255)){
           		imagine[H + 40 - 1 - i][j] = 8;
           		nr = nr + 1;
           		continue;
           	}
        }
    }

	fclose(fp1);
    //de aici algoritmul este aproape identic cu cel de la taskul 3
	FILE *in = fopen("cerinta4.in", "r");

	fscanf(in, "%d", &N);

	for(l = 0; l < N; l++) {
		fscanf(in, "%s", numepiesa);
		fscanf(in, "%d", &rotatie);
		fscanf(in, "%d", &coloana);

		coloana = coloana*10;

		if(numepiesa[0] == 'I'){
			piesa_I_imagine(imagine, H, L,rotatie, coloana, bitiextra);
		}
		if(numepiesa[0] == 'L'){
			piesa_L_imagine(imagine, H, L, rotatie, coloana, bitiextra);
		}
		if(numepiesa[0] == 'S'){
			piesa_S_imagine(imagine, H, L,rotatie, coloana, bitiextra);
		}
		if(numepiesa[0] == 'T'){
			piesa_T_imagine(imagine, H, L,rotatie, coloana, bitiextra);
		}
		if(numepiesa[0] == 'Z'){
			piesa_Z_imagine(imagine, H, L,rotatie, coloana, bitiextra);
		}
		if(numepiesa[0] == 'J'){
			piesa_J_imagine(imagine, H, L,rotatie, coloana, bitiextra);
		}
		if(numepiesa[0] == 'O'){
			piesa_O_imagine(imagine, H, L,rotatie, coloana, bitiextra);
		}
			
		Eliminare(imagine, H, L);
			
		if( (Verificare(imagine, L)) == 1)
			break;			
	}
		Imagine4(imagine, H, L, bitiextra);

        for (i = 0; i < H + 40; i++)
            free(imagine[i]);
        
        free(imagine);
}
