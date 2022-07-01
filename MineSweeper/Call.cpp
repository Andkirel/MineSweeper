#include "Call.h"

wxIMPLEMENT_APP(Call);

Call::Call()
{

}

Call::~Call()
{

}

bool Call::OnInit()
{
	m_frame1 = new Main();
	m_frame1->Show();

	return true;
}