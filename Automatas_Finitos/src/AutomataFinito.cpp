#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "AutomataFinito.h"
#define MAX 50

AutomataFinito::AutomataFinito(char* est, char ini, char* fin, char* alfa, char tr[MAX][MAX]){
	estados = new char[MAX];
	finales = new char[MAX];
	alfabeto = new char[MAX];

	strcpy(estados, est);
	strcpy(finales, fin);
	strcpy(alfabeto, alfa);
	inicial = ini;
	tam = strlen(tr[0]);
	for(int i = 0; i < tam; i++){
		strcpy(transiciones[i], tr[i]);
	}

	edo_actual = inicial;
	simb_actual = '\0';
	edo_actual_int = 0;
}

bool AutomataFinito::esFinal(){
	int i, t = strlen(finales);
	for(i = 0; i < t; i++){
		if(edo_actual == finales[i])
			return true;
	}
	return false;
}

int AutomataFinito::termina(){
	return rand() % 2;
}

int AutomataFinito::obtenIndice(){
	int i, t = strlen(estados);
	for(i = 0; i < t; i++){
		if(edo_actual == estados[i])
			return i;
	}
}

int AutomataFinito::obtenIndiceAlfa(){
	int i, t = strlen(alfabeto);
	for(i = 0; i < t; i++){
		if(simb_actual == alfabeto[i])
			return i+1;
	}
}

bool AutomataFinito::esDelAlfabeto(){
	int i, t = strlen(alfabeto);
	for(i = 0; i < t; i++){
		if(simb_actual == alfabeto[i])
			return true;
	}
	return false;
}
