#include <iostream>
#include "graph1.h"
#include "configuration.h"

Configuration::Configuration() {
	noChoices = 4;
	noQuestions = 10;
	noFlagNames = 224;
	string* flagNames = new string[224];
}
Configuration:: ~Configuration() {

	delete[] flagNames;
}
Configuration::Configuration(string* value, int noFlagNames) {
	flagNames = new string[noFlagNames];
	for (int i = 0; i < noFlagNames; ++i) {
		flagNames[i] = value[i];
	}
}
Configuration::Configuration(const Configuration& config) {
	flagNames = new string[noFlagNames];
	for (int i = 0; i < noFlagNames; ++i) {
		flagNames[i] = config.flagNames[i];
	}
}
bool Configuration::setNoChoices(int no_choices) {
	bool result = false;
	if (no_choices < 2) {
		noChoices = 2;
	}
	else if (no_choices > 6) {
		noChoices = 6;
	}
	else {
		noChoices = no_choices;
		result = true;
	}
	return result;

}
bool Configuration::setNoQuestions(int no_questions) {
	bool result = false;
	if (no_questions < 3) {
		noQuestions = 3;
	}
	else if (no_questions > 20) {
		noQuestions = 20;
	}
	else {
		noQuestions = no_questions;
		result = true;
	}
	return result;
}
void Configuration::setFlagNameAt(string flagName, int position) {
	if (position >= 0 && position < noFlagNames) {
		flagNames[position] = flagName;
	}

}
void Configuration::setNoFlagNames(int noFlagNames) {
	if (noFlagNames < 5) {
		this->noFlagNames = 5;
	}
	else if (noFlagNames > 224) {
		this->noFlagNames = 224;
	}
	else {
		this->noFlagNames = noFlagNames;
	}
}
string Configuration::getFlagNameAt(int index) {
		if (index >= 0 && index < noFlagNames) {
			return flagNames[index];
		}
}
string* Configuration::getAllFlagNames()
{
	return flagNames; 
}
int Configuration::getNoChoices() {
	return noChoices;
}
int Configuration::getNoQuestions() { 
	return noQuestions;
}
int Configuration::getNoFlagNames() { 
	return noFlagNames;
}



