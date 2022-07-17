#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define SEA '`'
#define SHIP 'O'
#define HIT '@'
#define MISS 'X'
#define FIELD_SIZE 10

#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

struct Ship
{
	int rowNumber;
	int columnNumber;
};

void ResetGameField(char**);
void PrintGameField(char**);

#endif 

