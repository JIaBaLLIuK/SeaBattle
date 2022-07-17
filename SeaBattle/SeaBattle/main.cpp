#include "functions.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char** firstPlayerGameField = new char* [FIELD_SIZE];  // поле первого игрока
	for (int i = 0; i < FIELD_SIZE; i++)
		firstPlayerGameField[i] = new char[FIELD_SIZE];
	char** secondPlayerGameField = new char* [FIELD_SIZE];  // поле второго игрока
	for (int i = 0; i < FIELD_SIZE; i++)
		secondPlayerGameField[i] = new char[FIELD_SIZE];
	ResetGameField(firstPlayerGameField);
	PrintGameField(firstPlayerGameField);

	system("pause");
	return 0;
}