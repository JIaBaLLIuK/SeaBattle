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


int InputIntValue(int, int);
void ResetGameField(char**);
void PrintGameField(char**);
void InputShipCoordinates(char**, int**);
void InputCurrentShipCoordinates(char**, int, int**);
bool CheckShipPosition(char**, int, int, int, int);
bool CheckCurrentCoordinates(char**, int, int);
void DrawShip(char**, int, int, int, int);
void RandomFieldGeneration(char**, int**);
void RandomShipGeneration(char**, int**, int);
void PlayerAttack(char**, char**, int**);
bool IsDestroyedShip(int**, int, int, int&);

// ��������� ������� ��� ���������� ������ ��� ��������� �������
template <typename type>
void MemoryAllocation(type*** array, int rowAmount, int columnAmount)
{
	(*array) = new type * [rowAmount];
	for (int i = 0; i < rowAmount; i++)
		(*array)[i] = new type[columnAmount];
}

#endif 
