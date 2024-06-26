/*
final project MVCTC for computer coding and web applications junior year
most of the documentation for the code for the missions is in the mars as I am on a time crunch and do not want to spend 45 minutes commeneting everything 
all thats different is the wording in the output and health of enemeys, moon is differenet there will be documentation there tho
*/
#include "personalLibv1.4.h"
#include "playerType.h"
#include "specialEnemey.h"
#include "specialBoss.h"
int mainMenu();
void introduction();
char earth(playerType&);
char mars(playerType&);
char venus(playerType&);
char saturn(playerType&);
void moon(playerType&);
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
			cin.clear();
			int planetChoice = validateIntRange("\n1. MARS\n2. VENUS\n3. EARTH\n4. SATURN\n5. FINAL MISSION (unlocked by competing all other missions...\n6. Exit...)\nEnter your chocie: ", 1, 6);		//sub menu for planets
			switch (planetChoice) {
			case 1: {
				system("cls");
				cout << "Flying to mars...";
				Sleep(2000);
				marsLetter = mars(player);
				cin.clear();
				break;
			}
			case 2: {
				system("cls");
				cout << "Flying to venus...";
				Sleep(2000);
				venusLetter = venus(player);
				break;
			}
			case 3: {
				system("cls");
				cout << "Flying to earth...";
				Sleep(2000);
				earthLetter = earth(player);
				break;
			}
			case 4: {
				system("cls");
				cout << "Flying to saturn...";
				Sleep(2000);
				saturnLetter = earth(player);
				break;
			}
			case 5: {
				system("cls");
				cout << "Flying to the moon...";
				Sleep(2000);
				if (marsLetter == 'M' && venusLetter == 'O' && earthLetter == 'O' && saturnLetter == 'N'){

				}
				if (player.getKeyWord() == "MOON") {
					moon(player);

				}	
				break;
			}
			case 6: {
				cout << "\nExiting...";
				break;
			}
			}
			
			break;
		}
		case 2: {
			cout << "\nDakota's shop\n1. 100$ 10 health\n2. 200$ 25 health\n3. 400$ 60 health\n 4. Exit";
			int shopChoice = 0;
			shopChoice = validateIntRange("\nEnter your choice: ", 1, 4);
			switch (shopChoice) {
			case 1: {
				if (player.getCurrency() >= 100) {
					player.removeMoney(100);
					player.heal(10);
					cout << "\nHEALED..\nHEALTH: " << player.getHealth();
				}
				else {
					cout << "\nNOT ENOUGH MONEY....";
				}
				break;
			}
			case 2: {
				if (player.getCurrency() >= 200) {
					player.removeMoney(200);
					player.heal(25);
					cout << "\nHEALED..\nHEALTH: " << player.getHealth();
				}
				else {
					cout << "\nNOT ENOUGH MONEY....";
				}
				break;
			}
			case 3: {
				if (player.getCurrency() >= 400) {
					player.removeMoney(400);
					player.heal(60);
					cout << "\nHEALED..\nHEALTH: " << player.getHealth();
				}
				else {
					cout << "\nNOT ENOUGH MONEY....";
				}
				break;
			}
			case 4:{
				cout << "\nExiting...";
				break;
			}

			


			}
			
		}
		case 3: {
			player.saveGame();				//save system in a binary file
			break;
		}
		case 4: {
			player.loadGame();				//load system in a binary file
			break;
		}
		case 5: {
			cout << "\nWORK IN PROGRESS...";
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
}		//main menu system
void introduction() {

	cout << "\nYou are a bounty hunter going planet after plant to get to your final bounty";

}		//intro to game
char mars(playerType& player) {
	cout << "\nYou landed safely and exit your ship...";
	cout << "\nA compound lays ahead which holds the bounty your after...";				//intro to mars
	cout << "\nYou break into the first door and there is a guard...";
	Sleep(8000);
	enemey grunt;
	while (grunt.health >= 0 || player.getHealth() >= 0) {
		if (grunt.health <= 0|| player.getHealth() <= 0) {			//grunt attack, sort of tutorial
			break;
		}
		system("cls");
		cout << "\nEnemey attacking...";
		Sleep(1000);
		if (getRandom(1, 100) <= 90) {				//attack system used random gened numbers to figure out probability of hitting, used in all attacks
			cout << "\nATTACK LANDED...";
			player.dealPlayerDamage(grunt.damage);
			Sleep(1000);
		}
		cout << "\nYour health: " << player.getHealth();			//battle info
		cout << "\nEnemeys health: " << grunt.health;
		cout << "\nYour options: ";
		cout << "\n1. Quick attack (90% success rate)";
		cout << "\n2. Heavy attack (70% success rate)";
		int attackSuccess = getRandom(1, 100);
		int choice = validateIntRange("\nEnter your choice: ", 1, 2);
		switch (choice) {
		case 1: {
			if (attackSuccess <= 90) {							//switch to do attacking
				cout << "\nATTACK LANDED....";
				Sleep(1000);
				grunt.health = grunt.health - player.getQuickDamageNumber();
			}
			break;
		}
		case 2: {
			if (attackSuccess <= 70) {				//heavy attack info
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
	player.saveGame();
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
		player.saveGame();
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
	player.saveGame();
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
		player.saveGame();
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
	player.saveGame();
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
		player.saveGame();
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
	player.saveGame();
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
		player.saveGame();
		return 'N';
	}
	else {
		cout << "\nYOU DIED...\nMISSION FAILED... \nEXITING MISSION";
		return ' ';
	}
}
//final mission, used classes in this mision to add some stuff
void moon(playerType& player) {
	player.saveGame();
	cout << "\nYou landed safely and exit your ship...";
	cout << "\nA moon base is ahead...";
	cout << "\nYou break into the first door and there is a special enemey who can do crit damage, he is strong...";
	Sleep(8000);
	specialEnemey grunt;
	while (grunt.getHealth() >= 0 || player.getHealth() >= 0) {
		if (grunt.getHealth() <= 0 || player.getHealth() <= 0) {
			break;
		}
		system("cls");
		cout << "\nEnemey attacking...";
		Sleep(1000);
		if (getRandom(1, 100) <= grunt.getCritChance()) {
			player.dealPlayerDamage(grunt.getcritDamage());			//crit damage system
			cout << "\nCRIT ATTACK LANDED....";
			Sleep(1000);
		}
		else if (getRandom(1, 100) <= 30) {
			cout << "\nATTACK LANDED...";
			player.dealPlayerDamage(grunt.getDamage());
			Sleep(1000);
		}
		else {
			cout << "\nENEMEY ATTACK MISSED...";
		}
		cout << "\nYour health: " << player.getHealth();
		cout << "\nEnemeys health: " << grunt.getHealth();
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
				grunt.dealDamage(player.getQuickDamageNumber());
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
				grunt.dealDamage(player.getHeavyDamageNumber());
			}
			else {
				cout << "\nYOUR ATTACK MISSED...";
			}
			break;
		}


		}
	}
	if (grunt.getHealth() <= 0) {
		cout << "\nEnemey is dead...";
	}
	else {
		cout << "\nYOU DIED...\nMISSION FAILED... \nEXITING MISSION";
	
	}

	cout << "\nYou contine ahead to see your bounty...";
	cout << "\nThere is an injured robot bear, you could take its med kit to heal yourself or leave it...";
	bool saveDog = static_cast<bool>(validateIntRange("\nEnter 1 to save it or 0 to take the 100 health for yourself...", 0, 1));
	if (saveDog == 0) {
		player.heal(100);
	}
	player.saveGame();
	cout << "\nThis boss is much harder and can self heal along with landing critical attacks...";
	specialBoss boss;
	while (boss.getHealth() > 0 || player.getHealth() > 0) {

		system("cls");
		cout << "\nEnemey attacking...";
		Sleep(1000);
		if (getRandom(1, 100) <= boss.getCritChance()) {
			player.dealPlayerDamage(boss.getcritDamage());
			cout << "\nCRIT ATTACK LANDED....";
			Sleep(1000);
		}
		else if (getRandom(1, 100) <= 90) {
			cout << "\nATTACK LANDED...";
			Sleep(1000);
			player.dealPlayerDamage(boss.getDamage());
		}
		else {
			cout << "\nATTACK MISSED....";
		}
		if (boss.getHealth() < 0 || player.getHealth() < 0) {
			break;
		}
		cout << "\nYour health: " << player.getHealth();
		cout << "\nEnemeys health: " << boss.getHealth();
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
				boss.dealDamage(player.getQuickDamageNumber());
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
				boss.dealDamage(player.getHeavyDamageNumber());
			}
			else {
				cout << "\nATTACK MISSED...";
				Sleep(1000);
			}
			break;
		}
		}
		if (saveDog == 1) {
			cout << "\nROBO BEAR DOES 100 DAMAGE....";
			Sleep(1000);
			boss.dealDamage(150);
			saveDog = 0;
		}
		if (getRandom(1, 100) < boss.getSelfHealChance()) {
			cout << "\nBOSS SELF HEALS...";
			boss.healBoss(boss.getSelfHealAmount());
		}

	}
	if (boss.getHealth() <= 0) {
		cout << "\nBoss is dead...\nFinal Mission completed...\n20000$ added to your account...";
		player.addMoney(20000);
		player.saveGame();
	
	}
	else {
		cout << "\nYOU DIED...\nMISSION FAILED...\nEXITING MISSION";
	
	}
}	

