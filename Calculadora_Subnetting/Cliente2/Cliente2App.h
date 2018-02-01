//---------------------------------------------------------------------------
//
// Name:        Cliente2App.h
// Author:      Alberto
// Created:     12/05/2014 12:38:02 p.m.
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __CLIENTE2App_h__
#define __CLIENTE2App_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class Cliente2App : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
