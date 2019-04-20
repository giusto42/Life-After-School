#include "event_list.hpp"

EventList::EventList()
{
	this->current = 0;
}

void EventList::add(const Event& event)
{
	this->event.add(event);
}

Event EventList::getCurrentEvent()
{
	if (this->current == this->event.getSize())
		this->current = 0;
	return this->event[this->current];
}

void EventList::openEvent()
{
	if (this->event.getSize() == 0)
		return;
	this->current = 0;
	Event currentEvent = this->getCurrentEvent();
	currentEvent.openEvent();
}

void EventList::nextEvent()
{
	if (this->event.getSize() == 0)
		return;
	this->current++;
	Event currentEvnt = this->getCurrentEvent();
	currentEvnt.openEvent();
}

bool EventList::isEmpty()
{
	return this->event.getSize() == 0;
}

int EventList::getEventPoz(Event event) 
{	
	Event *events = this->event.getElems();

	for (int i = 0; i < this->event.getSize(); i++)
	{
		if (events[i].compareEvent(event))
			return i;
	}
	return -1;
}

bool EventList::incrementEventNumber(Event event)
{
	Event *events  = this->event.getElems();

	int poz = getEventPoz(event);

	if (poz == -1)
		return false;

	events[poz].setNumberOfPeople(events[poz].getNumberOfPeople() + 1);
	return true;
}

bool EventList::decrementEventNumber(Event event)
{
	Event *events  = this->event.getElems();

	int poz = getEventPoz(event);

	if (poz == -1)
		return false;

	events[poz].setNumberOfPeople(events[poz].getNumberOfPeople() - 1);
	return true;
}

bool EventList::deleteEvent(const Event& event)
{
	return this->event.deleteEvent(event.getTitle());
}
