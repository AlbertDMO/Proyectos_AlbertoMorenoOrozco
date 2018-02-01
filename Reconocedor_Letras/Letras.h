#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

typedef struct letraideal{
	char letra;
	int unos,representacion[36];
	double value[36];
}LetraIdeal;

typedef struct letra{
	char letra;
	double *values;
	int representacion[36];
}Letra;

int** crearMatriz(int,int);
int** toMatrix(BMP);
void newLetraIdeal(LetraIdeal*,char,BMP);
int searchPattern(int**,int,int);
void setLimits(int,int*,int*,int*,int*);
int num1(int[]);
void imprimirDatos(LetraIdeal);
void getIdeales();
void setLetra(Letra*);
void newLetra(Letra*,BMP);
void compararLetras(Letra*);
void fflushin();