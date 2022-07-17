#include "functions.h"
// функция сброса поля
void ResetGameField(char** gameField)
{
	for (int i = 0; i < FIELD_SIZE; i++)
		for (int j = 0; j < FIELD_SIZE; j++)
			gameField[i][j] = SEA;
}
// функция отображения поля на экране
void PrintGameField(char**gameField)
{
	for (int i = 1; i <= FIELD_SIZE; i++)
		cout << "   " << i;
	int asciiCode = 65;
	cout << "\n |---|---|---|---|---|---|---|---|---|---|" << endl;
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			if (j == 0)
				cout << (char)asciiCode++;
			cout << "| " << gameField[i][j] << " ";
			if (j == FIELD_SIZE - 1)
				cout << "|" << endl;
		}
		cout << " |---|---|---|---|---|---|---|---|---|---|" << endl;
	}
}

