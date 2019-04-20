#ifndef EVENT_LIST_HPP
#define EVENT_LIST_HPP

#include "event.hpp"
#include "dynamic_vector.hpp"

class EventList
{
private:
	DynamicVector<Event> event;
	int current;
public:
	EventList();

	DynamicVector<Event> getEvents() const { return this->event; }
	
	void add(const Event& event);

	bool deleteEvent(const Event& event);	

	Event getCurrentEvent();

	void openEvent();

	void nextEvent();

	bool isEmpty();

	int getEventPoz(Event event);

	bool incrementEventNumber(Event event);
	bool decrementEventNumber(Event event);
};


#endif