#include "event.hpp"
#include "ui.hpp"

using namespace std;

int main()
{
	system("color f4");

	Repository repo = Repository();

	// add some songs
	Event e1 = Event("Ed Sheeran", "I see fire", DateTime(2020, 3, 21, 12, 4, 54), 0, "https://www.youtube.com/watch?v=2fngvQS_PmQ");
	Event e2 = Event("Two Steps From Hell", "Heart of Courage", DateTime(2020, 3, 21, 12, 8, 12), 0, "https://www.youtube.com/watch?v=XYKUeZQbMF0");
	Event e3 = Event("Pink Martini", "Splendour in the Grass", DateTime(2020, 3, 21, 12, 3, 47), 0, "https://www.youtube.com/watch?v=6L-_DiZlrUI");
	Event e4 = Event("Jaron", "Splendour in the Grass", DateTime(2020, 2, 21, 12, 3, 47), 0, "https://www.youtube.com/watch?v=6L-_DiZlrUI");
	repo.add(e1);
	repo.add(e2);
	repo.add(e3);
	repo.add(e4);

	Controller ctrl = Controller(repo);
	UI ui = UI(ctrl);
	ui.run();

	return 0;
}