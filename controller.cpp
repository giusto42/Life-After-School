#include "controller.hpp"

void Controller::addEventToRepo(const string& title, const string &description, 
	double year, double month, double day, double hour, double minutes, double secunds,
	 const int &numberOfPeople, const string& link)
{
	DateTime date = DateTime(year, month, day, hour, minutes, secunds);
	Event event = Event(title, description, date, numberOfPeople, link);

	this->repo.add(event);
}

void Controller::addEventToEventList(const Event& event)
{
	this->eventList.add(event);
	this->repo.incrementEventNumber(event);
	this->eventList.incrementEventNumber(event);
}

void Controller::deleteEventFromMyLibrary(const Event& event)
{
	this->eventList.deleteEvent(event);
	this->repo.decrementEventNumber(event);
	this->eventList.decrementEventNumber(event);
}

void Controller::nextEventInEventList()
{
	this->eventList.nextEvent();
}

DynamicVector<Event> Controller::getEventForMonth(double month)
{
	DynamicVector<Event> eventsFromRepo = this->repo.getEvents();
	Event *events = eventsFromRepo.getElems();
	DynamicVector<Event> eventsInMonth;

	for (int i = 0; i < eventsFromRepo.getSize(); i++)
	{
		if (events[i].getDate().getMonth() == month)
		{
			eventsInMonth.add(events[i]);
		}
	}

	return eventsInMonth;
}