#include "repository.hpp"

void Repository::add(const Event& event)
{
	this->event.add(event);
}

int Repository::getEventPoz(Event event) 
{	
	Event *events = this->event.getElems();

	for (int i = 0; i < this->event.getSize(); i++)
	{
		if (events[i].compareEvent(event))
			return i;
	}
	return -1;
}

bool Repository::incrementEventNumber(Event event)
{
	Event *events  = this->event.getElems();

	int poz = getEventPoz(event);

	if (poz == -1)
		return false;

	events[poz].setNumberOfPeople(events[poz].getNumberOfPeople() + 1);
	return true;
}

bool Repository::decrementEventNumber(Event event)
{
	Event *events  = this->event.getElems();

	int poz = getEventPoz(event);

	if (poz == -1)
		return false;

	events[poz].setNumberOfPeople(events[poz].getNumberOfPeople() - 1);
	return true;
}