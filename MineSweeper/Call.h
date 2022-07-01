#pragma once

#include "wx/wx.h"
#include "Main.h"

class Call : public wxApp
{
public:
	Call();
	~Call();
private:
	Main* m_frame1 = nullptr;

public:
	virtual bool OnInit();

};

