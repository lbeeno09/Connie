#include "Window.h"

void Window::Init()
{
	showDemoWindow = true;
}

void Window::Update()
{
    // Menu bar
    ShowMenuBar();

	if(showDemoWindow)
	{
		ImGui::ShowDemoWindow(&showDemoWindow);
	}


}
