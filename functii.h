#include <stdio.h>			//CD 311 Veis Onur Șener
#include <string.h>
#include <stdlib.h>

void piesa_O();
void piesa_L();
void piesa_J();
void piesa_I();
void piesa_S();
void piesa_Z();
void piesa_T();
void piesa_O_imagine(int **imagine, int H, int L, int rotatie, int coloana,
	int bitiextra);
void piesa_J_imagine(int **imagine, int H, int L, int rotatie, int coloana,
	int bitiextra);
void piesa_T_imagine(int **imagine, int H, int L, int rotatie, int coloana,
	int bitiextra);
void piesa_Z_imagine(int **imagine, int H, int L, int rotatie, int coloana,
	int bitiextra);
void piesa_S_imagine(int **imagine, int H, int L, int rotatie, int coloana,
	int bitiextra);
void piesa_L_imagine(int **imagine, int H, int L, int rotatie, int coloana,
	int bitiextra);
void piesa_I_imagine(int **imagine, int H, int L, int rotatie, int coloana,
	int bitiextra);
void Imagine(int **imagine, int H, int L, int bitiextra);
void Eliminare(int **imagine, int H, int L);
int Verificare(int **imagine, int L);
void Imagine4(int **imagine, int H, int L, int bitiextra);
void task4();
