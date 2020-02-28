#include "bmp_header.h"		//CD 311 Veis Onur Șener
#include "functii.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc , char *argv[]) {
	int N, H, L,bitiextra, i, j,
	 l, rotatie, coloana;
	char numepiesa[2];
	
	if(( argv[1][0]=='1')||(argv[1][0]=='2')){ //task 1 si 2
		piesa_L();	//crearea fisierelor .bmp cu piesele
		piesa_O();	//aflate in cele patru tipuri de rotatie
		piesa_J();
   		piesa_I();
		piesa_S();
		piesa_Z();
		piesa_T();
	}

	if( argv[1][0]=='3'){	//task 3
		FILE *in = fopen("cerinta3.in", "r");
		
		fscanf(in, "%d", &N); 		//numar piese
		fscanf(in, "%d", &H);		//inaltimea imaginii
		fscanf(in, "%d", &L);		//latimea imaginii

		H = H * 10;
		L = L * 10;

		bitiextra = 4 - (L % 4);	//calcularea paddingului
		if(bitiextra == 4)
			bitiextra = 0;
		
		//alocarea dinamica de memorie pentru matricea imagine
		int ** imagine=(int **) malloc ((H + 40)*sizeof (int*)); 
		
		if(imagine == NULL){
			fprintf(stderr, "Nu s-a alocat memorie\n");
			return 1;
		}
		
		for (i = 0; i < H + 40; i++){
			
			imagine[i] = (int*) calloc (L + bitiextra,sizeof (int));
			if(imagine[i] == NULL){
				fprintf(stderr, "Nu s-a alocat memorie\n");
				return 1;
			}
		}

		//valoarea 0 reprezinta alb, iar 1 negru
		//se creaza fundalul imaginii
		for(i = 0; i < (H + 40); i++)
			for(j = 0; j< (L + bitiextra); j++){
				imagine[i][j] = 0;
				if(i>=40)
					imagine[i][j] = 1;
			}
		
		for(l = 0; l < N; l++) {
			fscanf(in, "%s", numepiesa);	//piesa
			fscanf(in, "%d", &rotatie);		//rotatia piesei
			fscanf(in, "%d", &coloana);		//coloana in matrice

			coloana = coloana*10;			
		//asezarea piesei la coloana respectiva
			if(numepiesa[0] == 'I'){		
				piesa_I_imagine(imagine, H, L,rotatie, coloana, bitiextra);
			}
			if(numepiesa[0] == 'L'){
				piesa_L_imagine(imagine, H, L,rotatie, coloana, bitiextra);
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
		//eliminarea randurilor pline
			Eliminare(imagine, H, L);		
		//verificare daca s-a ajuns pe portiunea alba a imaginii	
			if( (Verificare(imagine, L)) == 1)
					break;
			
		}
		//crearea fisierului bmp utilizand matricea imagine
		Imagine(imagine, H, L, bitiextra);
		
		//eliberarea memoriei
		for (i = 0; i < H + 40; i++)
        	free(imagine[i]);
      	
      	free(imagine); 
  		   
	}

	if(argv[1][0] == '4'){		//task 4
		task4();
	}
		
	return 0;
}