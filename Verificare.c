#include<stdio.h>			//CD 311 Veis Onur Șener
#include<stdlib.h>

int Verificare(int **imagine, int L){
	int f, oprire, k;
//se verifica daca exista piesa pe portiunea alba
	oprire = 0;
	for(f = 0; f < 40 ; f++)
		for(k = 0; k < L; k++)
			if(imagine[f][k] != 0)
				oprire = 1;
	
	if(oprire == 1)
		return 1;
	else
		return 0;
}
