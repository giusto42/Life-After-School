#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "repository.hpp"
#include "event_list.hpp"

#include <iostream>

using namespace std;

class Controller
{
private:
	Repository repo;
	EventList eventList;

public:
	Controller(const Repository& repo) : repo(repo) {}

	Repository getRepo()const { return this->repo; }
	EventList getEventList() const { return this->eventList; }

	void addEventToRepo(const string& title, const string &description, 
	double year, double month, double day, double hour, double minutes, double secunds,
	 const int &numberOfPeople, const string& link);

	void addEventToEventList(const Event& event);

	void deleteEventFromMyLibrary(const Event& event);

	void nextEventInEventList();

	DynamicVector<Event> getEventForMonth(double month);
};

#endif