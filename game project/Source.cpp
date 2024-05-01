/*
finished with all my school work and have like 3 weeks left so i am making a game
*/
#include "personalLibv1.4.h"
int mainMenu();
void introduction();

int main() {
	introduction();
	int choice = 0;
	do {
		switch (choice) {
		case 1: {

		}
		case 2: {

		}
		case 3: {


		}
		case 4: {

		}
		case 5: {

		}
		case 6: {
			cout << "\nThank you for playing";
		}



		}

	} while (choice != 6);
	endProgram();
}
int mainMenu() {
	int choice = 0;
	cout << "\n1. Planet select";
	cout << "\n2. Shops";
	cout << "\n3. Save game";
	cout << "\n4. Load save";
	cout << "\n5. Settings";
	cout << "\n6. Exit";


	return choice;
}
void introduction() {
	cout << "In space, a lone figure cuts through the void. \nHis ship slicing through the darkness like a blade through silk. \nHis name is Spike, a bounty hunter with a past unknown.";
	cout << "\nWith a flicker of his cigarette and a glint in his eye, Spike navigates his ship, the Bebop, through the highways of our solar system in an effort to claim bountys.";


}