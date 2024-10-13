#include "App.h"

App::App() { }

App::~App() { }

void App::init()
{
	// Our state
	showDemoWindow_ = true;
	showAnotherWindow_ = false;
}

void App::update()
{
	ImGui::DockSpaceOverViewport(0, ImGui::GetWindowViewport());

	if(showDemoWindow_)
	{
		ImGui::ShowDemoWindow(&showDemoWindow_);
	}

	{
		static float f = 0.0f;
		static int counter = 0;

		ImGui::Begin("Hello, world!");

		ImGui::Text("This is some useful text.");
		ImGui::Checkbox("Demo Window", &showDemoWindow_);
		ImGui::Checkbox("Another Window", &showAnotherWindow_);

		ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
		ImGui::ColorEdit3("clear color", (float *)&clearColor_);

		if(ImGui::Button("Button"))
		{
			counter++;
		}
		ImGui::SameLine();
		ImGui::Text("counter = %d", counter);

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

		ImGui::End();
	}

	if(showAnotherWindow_)
	{
		ImGui::Begin("Another Window", &showAnotherWindow_);

		ImGui::Text("Hello from another window!");
		if(ImGui::Button("Close Me"))
		{
			showAnotherWindow_ = false;
		}

		ImGui::End();
	}

}