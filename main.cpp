#include "event.hpp"
#include "ui.hpp"

using namespace std;

int main()
{

	Repository repo = Repository();

	Event e1 = Event("Trip to Dubai", "some des", DateTime(2020, 3, 21, 12, 4, 54), 0, "https://www.youtube.com/watch?v=2fngvQS_PmQ");
	Event e2 = Event("Devs talk", "some devs that are talking", DateTime(2020, 3, 21, 12, 8, 12), 0, "https://www.youtube.com/watch?v=XYKUeZQbMF0");
	Event e3 = Event("Concerte", "music", DateTime(2020, 3, 21, 12, 3, 47), 0, "https://www.youtube.com/watch?v=6L-_DiZlrUI");
	Event e4 = Event("Private Event", "private party", DateTime(2020, 2, 21, 12, 3, 47), 0, "https://www.youtube.com/watch?v=6L-_DiZlrUI");
	repo.add(e1);
	repo.add(e2);
	repo.add(e3);
	repo.add(e4);

	Controller ctrl = Controller(repo);
	UI ui = UI(ctrl);
	ui.run();

	return 0;
}