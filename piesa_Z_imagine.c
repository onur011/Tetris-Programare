#include<stdio.h>			//CD 311 Veis Onur Șener
#include<stdlib.h>

void piesa_Z_imagine(int **imagine, int H, int L, int rotatie, int coloana,
int bitiextra){
	int i, j, c = 0;
	if((rotatie == 0) || (rotatie == 180)){
		for(i = 0; i < H + 40 ; i++){
			for(j = coloana; j< (L + bitiextra); j++){
				if((imagine[H + 40 - 1 - i][j] != 0) && 
				(imagine[H + 40 - 1 - i][j] != 1) && 
				(j >= coloana +10 ) && (j < coloana + 30)){
					c = H + 40 - i;
					c=c/10*10;
					c=H+40-c;
					break;
				}
				if((H + 40 - 1 - 10 - i >= 0) && 
				(imagine[H + 40 - 1 - 10 - i][j] != 0) && 
				(imagine[H + 40 - 1 - 10 - i][j] != 1) &&
				(j >= coloana ) && (j < coloana + 20)){
					c = H + 40 - i;
					c=c/10*10;
					c=H+40-c;
					break;
				}
			}
		}
		for(i = 0; i < (H + 40)-c; i++){
			for(j = coloana; j< (L + bitiextra); j++){

				if((i >= 10) && (i < 20) && (j >= coloana)
				&& (j < coloana + 20)){
					imagine[H + 40 - 1 - c - i][j] = 6;
				}
				if((i >= 0) && (i < 10) && (j >= coloana + 10)
				&& (j < coloana + 30)){
					imagine[H + 40 - 1 - c - i][j] = 6;
				}	
			}
		}
	}
	if((rotatie == 90) || (rotatie == 270)){
		for(i = 0; i < H + 40 ; i++){
			for(j = coloana; j< (L + bitiextra); j++){
				if((imagine[H + 40 - 1 - i][j] != 0) && 
				(imagine[H + 40 - 1 - i][j] != 1) && 
				(j >= coloana) && (j < coloana + 10)){
					c = H + 40 - i;
					c=c/10*10;
					c=H+40-c;
					break;
				}
				if((H + 40 - 1 - 10 - i >= 0) && 
				(imagine[H + 40 - 1 - 10 - i][j] != 0) && 
				(imagine[H + 40 - 1 - 10 - i][j] != 1) &&
				(j >= coloana + 10) && (j < coloana + 20)){
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
				&& (j < coloana + 10)){
					imagine[H + 40 - 1 - c - i][j] = 6;
				}
				if((i >= 10) && (i < 30) && (j >= coloana + 10)
				&& (j < coloana + 20)){
					imagine[H + 40 - 1 - c - i][j] = 6;
				}
			}
		}
	}
}
