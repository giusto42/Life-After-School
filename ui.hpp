#ifndef UI_HPP
#define UI_HPP

#include "controller.hpp"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printMyEventListMenu();
	static void printEventMenu();
	static void printMyEventManagementMenu();

	void addEventToRepo();
	void displayAllEventRepo();
	void displayAllEventFromMyLibrary();
	void displayEvent(Event &event);
};

#endif

