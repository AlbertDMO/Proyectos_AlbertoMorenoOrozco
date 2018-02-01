//---------------------------------------------------------------------------
//
// Name:        Cliente2App.cpp
// Author:      Alberto
// Created:     12/05/2014 12:38:02 p.m.
// Description: 
//
//---------------------------------------------------------------------------

#include "Cliente2App.h"
#include "Cliente2.h"

IMPLEMENT_APP(Cliente2App)

bool Cliente2App::OnInit()
{
    Cliente2* frame = new Cliente2(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int Cliente2App::OnExit()
{
	return 0;
}
