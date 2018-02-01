#include "Letras.h"

int numLetras;
LetraIdeal *ideales;

int** crearMatriz(int m, int n){
	int i, j;
	int **A = (int**)malloc(m*sizeof(int*));

	for( i = 0; i < m; i++){
		A[i] = (int*)malloc(n*sizeof(int));
	}

	for( i = 0; i < m; i++){
		for( j = 0; j < n; j++){
			A[i][j] = 0;
		}
	}

	return A;
}

int** toMatrix(BMP img){
	int i, j, **mat = crearMatriz(img.alto, img.ancho);

	for( i = 0; i < img.alto; i++){
		for ( j = 0; j < img.ancho; j++){
			mat[i][j] = (img.pixelR[i][j] + 1) % 256;
		}
	}

	return mat;
}

void newLetraIdeal(LetraIdeal *letra, char name, BMP img){
	int **matrix = toMatrix(img), i, j, k = 0;
	letra -> letra = name;

	for ( i = 0; i < 9; i++){
		for( j = 0; j < 4; j++){
			letra -> representacion[i + j + k] =  searchPattern(matrix, i+1, j+1);
		}

		k += j - 1;
	}

	letra -> unos = num1(letra -> representacion);

	for( i = 0; i < 36; i++){
		if( letra -> representacion[i]){
			letra ->value[i] = 1.0/(double)letra -> unos;
		}else{
			letra -> value[i] = (1.0)/(double)letra -> unos;
		}
	}
}

int searchPattern(int** matrix, int region, int patron){
	int i, j, xInicio, xFinal, yInicio, yFinal;
	setLimits(region, &xInicio, &yInicio, &xFinal, &yFinal);

	switch(patron){
		case 1:{
			/* patron vertical
				0	1	0
				0	1	0	
				0	1	0
			*/
			for(i = yInicio; i <= (yFinal - 2); i++){
				for(j = xInicio; j <= xFinal; j++){
					if((matrix[i][j] == 1) && (matrix[i + 1][j] == 1) && (matrix[i + 2][j] == 1)){
						return 1;
					}
				}
			}
			break;
		}

		case 2:{
			/* Patron horizontal
				0	0	0
				1	1	1
				0	0	0
			*/
			for(i = xInicio; i <= (xFinal - 2); i++){
				for( j = yInicio; j <= yFinal; j++){
					if((matrix[j][i] == 1) && (matrix[j][i + 1] == 1) && (matrix[j][i + 2] == 1)){
						return 1;
					}
				}
			}
			break;
		}
		case 3:{
			/*patron diagonal
			1	0	0
			0	1	0
			0	0	1
			*/

			for(i = yInicio; i <= (yFinal - 2); i++){
				for(j = xInicio; j <= (xFinal - 2); j++){
					if((matrix[i][j] == 1) && (matrix[i + 1][j + 1]) && (matrix[i + 2][j + 2] == 1)){
						return 1;
					}
				}
			}
			break;
		}

		case 4:{
			/* Patron diagonal inverso
				0	0	1
				0	1	0
				1	0	0
			*/
			for(i = yFinal; i >=(yInicio + 2); i--){
				for(j = xInicio; j <= (xFinal - 2); j++){
					if((matrix[i][j] == 1) && (matrix[i - 1][j + 1] == 1) && (matrix[i - 2][j +2] == 1)){
						return 1;
					}
				}
			}
			break;
		}
		default:{
			puts("Opcion invalida.");
			break;
		}
	}
	return 0;
}

void setLimits(int region, int *xInicio, int *yInicio, int *xFinal, int *yFinal){
	switch(region){
		case 1:{
			*xInicio = 0;
			*yInicio = 0;
			*xFinal = 6;
			*yFinal = 6;
			break;
		}

		case 2:{
			*xInicio = 7;
			*yInicio = 0;
			*xFinal = 13;
			*yFinal = 6;
			break;
		}

		case 3:{
			*xInicio = 14;
			*yInicio = 0;
			*xFinal = 20;
			*yFinal = 6;
			break;
		}

		case 4:{
			*xInicio = 0;
			*yInicio = 7;
			*xFinal = 6;
			*yFinal = 13;
			break;
		}

		case 5:{
			*xInicio = 7;
			*yInicio = 7;
			*xFinal = 13;
			*yFinal = 13;
			break;
		}

		case 6:{
			*xInicio = 14;
			*yInicio = 7;
			*xFinal = 20;
			*yFinal = 13;
			break;
		}

		case 7:{
			*xInicio = 0;
			*yInicio = 14;
			*xFinal = 6;
			*yFinal = 20;
			break;
		}

		case 8:{
			*xInicio = 7;
			*yInicio = 14;
			*xFinal = 13;
			*yFinal = 20;
			break;
		}

		case 9:{
			*xInicio = 14;
			*yInicio = 14;
			*xFinal = 20;
			*yFinal = 20;
			break;
		}
		default:{
			puts("Opcion Invalida.");
			break;
		}
	}
}

int num1(int arr[]){
	int i, num = 0;

	for(i = 0; i < 36; i++){
		if(arr[i] == 1)
			num++;
	}
	return num;
}
void imprimirDatos(LetraIdeal letra){
	int i;
	puts("");
	printf("Letra Ideal: %c\n", letra.letra);
	printf("Vector de representacion: \n");
	for(i = 0; i < 36; i++){
		printf("%d", letra.representacion[i]);
		if((i + 1)%4 == 0)
			printf(" ");
	}
	puts("");
}

void getIdeales(){
	int i;
	BMP img;
	char arch[50], c;
	system("clear");
	puts("\n\tReconocimiento de Letras.");
	printf("Ingrese el numero de letras ideales que seran usadas: ");
	scanf("%d",&numLetras);
	ideales=(LetraIdeal*)malloc(numLetras*sizeof(LetraIdeal));
	for(i=0;i<numLetras;i++){
		fflushin();
		printf("\nLetra Ideal: ");
		scanf("%c",&c);
		printf("Ingrese la ruta de la imagen: ");
		scanf("%s",arch);
		abrir_imagen(&img,arch);
		newLetraIdeal(&ideales[i],c,img);
	}

	system("clear");
	puts("\nPatrones de letras ideales guardados correctamente.");
	for(i = 0; i < numLetras; i++)
		imprimirDatos(ideales[i]);
	printf("\nPulse una tecla para continuar...");
	fflushin();
	getchar();
}

void setLetra(Letra *letra){
	BMP img;
	char arch[50];
	system("clear");
	printf("\nIngrese la ruta de la imagen a analizar: ");
	scanf("%s",arch);
	abrir_imagen(&img, arch);
	newLetra(letra, img);
}

void newLetra(Letra *letra, BMP img){
	int i, j, k = 0, **matrix = toMatrix(img);
	letra -> values = (double*)malloc(numLetras*sizeof(double));
	for(i = 0; i < 9; i++){
		for(j = 0; j < 4; j++){
			letra -> representacion[i + j + k] = searchPattern(matrix, i + 1, j + 1);
		}
		k += j - 1; 
	}
}

void compararLetras(Letra *letra){
	int i, j;
	double aux;
	puts("");
	for(i = 0; i < numLetras; i++){
		aux = 0;
		for(j = 0; j < 36; j++){
			aux += (letra -> representacion[j]*(ideales[i].value[j]));
		}
		letra -> values[i] = aux;
		printf("Comparando con %c -> %f\n",ideales[i].letra, letra->values[i]);
	}
	letra -> letra = ideales[0].letra;
	for(i = 1; i < numLetras; i++){
		if(letra -> values[i - 1] < letra -> values[i]){
			letra -> letra = ideales[i].letra;
		}
	}
	printf("\nLa imagen analizada es una letra %c. \n\n", letra -> letra);
}

void fflushin(){
 	int d, i=0;
 	d = stdin->_IO_read_end - stdin->_IO_read_ptr;
 	for(i=0; i<d; i++)
		getchar();
}
