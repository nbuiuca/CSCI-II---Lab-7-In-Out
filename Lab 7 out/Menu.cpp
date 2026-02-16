#include <iostream>
#include "graph1.h"
#include "Menu.h"
#include "Configuration.h"

Menu::Menu() {
	choices = NULL;
	selection = 0;
}
Menu:: ~Menu() {
	delete[] choices;
}
Menu :: Menu(const Menu& menu) {
	choices = new string [config.getNoChoices()];
	for (int i = 0; i < config.getNoChoices(); i++) {
		choices[i] = menu.choices[i];
	}
}
void Menu::setConfig(Configuration config) {
	this->config = config;
	choices = new string[config.getNoChoices()];
}
void Menu::setSelection(int selection) {
	this->selection = selection;
}
void Menu::setChoice(int index, string flag_name) {
	choices[index] = flag_name;
}
string Menu::getChoice(int index) {
	return choices[index];
}
int Menu::getSelection() {
	return selection;
}
Configuration Menu::getConfig() {
	return config;
}
int Menu::displayMenu() {
	int i = 0;
	int y = 235;
	int color;
	int y1 = 238;
	for (i; i < config.getNoQuestions(); i++) {
		gout << setPos(200,30) << setColor(0, 255, 0) << "Question #" << i+1 << endg;
		gout << setPos(200, 220) << setColor(0, 255, 0) << "Choose from the following: " << endg;
		for (int j = 0; j < config.getNoChoices(); j++) {
			color = drawRect(200, y, 300, 200);
			y += 8;
			setColor(color, 80, 200, 130);
			gout << setPos(200, y1) << setColor(0, 255, 0) << j+1 << choices[i] << endg;
			y1 += 8;
		}
	}
	return selection;
}
void Menu::displayFlag(string flag_name) {
	for (int i = 0; i < config.getNoQuestions(); i++) {
		displayBMP(flag_name +".BMP", 200, 50);
	}
}
