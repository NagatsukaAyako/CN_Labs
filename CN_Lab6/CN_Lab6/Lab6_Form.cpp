#include "Lab6_Form.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void StartFunction(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CN_Labs::MainForm form;
	Application::Run(%form);
}