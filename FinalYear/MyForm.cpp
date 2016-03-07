#pragma once
#include "Inclusions.h"
#include "MainForm.h"
#include "ChooseVideoType.h"

using namespace FinalYear;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	Application::Run(gcnew MainForm());
	return 0;
}

