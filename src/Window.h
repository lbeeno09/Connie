#ifndef _WINDOW_H
#define _WINDOW_H

#include "WindowBase.h"

class Window : public WindowBase
{
public:
	Window() = default;
	~Window() = default;

	virtual void Init() final;
	virtual void Update() final;

private:
	bool showDemoWindow = {};

    void ShowMenuBar();
};

#endif
