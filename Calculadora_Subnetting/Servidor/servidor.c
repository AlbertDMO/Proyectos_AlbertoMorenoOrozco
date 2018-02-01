#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "servidor.h"

#define MAX_CADENA 9
#define OCT 5

WSADATA wsaData;
SOCKET conn_socket,comm_socket;
SOCKET comunicacion;
struct sockaddr_in server;
struct sockaddr_in client;
struct hostent *hp;
int resp, stsize;
unsigned int addr;

char octeto1Buff[OCT], octeto2Buff[OCT], octeto3Buff[OCT], octeto4Buff[OCT];
char no_SR[MAX_CADENA], no_hxSR[MAX_CADENA], no_bitsBuff[3];

int octeto1, octeto2, octeto3, octeto4, no_bits, bits_hosts;
char clase;
const char* DEF = "0000000";
char dir[9] = {'C','l','a','s','e','s','\\','\0'};
FILE *lista_def, *tabla;

void RecibirDatos(){
	// Recibimos los datos del cliente
	// IP por octetos
	resp = recv(comm_socket, octeto1Buff, sizeof(octeto1Buff), 0);
	printf("Datos Recibidos: %s\n", octeto1Buff);
	octeto1Buff[resp] = '\0';
	octeto1 = atoi(octeto1Buff);
	
	resp = recv(comm_socket, octeto2Buff, sizeof(octeto2Buff), 0);
	printf("Datos Recibidos: %s\n", octeto2Buff);
	octeto2Buff[resp] = '\0';
	octeto2 = atoi(octeto2Buff);
	
	resp = recv(comm_socket, octeto3Buff, sizeof(octeto3Buff), 0);
	printf("Datos Recibidos: %s\n", octeto3Buff);
	octeto3Buff[resp] = '\0';
	octeto3 = atoi(octeto3Buff);
	
	resp = recv(comm_socket, octeto4Buff, sizeof(octeto4Buff), 0);
	printf("Datos Recibidos: %s\n", octeto4Buff);
	octeto4Buff[resp] = '\0';
	octeto4 = atoi(octeto4Buff);
	
	// Número de subredes
	resp = recv(comm_socket, no_SR, sizeof(no_SR), 0);
	printf("Datos Recibidos: %s\n", no_SR);
	no_SR[resp] = '\0';
	
	if(no_SR[0] == '0' && strlen(no_SR) < 7){
		strcpy(no_SR, DEF);
	}
	
	// Número de hosts por subred
	resp = recv(comm_socket, no_hxSR, sizeof(no_hxSR), 0);
	printf("Datos Recibidos: %s\n", no_hxSR);
	no_hxSR[resp] = '\0';
	
	if(no_hxSR[0] == '0' && strlen(no_hxSR) < 7){
		strcpy(no_hxSR, DEF);
	}
	
	// Número de bits prestados
	
	resp = recv(comm_socket, no_bitsBuff, sizeof(no_bitsBuff), 0);
	printf("Datos Recibidos: %s\n", no_bitsBuff);
	no_bitsBuff[resp] = '\0';
	no_bits = atoi(no_bitsBuff);
}

// Calcula la clase de red con la que se trabaja
char CalcClase(){
	// con octeto1 sabremos el tipo de clase que es
	if(octeto1 >= 0 && octeto1 < 128){
		return 'A';
	}else if(octeto1 >= 128 && octeto1 < 192){
		return 'B';
	}else if(octeto1 >=192  && octeto1 < 224){
		return 'C';
	}else{
		return '1';
	}
}

int BitsHost(){
	if(clase == 'A'){
		return 8*3;
	}else if(clase == 'B'){
		return 8*2;
	}else if(clase == 'C'){
		return 8;
	}
}

int ObtenNoBits(int caso){
	int cont1 = 0, cont2 = 0;
	char linea[20];
	
	if(caso == 1){
		char temp[strlen(no_hxSR)+1];
		strcpy(temp, no_hxSR);
		
		while(!feof(lista_def)){
			fgets(linea, 20, lista_def);
			if(atoi(temp) >= atoi(linea)){
				cont1--;
				break;
			}
			cont1++;
		}
		
	}else if(caso == 2){
		char temp[strlen(no_SR)+1];
		strcpy(temp, no_SR);
		
		while(!feof(lista_def)){
			fgets(linea, 20, lista_def);
			if(atoi(temp) <= atoi(linea)){
				break;
			}
			cont1++;
		}
	}
	
	char temp2[22];
	strcpy(temp2, dir);
	FILE *bitstxt = fopen(strcat(temp2,"\\no_bits.txt"), "r");
	
	while(!feof(bitstxt)){
		fgets(linea, 10, bitstxt);
		if(cont2 == cont1){
			fclose(bitstxt);
			return atoi(linea);
		}
		cont2++;
	}
}

void CreaTablaC(){
	int lineas_totales = pow(2, no_bits), j;
	octeto4 = 0;
	int int_dec = pow(2, bits_hosts);
	char ip[13], usa[3];
	sprintf(ip, "%03d.%03d.%03d.", octeto1, octeto2, octeto3);
	
	printf("Subnetting para red clase: \"%c\"\n", clase);
	fprintf(tabla,"Subnetting para red clase: \"%c\"\n", clase);
	fprintf(tabla,"%-4s| %-34s| %-16s| %-34s| %-16s| %-4s|\n", "SR", "Intervalo Decimal", "ID SubRed", "Intervalo Hosts", "Broadcast", "Usa");
	printf("%-4s| %-34s| %-15s| %-34s| %-15s| %-4s|\n", "SR", "Intervalo Decimal", "ID SubRed", "Intervalo Hosts", "Broadcast", "Usa");
	
	for(j = 1; j<= lineas_totales; j++){
		if(j == 1 || j == lineas_totales){
			strcpy(usa, "NO");
		}
		else{
			strcpy(usa, "SI");
		}
		
		fprintf(tabla, "%-3d | %s%03d - %s%03d | %s%03d | %s%03d - %s%03d | %s%03d | %-3s |\n", j, ip, octeto4, ip, octeto4+int_dec-1,ip, octeto4, ip, octeto4+1, ip, octeto4+int_dec-2, ip, octeto4+int_dec-1, usa);
		printf("%-3d | %s%03d - %s%03d | %s%03d | %s%03d - %s%03d | %s%03d | %-3s |\n", j, ip, octeto4, ip, octeto4+int_dec-1,ip, octeto4, ip, octeto4+1, ip, octeto4+int_dec-2, ip, octeto4+int_dec-1, usa);
		octeto4 += int_dec;
	}
}

void CreaTablaB(){
	int lineas_totales = pow(2, no_bits), j;
	int bits_oct3 = 8 - no_bits;
	int int_oct3, int_oct4;
	char ip[9], usa[3];
	octeto3 = 0;
	octeto4 = 0;
	sprintf(ip, "%03d.%03d.", octeto1, octeto2);
	
	printf("Subnetting para red clase: \"%c\"\n", clase);
	fprintf(tabla,"Subnetting para red clase: \"%c\"\n", clase);
	fprintf(tabla,"%-5s| %-34s| %-16s| %-34s| %-16s| %-4s|\n", "SR", "Intervalo Decimal", "ID SubRed", "Intervalo Hosts", "Broadcast", "Usa");
	printf("%-5s| %-34s| %-15s| %-34s| %-15s| %-4s|\n", "SR", "Intervalo Decimal", "ID SubRed", "Intervalo Hosts", "Broadcast", "Usa");
	
	if(bits_oct3 > 0){
		int_oct3 = pow(2, bits_oct3);
		int_oct4 = 256;
	}
	else{
		int_oct3 = 1;
		int_oct4 = pow(2, bits_hosts);
	}
	
	for(j = 1; j<= lineas_totales; j++){
		if(j == 1 || j == lineas_totales){
			strcpy(usa, "NO");
		}
		else{
			strcpy(usa, "SI");
		}
		
		if(octeto4 == 256){
			octeto4 = 0;
			octeto3 += int_oct3;
		}
		fprintf(tabla, "%-4d | %s%03d.%03d - %s%03d.%03d | %s%03d.%03d | %s%03d.%03d - %s%03d.%03d | %s%03d.%03d | %-3s |\n", j, ip, octeto3, octeto4, ip, octeto3+int_oct3-1, octeto4+int_oct4-1, ip, octeto3, octeto4, ip, octeto3, octeto4+1, ip, octeto3+int_oct3-1, octeto4+int_oct4-2, ip, octeto3+int_oct3-1, octeto4+int_oct4-1, usa);
		printf("%-4d | %s%03d.%03d - %s%03d.%03d | %s%03d.%03d | %s%03d.%03d - %s%03d.%03d | %s%03d.%03d | %-3s |\n", j, ip, octeto3, octeto4, ip, octeto3+int_oct3-1, octeto4+int_oct4-1, ip, octeto3, octeto4, ip, octeto3, octeto4+1, ip, octeto3+int_oct3-1, octeto4+int_oct4-2, ip, octeto3+int_oct3-1, octeto4+int_oct4-1, usa);
		octeto4 += int_oct4;		
	}
	
}

void CreaTablaA(){
	int lineas_totales = pow(2, no_bits), j;
	int bits_oct2 = 8 - no_bits;
	int bits_oct3 = 16 - no_bits;
	int int_oct2, int_oct3, int_oct4;
	char usa[3];
	int oct2, oct3, oct4;
	
	octeto2 = 0;
	octeto3 = 0;
	octeto4 = 0;
	
	printf("Subnetting para red clase: \"%c\"\n", clase);
	fprintf(tabla,"Subnetting para red clase: \"%c\"\n", clase);
	fprintf(tabla,"%-7s | %-34s| %-16s| %-34s| %-16s| %-4s|\n", "SR", "Intervalo Decimal", "ID SubRed", "Intervalo Hosts", "Broadcast", "Usa");
	printf("%-7s | %-34s| %-15s| %-34s| %-15s| %-4s|\n", "SR", "Intervalo Decimal", "ID SubRed", "Intervalo Hosts", "Broadcast", "Usa");
	
	if(bits_oct2 > 0){
		int_oct2 = pow(2, bits_oct2);
		int_oct3 = 256;
		int_oct4 = 256;
	}
	else{
		int_oct2 = 1;	
		
		if(bits_oct3 > 0){
			int_oct3 = pow(2, bits_oct3);
			int_oct4 = 256;
		}
		else{
			int_oct3 = 1;
			int_oct4 = pow(2, bits_hosts);
		}
		
	}
	
	for(j = 1; j<= lineas_totales; j++){
		if(j == 1 || j == lineas_totales){
			strcpy(usa, "NO");
		}
		else{
			strcpy(usa, "SI");
		}
		
		if(octeto4 == 256){
			octeto4 = 0;
			octeto3 += int_oct3;
			
			if(octeto3 == 256){
				octeto3 = 0;
				octeto2 += int_oct2;
			}
		}
		oct2 = octeto2 + int_oct2;
		oct3 = octeto3 + int_oct3;
		oct4 = octeto4 + int_oct4;
		fprintf(tabla, "%-7d | %03d.%03d.%03d.%03d - %03d.%03d.%03d.%03d | %03d.%03d.%03d.%03d | %03d.%03d.%03d.%03d - %03d.%03d.%03d.%03d | %03d.%03d.%03d.%03d | %-3s |\n", j, octeto1, octeto2, octeto3, octeto4, octeto1, oct2-1, oct3-1, oct4-1, octeto1, octeto2, octeto3, octeto4, octeto1, octeto2, octeto3, octeto4+1, octeto1, oct2-1, oct3-1, oct4-2, octeto1, oct2-1, oct3-1, oct4-1, usa);
		printf("%-7d | %03d.%03d.%03d.%03d - %03d.%03d.%03d.%03d | %03d.%03d.%03d.%03d | %03d.%03d.%03d.%03d - %03d.%03d.%03d.%03d | %03d.%03d.%03d.%03d | %-3s |\n", j, octeto1, octeto2, octeto3, octeto4, octeto1, oct2-1, oct3-1, oct4-1, octeto1, octeto2, octeto3, octeto4, octeto1, octeto2, octeto3, octeto4+1, octeto1, oct2-1, oct3-1, oct4-2, octeto1, oct2-1, oct3-1, oct4-1, usa);
		octeto4 += int_oct4;		
	}
}

// Proceso general que obtiene la tabla de subnetting
void CalcularTabla(){
	clase = CalcClase();
	
	if(clase != '1'){
		
		if(no_bits != 0){
		}
		else{
			
			char clase2[2] = {clase,'\0'};
			strcat(dir, clase2);
			char temp[22];
			
			strcpy(temp, dir);
			
			if(strcmp(no_hxSR, DEF) != 0 && strcmp(no_SR, DEF) == 0){
				lista_def = fopen(strcat(temp,"\\no_hxSR.txt"), "r");
				no_bits = ObtenNoBits(1);
				
			}else if(strcmp(no_SR, DEF) != 0 && strcmp(no_hxSR, DEF) == 0){
				lista_def = fopen(strcat(temp,"\\no_SR.txt"), "r");
				no_bits = ObtenNoBits(2);
			}
			fclose(lista_def);
		}
		
		bits_hosts = BitsHost();
		bits_hosts = bits_hosts - no_bits;
		tabla = fopen("tabla.txt", "w");
		
		switch(clase){
			case 'A':
				CreaTablaA();
				break;
			case 'B':
				CreaTablaB();
				break;
			case 'C':
				CreaTablaC();
				break;
		}
		
		fclose(tabla);
	}
}

void EnviarDatos(){
	tabla = fopen("tabla.txt", "r");
	int lineas_totales = pow(2, no_bits);
	char lineas[8], tupla[150];
	
	sprintf(lineas, "%d", lineas_totales);
	
	send (comm_socket, lineas, sizeof(lineas), 0);
	printf("Datos enviados: %s \n", lineas);
	
	while(!feof(tabla)){
		fgets(tupla, 150, tabla);
		send (comm_socket, tupla, sizeof(tupla), 0);
		printf("Datos enviados: %s \n", tupla);
	}
	fclose(tabla);
}

int main(){
	
	while(1){
	//Inicializamos la DLL de sockets
	resp=WSAStartup(MAKEWORD(1,0),&wsaData);
	if(resp){
		printf("Error al inicializar socket\n");
		getchar();
		return resp;
	}
	
	//Obtenemos la IP que usará nuestro servidor... 
	// en este caso localhost indica nuestra propia máquina...
	hp=(struct hostent *)gethostbyname("localhost");
	/*printf("Address type: %i.\n\n", hp->h_addrtype);
	printf("Hostname is: %s.\n", hp->h_name);*/
	//addr = inet_addr(host_name);
	//hp = gethostbyaddr((char *)&addr, 4, AF_INET);
	
	if(!hp){
		printf("No se ha encontrado servidor...\n");
		getchar();
		WSACleanup();
		return WSAGetLastError();
	}
	
	// Creamos el socket...
	conn_socket=socket(AF_INET,SOCK_STREAM, 0);
	if(conn_socket==INVALID_SOCKET) {
		printf("Error al crear socket\n");
		getchar();
		WSACleanup();
		return WSAGetLastError();
	}
	
	memset(&server, 0, sizeof(server)) ;
	memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
	server.sin_family = hp->h_addrtype;
	server.sin_port = htons(6000);
	
	// Asociamos ip y puerto al socket
	resp=bind(conn_socket, (struct sockaddr *)&server, sizeof(server));
	if(resp==SOCKET_ERROR){
		printf("Error al asociar puerto e ip al socket\n");
		closesocket(conn_socket);
		WSACleanup();
		getchar();
		return WSAGetLastError();
	}
	if(listen(conn_socket, 1)==SOCKET_ERROR){
		printf("Error al habilitar conexiones entrantes\n");
		closesocket(conn_socket);WSACleanup();
		getchar();
		return WSAGetLastError();
	}
	          
	// Aceptamos conexiones entrantes
	printf("Esperando conexiones entrantes... \n");
	stsize=sizeof(struct sockaddr);
	comm_socket=accept(conn_socket,(struct sockaddr *)&client,&stsize);
	if(comm_socket==INVALID_SOCKET){
		printf("Error al aceptar conexión entrante\n");
		closesocket(conn_socket);
		WSACleanup();
		getchar();
		return WSAGetLastError();
	}
	printf("Conexion entrante desde: %s\n", inet_ntoa(client.sin_addr));
	          
	// Como no vamos a aceptar más conexiones cerramos el socket escucha
	closesocket(conn_socket);
	          
	RecibirDatos();
	CalcularTabla();
	EnviarDatos();
	
	// Cerramos el socket de la comunicacion
	closesocket(comm_socket);
	
	// Cerramos liberia winsock
	WSACleanup();
	//getchar();
}
	return 0;
}
