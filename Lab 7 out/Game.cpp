#include <iostream>
#include "graph1.h"
#include "Menu.h"
#include "Configuration.h"
#include "Game.h"
#include <ctime>
Game :: Game() {
	no_correct = 0;
}
void Game::setMenu(Menu menu) {
	this->menu = menu;
}

Menu Game::getMenu() {
	return menu;
}
int Game ::getNoCorrect() {
	return no_correct;
}
int Game::play() {
	srand(time(0));
	int random;
	random = rand() % 233 + 1;
	string flagName = menu.getConfig().getFlagNameAt(random);
	int addrandom;
	addrandom = rand() % 233 + 1;
	while (addrandom == random) {
		addrandom = rand() % 233 + 1;
	}
	string addFlagName = menu.getConfig().getFlagNameAt(addrandom);

	//step 5
	int correct_answer;
	for (int i = 0; i < menu.getConfig().getNoQuestions(); ++i) {
		// Choose random correct and incorrect options
		correct_answer = rand() % menu.getConfig().getNoFlagNames();
		menu.displayFlag(menu.getConfig().getFlagNameAt(correct_answer));
		int choice = menu.displayMenu();
		if (choice == correct_answer) {
			gout << setPos(200, 235 + (8 * menu.getConfig().getNoChoices() + 8)) << setColor(0, 255, 0) << "Correct!!!!" << endg;
		}
		else
		{
			gout << setPos(200, 235 + (8 * menu.getConfig().getNoChoices() + 8)) << setColor(0, 255, 0) << "INCORRECT!!!! - THE CORRECT ANSWER IS " << correct_answer << endg;
		}
	}
	menu.displayFlag(flagName);
	int userSelection;
	cout << "Enter the number corresponding to your choice: ";
	cin >> userSelection;
	menu.displayMenu();
	if (userSelection == correct_answer) {
		gout << setPos(200, 235 + (8 * menu.getConfig().getNoChoices() + 8)) << setColor(0, 255, 0) << "Correct!!!!" << endg;
		userSelection++;
	}
	else
	{
		gout << setPos(200, 235 + (8 * menu.getConfig().getNoChoices() + 8)) << setColor(0, 255, 0) << "INCORRECT!!!! - THE CORRECT ANSWER IS " << menu.getConfig().getFlagNameAt(random) << endg;
	}
	return userSelection;
}
