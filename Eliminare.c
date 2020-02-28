#include<stdio.h>				//CD 311 Veis Onur Șener
#include<stdlib.h>


void Eliminare(int **imagine, int H, int L){
	int i, j, f, k, eliminare;
//se parcurge matricea imagine in cautare
//de linii pline
	for(i = 0; i < (H + 40); i++){
		eliminare = 1;
		
		for(j = 0; j< L; j++){
			if((imagine[i][j] == 0) || 
			(imagine[i][j] == 1))
				eliminare = 0;
		}
	//daca s-a gasit o linie plina, aceasta 
	//este eliminata si liniile coboara pana
	//la cea eliminata
		if(eliminare == 1){
			for (f=i;f>1;f--)
    			for(k=0;k< L;k++)
				if(f-1>=0)
					imagine[f][k]=imagine[f-1][k];		
		}
	//dupa ce s-a eliminat, apar in plus linii de
	//culoare alba ,din cauza coborarii unei bucati din matrice,
	//care sunt schimbate in culoarea negru
		for(f =40; f < 40+H; f++)
			for(k = 0; k< L ; k++)
				if(imagine[f][k]==0)
					imagine[f][k]=1;
	}
	
}
