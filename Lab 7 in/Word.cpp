//Nhan Bui
//Lab 7 in
#include <iostream>
#include "graph1.h"|
#include "Word.h"



Word::Word() {
	word = "";
	x = NULL;
	y = NULL;
}
Word :: ~Word() {
	delete[]x;
	delete[]y;
}

//Copy Constructor
Word::Word(const Word& word) {
	int i = 0;
	//getting the length of the word data member of the word object.
	int size = (int)word.word.length();
	this->x = new int[size];
	this->y = new int[size];
	//setting the word data member of this object to the value of the word data member
	this->word = word.word;
	// make a copy of the array
	for (i = 0; i < size; i++)
	{
		this->x[i] = word.x[i];
		this->y[i] = word.y[i];
	}
}
void Word::setWord(string word) {
	this->word = word;
}
string Word::getWord() {
	return word;	
}
void Word::setCoords(int x_val, int y_val) {
	x = new int[(int)word.length()];
	y = new int[(int)word.length()];
	for (int i = 0; i < (int)word.length(); i++) {
		x[i] = x_val + (i * 32);
		y[i] = y_val;
	}
}
void Word::draw() {
	string fn;
	string bmp = ".bmp";
	for (int i = 0; i < (int)word.length(); i++)
	{
		//referencing the characters in the word data member string
		fn = this->word[i] + bmp;
		//getting the reference of the string and then get the value by calling the first element of the string;
		displayBMP(fn, this->x[i], this->y[i]);
	}
}