#pragma once
#include "wx/wx.h"

class Main : public wxFrame
{
public:
	Main();
	~Main();
public:

	
	int FieldWidth = 10;
	int FieldHeight = 10;
	wxButton **btn;
	int* Field = nullptr;
	bool bFirstClick = true;

	void OnButtonClicked(wxCommandEvent& evt);
	
	wxDECLARE_EVENT_TABLE();
};

