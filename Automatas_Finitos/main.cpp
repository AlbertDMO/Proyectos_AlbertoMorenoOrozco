#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "AutomataFinito.h"

using namespace std;

void genera(AutomataFinito af){
		if(af.esFinal() and af.termina()){
			cout << endl;
		}else{
			do{
				af.trans_rand = rand() % af.tam;
			}while(af.transiciones[af.edo_actual_int][af.trans_rand] == 'x' or af.trans_rand == 0);

			af.simb_actual = af.alfabeto[af.trans_rand - 1];
			cout << af.simb_actual;
			af.edo_actual = af.transiciones[af.edo_actual_int][af.trans_rand];
			af.edo_actual_int = af.obtenIndice();
			genera(af);
		}
	}

	void reconoce(char* cadena, AutomataFinito af){
		int t = strlen(cadena), i;
		int edo_sig;

		for(i = 0; i < t; i++){
			af.simb_actual = cadena[i];
            edo_sig = af.obtenIndiceAlfa();
			af.edo_actual = af.transiciones[af.edo_actual_int][edo_sig];
            if(af.edo_actual == 'x' or !af.esDelAlfabeto()){
				cout << "No se reconoce la cadena"  << endl;
				exit(0);
            }
			af.edo_actual_int = af.obtenIndice();
		}
		if(af.esFinal()){
			cout << "La cadena: \"" << cadena << "\" es parte del lenguaje" << endl;
		}else{
			cout << "No se reconoce la cadena"  << endl;
		}
	}

int main(int argc, char const *argv[])
{
    srand (time(NULL));
	char* nom_arch = (char*)argv[1];
	char* modo = (char*)argv[2];

	char estados[MAX], finales[MAX], alfabeto[MAX];
	char inicial;
	char trans[MAX][MAX];

	ifstream archivo(nom_arch);

	//obtener los estados
	archivo.getline(estados,MAX);

	//obtiene el inicial
	archivo.get(inicial);
	archivo.get();

	//obtiene los finales
	archivo.getline(finales, MAX);

	//obtiene alfabeto
	archivo.getline(alfabeto, MAX);

	//obtiene tabla de transiciones
	int i = 0;
	while(archivo.getline(trans[i], MAX)){
		i++;
	}
	archivo.close();

	AutomataFinito af(estados, inicial, finales, alfabeto, trans);
	if(strcmp(modo,"-g") == 0){
		cout << "Cadena Generada por el automata: " << endl;
		genera(af);
	}else if(strcmp(modo,"-r") == 0){
		char* cadena = (char*)argv[3];
		reconoce(cadena, af);
	}
	return 0;
}

