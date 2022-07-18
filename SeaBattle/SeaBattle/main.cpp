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
	cout << "Пустое игровое поле имеет вид:" << endl;
	PrintGameField(firstPlayerGameField);
	InputShipCoordinates(firstPlayerGameField);
	/*RandomFieldGeneration(firstPlayerGameField);
	cout << "Случайное игровое поле имеет вид : " << endl;
	PrintGameField(firstPlayerGameField);*/


	for (int i = 0; i < FIELD_SIZE; i++)
		delete[]firstPlayerGameField[i];
	delete[]firstPlayerGameField;
	for (int i = 0; i < FIELD_SIZE; i++)
		delete[]secondPlayerGameField[i];
	delete[]secondPlayerGameField;
	system("pause");
	return 0;
}