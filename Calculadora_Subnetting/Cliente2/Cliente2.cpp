///-----------------------------------------------------------------
///
/// @file      Cliente2.cpp
/// @author    Alberto
/// Created:   12/05/2014 12:38:03 p.m.
/// @section   DESCRIPTION
///            Cliente2 class implementation
///
///------------------------------------------------------------------

#include "Cliente2.h"
#include "ClienteSocket.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define MAX_CADENA 9
#define OCT 5

char SendBuff[512],RecvBuff[512];
WSADATA wsaData;
SOCKET conn_socket;
struct sockaddr_in server;
struct hostent *hp;
int resp;

char octeto1[OCT], octeto2[OCT], octeto3[OCT], octeto4[OCT];
char no_SR[MAX_CADENA], no_hxSR[MAX_CADENA], no_bits[3];

wxString wxoct1, wxoct2, wxoct3, wxoct4;
wxString wxno_SR, wxno_hxSR, wxno_bits;

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// Cliente2
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Cliente2,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(Cliente2::OnClose)
	EVT_BUTTON(ID_ACEPTAR,Cliente2::AceptarClick)
END_EVENT_TABLE()
////Event Table End

Cliente2::Cliente2(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

Cliente2::~Cliente2()
{
}

void Cliente2::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	no_bitsBox = new wxTextCtrl(this, ID_NO_BITSBOX, _("0"), wxPoint(131, 282), wxSize(44, 22), wxTE_CENTRE, wxDefaultValidator, _("no_bitsBox"));
	no_bitsBox->SetMaxLength(2);
	no_bitsBox->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	no_hxSRBox = new wxTextCtrl(this, ID_NO_HXSRBOX, _("0"), wxPoint(106, 209), wxSize(94, 22), wxTE_CENTRE, wxDefaultValidator, _("no_hxSRBox"));
	no_hxSRBox->SetMaxLength(7);
	no_hxSRBox->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	no_SRBox = new wxTextCtrl(this, ID_NO_SRBOX, _("0"), wxPoint(108, 133), wxSize(94, 22), wxTE_CENTRE, wxDefaultValidator, _("no_SRBox"));
	no_SRBox->SetMaxLength(7);
	no_SRBox->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	oct4 = new wxTextCtrl(this, ID_OCT4, _("0"), wxPoint(209, 55), wxSize(35, 22), 0, wxDefaultValidator, _("oct4"));
	oct4->SetMaxLength(3);
	oct4->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	oct3 = new wxTextCtrl(this, ID_OCT3, _("0"), wxPoint(168, 55), wxSize(35, 22), 0, wxDefaultValidator, _("oct3"));
	oct3->SetMaxLength(3);
	oct3->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	oct2 = new wxTextCtrl(this, ID_OCT2, _("0"), wxPoint(127, 55), wxSize(35, 22), 0, wxDefaultValidator, _("oct2"));
	oct2->SetMaxLength(3);
	oct2->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	oct1 = new wxTextCtrl(this, ID_OCT1, _("0"), wxPoint(86, 55), wxSize(35, 22), 0, wxDefaultValidator, _("oct1"));
	oct1->SetMaxLength(3);
	oct1->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	Aceptar = new wxButton(this, ID_ACEPTAR, _("Aceptar"), wxPoint(112, 321), wxSize(75, 25), 0, wxDefaultValidator, _("Aceptar"));

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, _("Número de bits prestados"), wxPoint(81, 250), wxDefaultSize, 0, _("WxStaticText4"));
	WxStaticText4->SetBackgroundColour(wxColour(_("WHITE")));
	WxStaticText4->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("Número de hosts por SubRed"), wxPoint(72, 172), wxDefaultSize, 0, _("WxStaticText3"));
	WxStaticText3->SetBackgroundColour(wxColour(_("WHITE")));
	WxStaticText3->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Número de SubRedes"), wxPoint(91, 101), wxDefaultSize, 0, _("WxStaticText2"));
	WxStaticText2->SetBackgroundColour(wxColour(_("WHITE")));
	WxStaticText2->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _(" IP:"), wxPoint(53, 56), wxDefaultSize, 0, _("WxStaticText1"));
	WxStaticText1->SetBackgroundColour(wxColour(_("WHITE")));
	WxStaticText1->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	SetTitle(_("Calculadora de Subnetting"));
	SetIcon(wxNullIcon);
	SetSize(116,11,331,400);
	Center();
	
	////GUI Items Creation End
}

void Cliente2::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * AceptarClick
 */
void Cliente2::AceptarClick(wxCommandEvent& event)
{
	// insert your code here
	wxoct1 = oct1->GetValue();
	wxoct2 = oct2->GetValue();
	wxoct3 = oct3->GetValue();
	wxoct4 = oct4->GetValue();
	wxno_SR = no_SRBox->GetValue();
	wxno_hxSR = no_hxSRBox->GetValue();
	wxno_bits = no_bitsBox->GetValue();
	
	//system(wxoct1.c_str());
	
	// convierte el wxString en char*
	strcpy(octeto1, wxoct1.mb_str());
	strcpy(octeto2, wxoct2.mb_str());
	strcpy(octeto3, wxoct3.mb_str());
	strcpy(octeto4, wxoct4.mb_str());
	
	strcpy(no_SR, wxno_SR.mb_str());
	strcpy(no_hxSR, wxno_hxSR.mb_str());
	strcpy(no_bits, wxno_bits.mb_str());
	
	SocketCliente();
}

// Funciones hechos sin el API
void EnviarDatos(){
	send(conn_socket,octeto1,sizeof(octeto1),0);
	printf("Datos enviados: %s \n", octeto1);
	send(conn_socket,octeto2,sizeof(octeto2),0);
	printf("Datos enviados: %s \n", octeto2);
	send(conn_socket,octeto3,sizeof(octeto3),0);
	printf("Datos enviados: %s \n", octeto3);
	send(conn_socket,octeto4,sizeof(octeto4),0);
	printf("Datos enviados: %s \n", octeto4);
	
	send(conn_socket,no_SR,sizeof(no_SR),0);
	printf("Datos enviados: %s \n", no_SR);
	send(conn_socket,no_hxSR,sizeof(no_hxSR),0);
	printf("Datos enviados: %s \n", no_hxSR);
	send(conn_socket,no_bits,sizeof(no_bits),0);
	printf("Datos enviados: %s \n", no_bits);
}

void PrintTabla(){
	char lineas[8], tupla[150], cad[30], dir_tabla[40];
	int lineas_totales, j;
	/*time_t tiempo;
	struct tm *tmPtr;
	
  	tiempo = time(NULL);
  	tmPtr = localtime(&tiempo);
  	strftime(cad, 30, "%d-%m-%y_%H.%M.%S.txt", tmPtr );
  	puts(cad);
  	strcpy(dir_tabla, "tabla-");
	//FILE *tabla = fopen(strcat(dir_tabla, cad), "w");*/
	FILE *tabla = fopen("tabla.txt", "w");
	
	recv(conn_socket, lineas, sizeof(lineas), 0);
	printf("Datos recibidos: %s \n", lineas);
	lineas_totales = atoi(lineas);
	
	for(j = -1; j <= lineas_totales; j++){
		recv(conn_socket,tupla, sizeof(tupla), 0);
		fputs(tupla, tabla);
		puts(tupla);
	}
	ShellExecute(NULL,_T("open"),_T("tabla.txt"), NULL,NULL, SW_NORMAL); 
	//ShellExecute(NULL,_T("open"), _T("dir_tabla"), NULL, NULL, SW_NORMAL); 
	fclose(tabla);
}

int SocketCliente(){
	
	//Inicializamos la DLL de sockets
	resp=WSAStartup(MAKEWORD(1,0),&wsaData);
	if(resp){
		printf("Error al inicializar socket\n");
		getchar();
		return -1;
	}
	
	//Obtenemos la IP del servidor... en este caso
	// localhost indica nuestra propia máquina...
	hp=(struct hostent *)gethostbyname("localhost");
	
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
	
	// Nos conectamos con el servidor...
	if(connect(conn_socket,(struct sockaddr *)&server,sizeof(server))==SOCKET_ERROR){
		printf("Fallo al conectarse con el servidor\n");
		closesocket(conn_socket);
		WSACleanup();
		getchar();
		return WSAGetLastError();
	}
	
	printf("Conexion establecida con: %s\n", inet_ntoa(server.sin_addr)); 
	
	//RecibirDatos();
	EnviarDatos();
	PrintTabla();
	
	getchar();
	// Cerramos el socket y liberamos la DLL de sockets
	closesocket(conn_socket);
	WSACleanup();
	return 0;
}


