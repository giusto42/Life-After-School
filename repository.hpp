#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP


#include "event.hpp"
#include "dynamic_vector.hpp"

class Repository
{
private:
	DynamicVector<Event>  event;

public:
	Repository() {}

	void add(const Event& event);
	void deleteEvent(const Event& event);
	void updateEvent(const Event& event);

	int getEventPoz(Event event);

	bool incrementEventNumber(Event event);
	bool decrementEventNumber(Event event);

	DynamicVector<Event> getEvents() const { return this->event; }
};

#endif