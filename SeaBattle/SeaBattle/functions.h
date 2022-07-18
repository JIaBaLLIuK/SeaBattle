#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define SEA '~'
#define SHIP '#'
#define HIT 'X'
#define MISS 'O'
#define FIELD_SIZE 10
#define TOP 1
#define BOTTOM 2
#define LEFT 3
#define RIGHT 4
#define BATTLESHIP_SIZE 4
#define CRUISER_SIZE 3
#define DESTROYER_SIZE 2
#define BOAT_SIZE 1

#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

struct Ship
{
	int rowNumber;
	int columnNumber;
};

int InputIntValue(int, int);
void ResetGameField(char**);
void PrintGameField(char**);
void InputShipCoordinates(char**);
void InputCurrentShipCoordinates(char**, int);
bool CheckShipPosition(char**, int, int, int, int);
bool CheckCurrentCoordinates(char**, int, int);
void DrawShip(char**, int, int, int, int);
void RandomFieldGeneration(char**);

#endif 
