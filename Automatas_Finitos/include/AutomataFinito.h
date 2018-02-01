#ifndef AUTOMATAFINITO_H
#define AUTOMATAFINITO_H
#define MAX 50

class AutomataFinito{
	public:
		char *estados, *finales, * alfabeto;
		char inicial;
		char transiciones[MAX][MAX];

		int tam, trans_rand, edo_actual_int;
		char edo_actual, simb_actual;

		AutomataFinito(char* est, char ini, char* fin, char* alfa, char tr[MAX][MAX]);
		bool esFinal();
		int termina();
		int obtenIndice();
		int obtenIndiceAlfa();
		bool esDelAlfabeto();
};

#endif // AUTOMATAFINITO_H
