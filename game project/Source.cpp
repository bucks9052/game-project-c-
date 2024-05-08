/*
final project MVCTC for computer coding and web applications junior year
*/
#include "npcShop.h"
#include "personalLibv1.4.h"
#include "playerType.h"
int mainMenu();
void introduction();
char mars(playerType player);
struct enemey {				//structure to create enemeys easily
	int health = 100;
	int damage = 10;
};
int main() {
	introduction();
	playerType player;
	int choice = 0;
	char marsLetter = ' ';
	char venusLetter = ' ';
	char earthLetter = ' ';
	char saturnLetter = ' ';
	do {
		choice = mainMenu();
		switch (choice) {
		case 1: {
			int planetChoice = validateIntRange("\n1. MARS\n2. VENUS\n3. EARTH\n4. SATURN\n5. FINAL MISSION (unlocked by competing all other missions...)", 1, 5);
			switch (planetChoice) {
			case 1: {
				system("cls");
				cout << "Flying to mars...";
				Sleep(2000);
				marsLetter = mars(player);
			}
				  
			}
			
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

char mars(playerType player) {
	cout << "\nYou landed safely and exit your ship...";
	cout << "\nA compound lays ahead which holds the bounty your after...";
	cout << "\nYou break into the first door and there is a guard...";
	Sleep(8000);
	enemey grunt;
	while (grunt.health > 0 || player.getHealth() > 0) {
		if (grunt.health < 0|| player.getHealth() < 0) {
			break;
		}
		system("cls");
		cout << "\nEnemey attacking...";
		Sleep(1000);
		if (getRandom(1, 100) <= 90) {
			cout << "\nATTACK LANDED...";
			player.dealPlayerDamage(grunt.damage);
			Sleep(1000);
		}
		cout << "\nYour health: " << player.getHealth();
		cout << "\nEnemeys health: " << grunt.health;
		cout << "\nYour options: ";
		cout << "\n1. Quick attack (90% success rate)";
		cout << "\n2. Heavy attack (70% success rate)";
		int attackSuccess = getRandom(1, 100);
		int choice = validateIntRange("\nEnter your choice: ", 1, 2);
		switch (choice) {
		case 1: {
			if (attackSuccess <= 90) {
				cout << "\nATTACK LANDED....";
				grunt.health = grunt.health - player.getQuickDamageNumber();
			}
			break;
		}
		case 2: {
			if (attackSuccess <= 70) {
				cout << "\nATTACK LANDED....";
				grunt.health = grunt.health - player.getHeavyDamageNumber();
			}
			break;
		}


		}
	}
	if (grunt.health <= 0) {
		cout << "\nGrunt is dead...";
	}
	else {
		cout << "\nYOU DIED...\nMISSION FAILED... \nEXITING MISSION";
		return ' ';
	}
	cout << "\nYou contine ahead to see your bounty...";
	cout << "\nThere is an injured dog, you could take its med kit to heal yourself or leave it...";
	bool saveDog = static_cast<bool>(validateIntRange("\nEnter 1 to save it or 0 to take the 50 health for yourself...", 0, 1));
	cout << "\nThe boss is much stronger then the grunt...";
	enemey boss;
	boss.health = 200;
	boss.damage = 20;
	while (boss.health <= 0 || player.getHealth() <= 0) {
		if (boss.health < 0 || player.getHealth() < 0) {
			break;
		}
		system("cls");
		cout << "\nEnemey attacking...";
		if (getRandom(1, 100) <= 90) {
			cout << "\nATTACK LANDED...";
			player.dealPlayerDamage(boss.damage);
		}
		cout << "\nYour health: " << player.getHealth();
		cout << "\nEnemeys health: " << boss.health;
		cout << "\nYour options: ";
		cout << "\n1. Quick attack (90% success rate)";
		cout << "\n2. Heavy attack (70% success rate)";
		int attackSuccess = getRandom(1, 100);
		int choice = validateIntRange("\nEnter your choice: ", 1, 2);
		switch (choice) {
		case 1: {
			if (attackSuccess <= 90) {
				cout << "\nATTACK LANDED....";
				boss.health = boss.health - player.getQuickDamageNumber();
			}
			else {
				cout << "\nATTACK MISSED...";
			}
			break;
		}
		case 2: {
			if (attackSuccess <= 70) {
				cout << "\nATTACK LANDED....";
				boss.health = boss.health - player.getHeavyDamageNumber();
			}
			else {
				cout << "\nATTACK MISSED...";
			}
			break;
		}
		}
		if (saveDog == 1) {
			cout << "\nDOG DOES 50 DAMAGE....";
			boss.health = boss.health - 50;
			saveDog = 0;
		}
	}
	if (boss.health <= 0) {
		cout << "\nBoss is dead...\nFirst puzzle piece unlocked\n 500$ added to your account...";
		return 'M';
	}
	else {
		cout << "\nYOU DIED...\nMISSION FAILED... \nEXITING MISSION";
		return ' ';
	}
}