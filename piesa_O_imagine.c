#include<stdio.h>				//CD 311 Veis Onur Șener
#include<stdlib.h>

void piesa_O_imagine(int **imagine, int H, int L, int rotatie, int coloana, 
int bitiextra){
	int i, j, c = 0;
 
	if((rotatie == 0) || (rotatie == 90) || (rotatie == 180) ||
	(rotatie == 270)){
		for(i = 0; i < H + 40 ; i++){
			for(j = coloana; j< (L + bitiextra); j++){
				if((imagine[H + 40 - 1 - i][j] != 0) && 
				(imagine[H + 40 - 1 - i][j] != 1) && 
				(j >= coloana) && (j < coloana + 20)){
					c = H + 40 - i;
					c=c/10*10;
					c=H+40-c;
					break;
				}
			}
		}

		
		for(i = 0; i < (H + 40)-c; i++){
			for(j = coloana; j< (L + bitiextra); j++){

				if((i >= 0) && (i < 20) && (j >= coloana)
				&& (j < coloana + 20)){
						imagine[H + 40 - 1 - c - i][j] = 8;
				}
			}
		}
	}
}
