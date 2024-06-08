#include "MyForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault;
	Application::EnableVisualStyles;
	WebsiteManager::MyForm app;
	Application::Run(% app);
}