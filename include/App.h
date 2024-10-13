#include "AppBase.h"

class App : public AppBase
{
public:
	App();

	~App();

	void init() override;

	void update() override;

private:
	void showMenuBar();

	// Our state
	bool showDemoWindow_;
	bool showAnotherWindow_;
};