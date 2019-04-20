#include "ui.hpp"
#include <string>

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 Manage event repository." << endl;
	cout << "2 Manage my eventList." << endl;
	cout << "0 Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << endl;
	cout << "1 Add event." << endl;
	cout << "2 Show all event." << endl;
	cout << "0 Return." << endl;
}

void UI::printMyEventListMenu()
{
	cout << endl;
	cout << "1 Show event for a given month." << endl;
	cout << "2 Show event I'm going." << endl;
	cout << "3 Manage event I'm going." << endl;
	cout << "0 Return." << endl;
}

void UI::printMyEventManagementMenu()
{
	cout << endl;
	cout << "1 Next event." << endl;
	cout << "2 Delete event." << endl;
	cout << "0 Return." << endl;
}

void UI::printEventMenu()
{
	cout << endl;
	cout << "1 Add event to my list." << endl;
	cout << "2 Show event." << endl;
	cout << "3 Next event." << endl;
	cout << "0 Return." << endl;
}

void UI::addEventToRepo()
{
	system("clear");
	cout << "Enter the title: ";
	string title;
	getline(cin, title);
	cout << "Enter the description: ";
	string description;
	getline(cin, description);
	cout << "Enter the year: ";
	double year = 1970;
	cin >> year;
	cout << "Enter the month: ";
	double month = 1;
	cin >> month;
	cout << "Enter the day: ";
	double day = 1;
	cin >> day;
	cout << "Enter the hour: ";
	double hour = 0;
	cin >> hour;
	cout << "Enter the minutes: ";
	double minutes = 0;
	cin >> minutes;
	cout << "Enter the seconds: ";
	double seconds = 0;
	cin >> seconds;
	cout << "Enter the numberOfPeople: ";
	double numberOfPeople = 0;
	cin >> numberOfPeople;
	cin.ignore();
	cout << "Enter the link: ";
	string link;
	getline(cin, link);

	this->ctrl.addEventToRepo(title, description, year, month, day, hour, minutes, seconds, numberOfPeople, link);
}

void UI::displayAllEventRepo()
{
	system("clear");
	DynamicVector<Event> v = this->ctrl.getRepo().getEvents();
	Event* events = v.getElems();

	if (events == NULL)
		return;

	if (v.getSize() == 0) {
		cout << "There are no events to display." << endl;
		return;
	}

	for (int i = 0; i < v.getSize(); i++)
	{
		Event event = events[i];
		DateTime date = event.getDate();
		cout << "\nTitle: " << event.getTitle() << "\nDescription: " << event.getDescription() << "\nEvent time: " <<
		 date.getYear() << "/" << date.getMonth() <<
		  "/" << date.getDay() <<
		   " " << date.getHour() <<
		    ":" << date.getMinutes() << "\nGoing people number: " << event.getNumberOfPeople() << endl;
	}
}

void UI::displayAllEventFromMyLibrary()
{
	system("clear");
	DynamicVector<Event> v = this->ctrl.getEventList().getEvents();
	Event* events = v.getElems();

	if (events == NULL)
		return;

	if (v.getSize() == 0) {
		cout << "There are no events to display." << endl;
		return;
	}

	for (int i = 0; i < v.getSize(); i++)
	{
		Event event = events[i];
		DateTime date = event.getDate();
		cout << "\nTitle: " << event.getTitle() << "\nDescription: " << event.getDescription() << "\nEvent time: " <<
		 date.getYear() << "/" << date.getMonth() <<
		  "/" << date.getDay() <<
		   " " << date.getHour() <<
		    ":" << date.getMinutes() << "\nGoing people number: " << event.getNumberOfPeople() << endl;
	}
}

void UI::displayEvent(Event &event)
{
	system("clear");
	DateTime date = event.getDate();
	cout << "\nTitle: " << event.getTitle() << "\nDescription: " << event.getDescription() << "\nEvent time: " <<
	 date.getYear() << "/" << date.getMonth() << "/" << date.getDay() << " " << date.getHour() << ":" << date.getMinutes() << endl;
}

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command = 0;
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
		{
			system("clear");
			break;
		}

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo = 0;
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
				{
					system("clear");
					break;
				}
				switch (commandRepo)
				{
				case 1:
					this->addEventToRepo();
					break;
				case 2:
					this->displayAllEventRepo();
				}
			}
		}
		else if (command == 2)
		{
			while (true)
			{
				UI::printMyEventListMenu();
				int commandMyEventList = 0;
				cout << "Input the command: ";
				cin >> commandMyEventList;
				cin.ignore();
				if (commandMyEventList == 0)
				{
					system("clear");
					break;
				}
				
				else if (commandMyEventList == 1)
				{
					int month = 0;
					cout << "Input the month for the events you want to see: ";
					cin >> month;
					cin.ignore();
					DynamicVector<Event> eventsInMonth = this->ctrl.getEventForMonth(month);
					int currentEvent = 0;
					if (eventsInMonth.getSize() == 0)
						cout << "There are no events to display." << endl;
					else
					{
						while (true)
						{
							UI::displayEvent(eventsInMonth[currentEvent]);
							UI::printEventMenu();
							int commandEvent = 0;
							cout << "Input the command: ";
							cin >> commandEvent;
							cin.ignore();
							if (commandEvent == 0)
							{
								system("clear");
								break;
							}
							switch (commandEvent)
							{
							case 1:
								this->ctrl.addEventToEventList(eventsInMonth[currentEvent]);
								cout<< "Event added" << endl;
								currentEvent += 1;
								if (currentEvent == eventsInMonth.getSize())
									currentEvent = 0;
								break;
							case 2:
								eventsInMonth[currentEvent].openEvent();
								break;
							case 3:
								currentEvent += 1;
								if (currentEvent == eventsInMonth.getSize())
									currentEvent = 0;
								break;
							default:
								break;
							}
						}
					}
				} 
				else if (commandMyEventList == 2) 
				{
					this->displayAllEventFromMyLibrary();
				}
				else if (commandMyEventList == 3)
				{
					int currentEvent = 0;
					while (true)
					{
						DynamicVector<Event> myEvents = this->ctrl.getEventList().getEvents();
						UI::displayEvent(myEvents[currentEvent]);
						UI::printMyEventManagementMenu();
						int commandEvent = 0;
						cout << "Input the command: ";
						cin >> commandEvent;
						cin.ignore();
						if (commandEvent == 0)
						{
							system("clear");
							break;
						}
						switch (commandEvent)
						{
						case 1:
							currentEvent += 1;
							if (currentEvent == myEvents.getSize())
								currentEvent = 0;
							break;
						case 2:
							this->ctrl.deleteEventFromMyLibrary(myEvents[currentEvent]);
							break;
						default:
							break;
						}
					}
				}
			}
		}

	}
}