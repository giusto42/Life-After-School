#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>

using namespace std;

class DateTime
{
private:
	double year;
	double month;
	double day;
	double hour;
	double minutes;
	double seconds;
public:
	DateTime() : year(1970), month(1), day(1), hour(0), minutes(0), seconds(0) {}
	DateTime(double year, double month, double day, 
		double hour, double min, double sec) :year(year), month(month), day(day), hour(hour), minutes(min), seconds(sec) {}

	double getYear() { return year; }
	double getMonth() { return month; }
	double getDay() { return day; }
	double getHour() { return hour; }
	double getMinutes() { return this->minutes; }
	double getSeconds() { return seconds; }

	void setYear(double year) { this->year = year; }
	void setMonth(double month) { this->month = month; }
	void setDay(double day) { this->day = day; }
	void setHour(double hour) { this->hour = hour; }
	void setMinutes(double min) { this->minutes = min; }
	void setSeconds(double sec) { this->seconds = sec; }
};

class Event
{
private:
	string title;
	string description;
	DateTime date;
	int numberOfPeople;
	string link;
public:
	Event();
	Event(const string& title, const string &description, 
		const DateTime& date, const int &numberOfPeople, const string& link);

	string getTitle() const { return title; }
	string getDescription() const { return description; }
	DateTime getDate() const { return date; }
	int getNumberOfPeople() const { return numberOfPeople; }
	string getLink() const { return link; }

	void setTitle(string title) { this->title = title; }
	void setDescription(string description) { this->description = description; }
	void setNumberOfPeople(int numberOfPeople) { this->numberOfPeople = numberOfPeople; }
	void setLink(string link) { this->link = link; }

	void openEvent();
	bool compareEvent(Event event);
};

#endif