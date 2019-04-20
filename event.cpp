#include "event.hpp"
// #include <windows.h>
// #include <shellapi.h>

using namespace std;

Event::Event() : title(""), description(""), date(DateTime()), numberOfPeople(0), link("") {}

Event::Event(const string& title, const string &description, 
		const DateTime& date, const int &numberOfPeople, const string& link)
{
	this->title = title;
	this->description = description;
	this->date = date;
	this->numberOfPeople = numberOfPeople;
	this->link = link;
}

void Event::openEvent()
{
	string sh = string("open ").append(this->link);
	system(sh.c_str());
}

bool Event::compareEvent(Event event)
{
	return this->title == event.getTitle();
}
