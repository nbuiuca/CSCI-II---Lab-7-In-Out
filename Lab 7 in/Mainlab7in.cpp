//NhanBui
//Lab 7 in
#include "Word.h"
#include "graph1.h"
#include <iostream>
#include <string>
using namespace std;
void reverseWord(Word copy, int x_val, int y_val);
int main() {
	//variable declaration
	string input;
	int x = 0;
	int y = 0;
	char repeat;
	Word word;
	displayGraphics();
	do {
		//2.Prompt the user for the word to be displayed..
		cout << "Enter Word to be displayed: ";
		cin >> input;
		cout << endl;
	//	3. Prompt the user for the starting x / y coords
		cout << "enter starting X and Y coords: ";
		cin >> x >> y;
		//4. Invoke setWord method that sets the private data field word.
		word.setWord(input);
		//5.Invoke the setCoords method using the starting x / y coordinate.All other coordinates will be set within the x / y arrays by this initial coordinate
		word.setCoords(x, y);
		//6. Invoke the draw method that displays the alphabetic images corresponding to the letters of the entered word.The letters will be displayed based on the coordinates stored in the x / y arrays.
		word.draw();
		//7. 3 secs delay
		Sleep(3000);
		//8. Invoke the reverseWord independent function to reverse the original word.The Word object is passed by value invoking the Copy Constructor.
		reverseWord(word, x, y);
		//9. Invoke 2nd time to verify if the copy constructor is implemented
		//reverseWord(word, x, y);
		//10. repeat program
		cout << "Repeat Program?(y/n)";
		cin >> repeat;
	} while (tolower(repeat) == 'y');

	return 0;
}
void reverseWord(Word copy, int x_val, int y_val) {
	int i = 0;
	int length = (int)copy.getWord().length();
	string rWord = copy.getWord();
	//Create a string that stores a manipulate value of the word;
	string temp = rWord;
	string fn;
	string bmp = ".bmp";
	for (i = 0; i < length; i++)
	{
		//gets the last values of word and stores those last characters in rWord string.
		rWord[i] = temp[length - i - 1];
	}
	//display reverse wird
	for (i = 0; i < length; i++) {
		fn = rWord[i] + bmp;
		displayBMP(&fn[0], x_val + (i * 32), y_val);
	}
}