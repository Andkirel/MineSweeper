#include "Main.h"
#include <stdlib.h>

wxBEGIN_EVENT_TABLE(Main, wxFrame)
    EVT_BUTTON(10001, OnButtonClicked)

wxEND_EVENT_TABLE()


Main::Main() :wxFrame(nullptr, wxID_ANY, "MineSweeper", wxPoint(30,30), wxSize(800,600))
{
	btn = new wxButton * [FieldWidth * FieldHeight];
	wxGridSizer* grid = new wxGridSizer(FieldWidth, FieldHeight, 0, 0);

	Field = new int[FieldWidth * FieldHeight];

	wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int x = 0; x < FieldWidth; x++)
	{
		for (int y = 0; y < FieldHeight; y++)
		{
			btn[y*FieldWidth + x] = new wxButton(this, 10000 + (y * FieldWidth + x));
			btn[y * FieldWidth + x]->SetFont(font);
			grid->Add(btn[y * FieldWidth + x], 1, wxEXPAND | wxALL);

			btn[y * FieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonClicked, this);
			Field[y * FieldWidth + x] = 0;
		}

		this->SetSizer(grid);
		grid->Layout();
	}


	//m_btn1 = new wxButton(this, 10001, "Play", wxPoint(10, 10), wxSize(150, 50));
	//m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	//m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
}

Main::~Main()
{
	delete[]btn;
}

void Main::OnButtonClicked(wxCommandEvent& evt)
{
	int x = (evt.GetId() - 10000) % FieldWidth;
	int y = (evt.GetId() - 10000) / FieldWidth;

	if (bFirstClick)
	{
		int mines = 30;
		while (mines)
		{
			int rx = rand() % FieldWidth;
			int ry = rand() % FieldHeight;

			if (Field[ry * FieldWidth + rx] == 0 && rx != x && ry != y)
			{
				Field[ry * FieldWidth + rx] = -1;
				mines--;
			}
		}

		bFirstClick = false;
	}

	btn[y * FieldWidth + x]->Enable(false);

	if (Field[y * FieldWidth + x] == -1)
	{
		wxMessageBox("BANGGGGG!!!! - Game Over");

		bFirstClick = true;
		for (int x = 0; x < FieldWidth; x++)
		{
			for (int y = 0; y < FieldHeight; y++)
			{
				Field[y * FieldWidth + x] = 0;
				btn[y * FieldWidth + x]->SetLabel("");
				btn[y * FieldWidth + x]->Enable(true);
			}
		}
	}
	else
	{
		int mine_count = 0;
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (x + i >= 0 && x + i < FieldWidth && y + j >= 0 && y + j < FieldHeight)
				{
					if (Field[(y + j) * FieldWidth + (x + i)] == -1)
					{
						if (Field[(y + j) * FieldWidth + (x + i)] == -1)
						{
							mine_count++;
						}	
					}
				}
			}
		}

		if (mine_count >= 0)
		{
			btn[y * FieldWidth + x]->SetLabel(std::to_string(mine_count));
		}
	}


	evt.Skip();
	
}
