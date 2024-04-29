#include "Window.h"

void Window::Init()
{
	showDemoWindow = true;
}

void Window::Update()
{
	// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
	if(showDemoWindow)
	{
		ImGui::ShowDemoWindow(&showDemoWindow);
	}
}