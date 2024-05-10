/*
final project MVCTC for computer coding and web applications junior year
*/
#include "personalLibv1.4.h"
#include "playerType.h"
int mainMenu();
void introduction();
char earth(playerType&);
char mars(playerType&);
char venus(playerType&);
char saturn(playerType&);
char moon(playerType&);
struct enemey {				//structure to create enemeys easily
	int health = 100;
	int damage = 10;
};
int main() {
	introduction();			//game intro
	playerType player;
	int choice = 0;
	char marsLetter = ' ';				//all needed vars to unlock final mission
	char venusLetter = ' ';
	char earthLetter = ' ';
	char saturnLetter = ' ';
	do {
		choice = mainMenu();
		switch (choice) {
		case 1: {
			int planetChoice = validateIntRange("\n1. MARS\n2. VENUS\n3. EARTH\n4. SATURN\n5. FINAL MISSION (unlocked by competing all other missions...)\nEnter your chocie: ", 1, 5);		//
			switch (planetChoice) {
			case 1: {
				system("cls");
				cout << "Flying to mars...";
				Sleep(2000);
				marsLetter = mars(player);
			}
			case 2: {
				system("cls");
				cout << "Flying to venus...";
				Sleep(2000);
				venusLetter = venus(player);
			}
			case 3: {
				system("cls");
				cout << "Flying to earth...";
				Sleep(2000);
				venusLetter = earth(player);
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
	cout << "In space, a lone ship cuts through the void. \nHis ship flying through space. \na bounty hunter.";
	cout << "\nflying through our solar system in an effort to chase bounty's to finally find the big bounty.";
}
char mars(playerType& player) {
	cout << "\nYou landed safely and exit your ship...";
	cout << "\nA compound lays ahead which holds the bounty your after...";
	cout << "\nYou break into the first door and there is a guard...";
	Sleep(8000);
	enemey grunt;
	while (grunt.health >= 0 || player.getHealth() >= 0) {
		if (grunt.health <= 0|| player.getHealth() <= 0) {
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
				Sleep(1000);
				grunt.health = grunt.health - player.getQuickDamageNumber();
			}
			break;
		}
		case 2: {
			if (attackSuccess <= 70) {
				cout << "\nATTACK LANDED....";
				Sleep(1000);
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
	if (saveDog == 0) {
		player.heal(50);
	}
	cout << "\nThe boss is much stronger then the grunt...";
	enemey boss;
	boss.health = 200;
	boss.damage = 20;
	while (boss.health > 0 || player.getHealth() > 0) {
		if (boss.health < 0 || player.getHealth() < 0) {
			break;
		}
		system("cls");
		cout << "\nEnemey attacking...";
		Sleep(1000);
		if (getRandom(1, 100) <= 90) {
			cout << "\nATTACK LANDED...";
			Sleep(1000);
			player.dealPlayerDamage(boss.damage);
		}
		if (boss.health < 0 || player.getHealth() < 0) {
			break;
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
				Sleep(1000);
				boss.health = boss.health - player.getQuickDamageNumber();
			}
			else {
				cout << "\nATTACK MISSED...";
				Sleep(1000);
			}
			break;
		}
		case 2: {
			if (attackSuccess <= 70) {
				cout << "\nATTACK LANDED....";
				Sleep(1000);
				boss.health = boss.health - player.getHeavyDamageNumber();
			}
			else {
				cout << "\nATTACK MISSED...";
				Sleep(1000);
			}
			break;
		}
		}
		if (saveDog == 1) {
			cout << "\nDOG DOES 50 DAMAGE....";
			Sleep(1000);
			boss.health = boss.health - 50;
			saveDog = 0;
		}
	}
	if (boss.health <= 0) {
		cout << "\nBoss is dead...\nFirst puzzle piece unlocked\n500$ added to your account...";
		player.addMoney(500);
		return 'M';
	}
	else {
		cout << "\nYOU DIED...\nMISSION FAILED... \nEXITING MISSION";
		return ' ';
	}
}
char venus(playerType& player) {
	cout << "\nYou landed safely and exit your ship...";
	cout << "\nA compound lays ahead which holds the bounty your after...";
	cout << "\nYou break into the first door and there is a huge guard, he is weaker then the last one but much harder to take down...";
	Sleep(8000);
	enemey grunt;
	grunt.health = 150;
	while (grunt.health >= 0 || player.getHealth() >= 0) {
		if (grunt.health <= 0 || player.getHealth() <= 0) {
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
				Sleep(1000);
				grunt.health = grunt.health - player.getQuickDamageNumber();
			}
			break;
		}
		case 2: {
			if (attackSuccess <= 70) {
				cout << "\nATTACK LANDED....";
				Sleep(1000);
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
	cout << "\nThere is an injured bear, you could take its med kit to heal yourself or leave it...";
	bool saveBear = static_cast<bool>(validateIntRange("\nEnter 1 to save it or 0 to take the 50 health for yourself...", 0, 1));
	if (saveBear == 0) {
		player.heal(50);
	}
	cout << "\nThis boss is much stronger then then the huge bodyguard...";
	enemey boss;
	boss.health = 300;
	boss.damage = 15;
	while (boss.health > 0 || player.getHealth() > 0) {
		if (boss.health < 0 || player.getHealth() < 0) {
			break;
		}
		system("cls");
		cout << "\nEnemey attacking...";
		Sleep(1000);
		if (getRandom(1, 100) <= 90) {
			cout << "\nATTACK LANDED...";
			Sleep(1000);
			player.dealPlayerDamage(boss.damage);
		}
		if (boss.health < 0 || player.getHealth() < 0) {
			break;
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
				Sleep(1000);
				boss.health = boss.health - player.getQuickDamageNumber();
			}
			else {
				cout << "\nATTACK MISSED...";
				Sleep(1000);
			}
			break;
		}
		case 2: {
			if (attackSuccess <= 70) {
				cout << "\nATTACK LANDED....";
				Sleep(1000);
				boss.health = boss.health - player.getHeavyDamageNumber();
			}
			else {
				cout << "\nATTACK MISSED...";
				Sleep(1000);
			}
			break;
		}
		}
		if (saveBear == 1) {
			cout << "\nBEAR DOES 200 DAMAGE....";
			Sleep(1000);
			boss.health = boss.health - 200;
			saveBear = 0;
		}
	}
	if (boss.health <= 0) {
		cout << "\nBoss is dead...\Second puzzle piece unlocked\n1000$ added to your account...";
		player.addMoney(1000);
		return 'O';
	}
	else {
		cout << "\nYOU DIED...\nMISSION FAILED... \nEXITING MISSION";
		return ' ';
	}
}
char earth(playerType& player) {
	cout << "\nYou landed safely and exit your ship...";
	cout << "\nA fortress lays ahead which holds the bounty your after...";
	cout << "\nYou break into the first door and there is a bear, he is strong but struggles to land attacks...";
	Sleep(8000);
	enemey grunt;
	grunt.health = 200;
	grunt.damage = 25;
	while (grunt.health >= 0 || player.getHealth() >= 0) {
		if (grunt.health <= 0 || player.getHealth() <= 0) {
			break;
		}
		system("cls");
		cout << "\nEnemey attacking...";
		Sleep(1000);
		if (getRandom(1, 100) <= 30) {
			cout << "\nATTACK LANDED...";
			player.dealPlayerDamage(grunt.damage);
			Sleep(1000);
		}
		else {
			cout << "\nENEMEY ATTACK MISSED...";
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
				Sleep(1000);
				grunt.health = grunt.health - player.getQuickDamageNumber();
			}
			else {
				cout << "\nYOUR ATTACK MISSED...";
			}
			break;
		}
		case 2: {
			if (attackSuccess <= 70) {
				cout << "\nATTACK LANDED....";
				Sleep(1000);
				grunt.health = grunt.health - player.getHeavyDamageNumber();
			}
			else {
				cout << "\nYOUR ATTACK MISSED...";
			}
			break;
		}


		}
	}
	if (grunt.health <= 0) {
		cout << "\nBear is dead...";
	}
	else {
		cout << "\nYOU DIED...\nMISSION FAILED... \nEXITING MISSION";
		return ' ';
	}

	cout << "\nYou contine ahead to see your bounty...";
	cout << "\nThere is an injured dog, you could take its med kit to heal yourself or leave it...";
	bool saveDog = static_cast<bool>(validateIntRange("\nEnter 1 to save it or 0 to take the 50 health for yourself...", 0, 1));
	if (saveDog == 0) {
		player.heal(50);
	}
	cout << "\nThis boss is much bigger than the bear however he's slower making his attacks rarely hit...";
	enemey boss;
	boss.health = 250;
	boss.damage = 35;
	while (boss.health > 0 || player.getHealth() > 0) {

		system("cls");
		cout << "\nEnemey attacking...";
		Sleep(1000);
		if (getRandom(1, 100) <= 90) {
			cout << "\nATTACK LANDED...";
			Sleep(1000);
			player.dealPlayerDamage(boss.damage);
		}
		if (boss.health < 0 || player.getHealth() < 0) {
			break;
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
				Sleep(1000);
				boss.health = boss.health - player.getQuickDamageNumber();
			}
			else {
				cout << "\nATTACK MISSED...";
				Sleep(1000);
			}
			break;
		}
		case 2: {
			if (attackSuccess <= 70) {
				cout << "\nATTACK LANDED....";
				Sleep(1000);
				boss.health = boss.health - player.getHeavyDamageNumber();
			}
			else {
				cout << "\nATTACK MISSED...";
				Sleep(1000);
			}
			break;
		}
		}
		if (saveDog == 1) {
			cout << "\nROBO DOG DOES 100 DAMAGE....";
			Sleep(1000);
			boss.health = boss.health - 100;
			saveDog = 0;
		}

	}
	if (boss.health <= 0) {
		cout << "\nBoss is dead...\nThird puzzle piece unlocked\n2000$ added to your account...";
		player.addMoney(2000);
		return 'O';
	}
	else {
		cout << "\nYOU DIED...\nMISSION FAILED... \nEXITING MISSION";
		return ' ';
	}
}
char saturn(playerType& player) {
	cout << "\nYou landed safely and exit your ship...";
	cout << "\nA fortress lays ahead which holds the bounty your after...";
	cout << "\nYou break into the first door and there is a bear, he is strong but struggles to land attacks...";
	Sleep(8000);
	enemey grunt;
	grunt.health = 200;
	grunt.damage = 25;
	while (grunt.health >= 0 || player.getHealth() >= 0) {
		if (grunt.health <= 0 || player.getHealth() <= 0) {
			break;
		}
		system("cls");
		cout << "\nEnemey attacking...";
		Sleep(1000);
		if (getRandom(1, 100) <= 30) {
			cout << "\nATTACK LANDED...";
			player.dealPlayerDamage(grunt.damage);
			Sleep(1000);
		}
		else {
			cout << "\nENEMEY ATTACK MISSED...";
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
				Sleep(1000);
				grunt.health = grunt.health - player.getQuickDamageNumber();
			}
			else {
				cout << "\nYOUR ATTACK MISSED...";
			}
			break;
		}
		case 2: {
			if (attackSuccess <= 70) {
				cout << "\nATTACK LANDED....";
				Sleep(1000);
				grunt.health = grunt.health - player.getHeavyDamageNumber();
			}
			else {
				cout << "\nYOUR ATTACK MISSED...";
			}
			break;
		}


		}
	}
	if (grunt.health <= 0) {
		cout << "\nBear is dead...";
	}
	else {
		cout << "\nYOU DIED...\nMISSION FAILED... \nEXITING MISSION";
		return ' ';
	}

	cout << "\nYou contine ahead to see your bounty...";
	cout << "\nThere is an injured dog, you could take its med kit to heal yourself or leave it...";
	bool saveDog = static_cast<bool>(validateIntRange("\nEnter 1 to save it or 0 to take the 50 health for yourself...", 0, 1));
	if (saveDog == 0) {
		player.heal(50);
	}
	cout << "\nThis boss is much bigger than the bear however he's slower making his attacks rarely hit...";
	enemey boss;
	boss.health = 250;
	boss.damage = 35;
	while (boss.health > 0 || player.getHealth() > 0) {

		system("cls");
		cout << "\nEnemey attacking...";
		Sleep(1000);
		if (getRandom(1, 100) <= 90) {
			cout << "\nATTACK LANDED...";
			Sleep(1000);
			player.dealPlayerDamage(boss.damage);
		}
		if (boss.health < 0 || player.getHealth() < 0) {
			break;
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
				Sleep(1000);
				boss.health = boss.health - player.getQuickDamageNumber();
			}
			else {
				cout << "\nATTACK MISSED...";
				Sleep(1000);
			}
			break;
		}
		case 2: {
			if (attackSuccess <= 70) {
				cout << "\nATTACK LANDED....";
				Sleep(1000);
				boss.health = boss.health - player.getHeavyDamageNumber();
			}
			else {
				cout << "\nATTACK MISSED...";
				Sleep(1000);
			}
			break;
		}
		}
		if (saveDog == 1) {
			cout << "\nROBO DOG DOES 100 DAMAGE....";
			Sleep(1000);
			boss.health = boss.health - 100;
			saveDog = 0;
		}

	}
	if (boss.health <= 0) {
		cout << "\nBoss is dead...\nThird puzzle piece unlocked\n2000$ added to your account...";
		player.addMoney(2000);
		return 'N';
	}
	else {
		cout << "\nYOU DIED...\nMISSION FAILED... \nEXITING MISSION";
		return ' ';
	}
}
char moon(playerType& player) {
	cout << "\nYou landed safely and exit your ship...";
	cout << "\nA moon base lays ahead which holds the final bounty your after...";
	cout << "\nYou break into the first door and there is a special enemey who can do crit damage, he is strong...";
	Sleep(8000);
	enemey grunt;
	grunt.health = 200;
	grunt.damage = 25;
	while (grunt.health >= 0 || player.getHealth() >= 0) {
		if (grunt.health <= 0 || player.getHealth() <= 0) {
			break;
		}
		system("cls");
		cout << "\nEnemey attacking...";
		Sleep(1000);
		if (getRandom(1, 100) <= 30) {
			cout << "\nATTACK LANDED...";
			player.dealPlayerDamage(grunt.damage);
			Sleep(1000);
		}
		else {
			cout << "\nENEMEY ATTACK MISSED...";
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
				Sleep(1000);
				grunt.health = grunt.health - player.getQuickDamageNumber();
			}
			else {
				cout << "\nYOUR ATTACK MISSED...";
			}
			break;
		}
		case 2: {
			if (attackSuccess <= 70) {
				cout << "\nATTACK LANDED....";
				Sleep(1000);
				grunt.health = grunt.health - player.getHeavyDamageNumber();
			}
			else {
				cout << "\nYOUR ATTACK MISSED...";
			}
			break;
		}


		}
	}
	if (grunt.health <= 0) {
		cout << "\nBear is dead...";
	}
	else {
		cout << "\nYOU DIED...\nMISSION FAILED... \nEXITING MISSION";
		return ' ';
	}

	cout << "\nYou contine ahead to see your bounty...";
	cout << "\nThere is an injured dog, you could take its med kit to heal yourself or leave it...";
	bool saveDog = static_cast<bool>(validateIntRange("\nEnter 1 to save it or 0 to take the 50 health for yourself...", 0, 1));
	if (saveDog == 0) {
		player.heal(50);
	}
	cout << "\nThis boss is much bigger than the bear however he's slower making his attacks rarely hit...";
	enemey boss;
	boss.health = 250;
	boss.damage = 35;
	while (boss.health > 0 || player.getHealth() > 0) {

		system("cls");
		cout << "\nEnemey attacking...";
		Sleep(1000);
		if (getRandom(1, 100) <= 90) {
			cout << "\nATTACK LANDED...";
			Sleep(1000);
			player.dealPlayerDamage(boss.damage);
		}
		if (boss.health < 0 || player.getHealth() < 0) {
			break;
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
				Sleep(1000);
				boss.health = boss.health - player.getQuickDamageNumber();
			}
			else {
				cout << "\nATTACK MISSED...";
				Sleep(1000);
			}
			break;
		}
		case 2: {
			if (attackSuccess <= 70) {
				cout << "\nATTACK LANDED....";
				Sleep(1000);
				boss.health = boss.health - player.getHeavyDamageNumber();
			}
			else {
				cout << "\nATTACK MISSED...";
				Sleep(1000);
			}
			break;
		}
		}
		if (saveDog == 1) {
			cout << "\nROBO DOG DOES 100 DAMAGE....";
			Sleep(1000);
			boss.health = boss.health - 100;
			saveDog = 0;
		}

	}
	if (boss.health <= 0) {
		cout << "\nBoss is dead...\nThird puzzle piece unlocked\n2000$ added to your account...";
		player.addMoney(2000);
		return 'O';
	}
	else {
		cout << "\nYOU DIED...\nMISSION FAILED...\nEXITING MISSION";
		return ' ';
	}
}	