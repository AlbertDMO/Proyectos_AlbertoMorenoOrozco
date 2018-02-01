///-----------------------------------------------------------------
///
/// @file      Cliente2.h
/// @author    Alberto
/// Created:   12/05/2014 12:38:03 p.m.
/// @section   DESCRIPTION
///            Cliente2 class declaration
///
///------------------------------------------------------------------

#ifndef __CLIENTE2_H__
#define __CLIENTE2_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/stattext.h>
////Header Include End

////Dialog Style Start
#undef Cliente2_STYLE
#define Cliente2_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class Cliente2 : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		Cliente2(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Cliente2"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = Cliente2_STYLE);
		virtual ~Cliente2();
		void AceptarClick(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxTextCtrl *no_bitsBox;
		wxTextCtrl *no_hxSRBox;
		wxTextCtrl *no_SRBox;
		wxTextCtrl *oct4;
		wxTextCtrl *oct3;
		wxTextCtrl *oct2;
		wxTextCtrl *oct1;
		wxButton *Aceptar;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_NO_BITSBOX = 1012,
			ID_NO_HXSRBOX = 1011,
			ID_NO_SRBOX = 1010,
			ID_OCT4 = 1009,
			ID_OCT3 = 1008,
			ID_OCT2 = 1007,
			ID_OCT1 = 1006,
			ID_ACEPTAR = 1005,
			ID_WXSTATICTEXT4 = 1004,
			ID_WXSTATICTEXT3 = 1003,
			ID_WXSTATICTEXT2 = 1002,
			ID_WXSTATICTEXT1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
