/*
finished with all my school work and have like 3 weeks left so i am making a game
*/
#include "personalLibv1.4.h"
int mainMenu();
int main() {
	int choice = 0;
	do {
		validateInt("TEST: ");





	} while (choice != 6);
	endProgram();
}
int mainMenu() {
	int choice = 0;
	cout << "\n1. Planet select";
	cout << "\n2. Shop";
	cout << "\n3. Save game";
	cout << "\n4. Load save";
	cout << "\n5. Settings";
	cout << "\n6. Exit";


	return choice;
}