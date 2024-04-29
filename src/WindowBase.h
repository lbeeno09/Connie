#ifndef _WINDOWBASE_H
#define _WINDOWBSE_H

#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <cstdio>
#include <cstdlib>

class WindowBase
{
public:
	WindowBase();

	virtual ~WindowBase();

	void Run();

	virtual void Init() = 0;
	virtual void Update() = 0;

protected:
	ImVec4 clearColor = {};

private:
	// System states
	GLFWwindow* window = {};
};

#endif