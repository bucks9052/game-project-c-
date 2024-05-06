/*
finished with all my school work and have like 3 weeks left so i am making a game
*/
#include "personalLibv1.4.h"
#include "npcShop.h"
#include "playerType.h"
int mainMenu();
void introduction();
struct enemey {
	int health = 0;
	int damage = 0;
};
int main() {
	introduction();
	int choice = 0;

	do {
		choice = mainMenu();
		switch (choice) {
		case 1: {
			
			break;
		}
		case 2: {


			break;
		}
		case 3: {

			break;
		}
		case 4: {



			break;
		}
		case 5: {


			break;
		}
		case 6: {
			cout << "\nThank you for playing...;.";
			break;
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
	choice = validateIntRange("\nEnter your choice: ", 1, 6);
	
	return choice;
}
void introduction() {
	cout << "In space, a lone ship cuts through the void. \nHis ship flying through space. \nHe is a bounty hunter.";
	cout << "\nSpike navigates his ship, the Bebop, through the highways of our solar system in an effort to chase bounty's to finally find the big bounty.";
}
int dealDamage(int targetHealth, int damageDealt) {
	int health = targetHealth - damageDealt;
	if (health == 0) {
		cout << "\nYOU DIED....";
	}
	return health;
}
char mars(playerType player) {
	cout << "\nYou landed safely and exit your ship...";
	cout << "\nA compound lays ahead which holds the bounty your after...";



}