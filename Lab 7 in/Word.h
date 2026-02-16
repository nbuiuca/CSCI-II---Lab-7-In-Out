#pragma once

#ifndef WORD_H
#define WORD_H
#include <iostream>
#include "graph1.h"
class Word
{
private:
    string word;
    int* x; //x-coords
    int* y; //y-coords


public:
    Word();
    ~Word();
    Word(const Word& word); //Copy Constructor
    void setWord(string word);
    void  setCoords(int x_val, int y_val);
    string getWord();
    void draw();
};

#endif
