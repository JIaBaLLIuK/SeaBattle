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
bool PlayerAttack(char**, char**, int**, int);
bool IsDestroyedShip(int**, int, int, int&, char**, char**);
void ShipPlacementMenu(char**, int**);
bool IsWinner(char**);
void DrawAroundShip(char**, char**, int, int, int, int);

// шаблонная функция для выделение памяти под двумерные массивы
template <typename type>
void MemoryAllocation(type*** array, int rowAmount, int columnAmount)
{
	(*array) = new type * [rowAmount];
	for (int i = 0; i < rowAmount; i++)
		(*array)[i] = new type[columnAmount];
}
// шаблонная функция для удаления двумерных массивов
template <typename type>
void MemoryDelete(type*** array, int rowAmount, int columnAmount)
{
	for (int i = 0; i < rowAmount; i++)
		delete[](*array)[i];
	delete[](*array);
}

#endif 
