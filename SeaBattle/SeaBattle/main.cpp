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
	char** firstPlayerFieldForAttack = new char* [FIELD_SIZE];  // поле первого игрока, на котором отображаются атаки по второму игроку
	for (int i = 0; i < FIELD_SIZE; i++)
		firstPlayerFieldForAttack[i] = new char[FIELD_SIZE];
	char** secondPlayerFieldForAttack = new char* [FIELD_SIZE];  // поле второго игрока, на котором отображаются атаки по первому игроку
	for (int i = 0; i < FIELD_SIZE; i++)
		secondPlayerFieldForAttack[i] = new char[FIELD_SIZE];
	int** shipCoordinates = new int* [10];  // массив, каждая строка которого хранит стартовую позицию кораблая, направление и размер
	for (int i = 0; i < 10; i++)
		shipCoordinates[i] = new int[4];
	ResetGameField(firstPlayerGameField);
	ResetGameField(secondPlayerGameField);
	ResetGameField(firstPlayerFieldForAttack);
	ResetGameField(secondPlayerFieldForAttack);
	cout << "Пустое игровое поле имеет вид:" << endl;
	PrintGameField(firstPlayerGameField);
	cout << "Каким образом вы хотите разместить корабли на поле?\n1 - вручную\n2 - случайно" << endl;
	int typeOfFieldInput = InputIntValue(1, 2);
	switch (typeOfFieldInput)
	{
	case 1:
		InputShipCoordinates(firstPlayerGameField, shipCoordinates);
		break;
	case 2:
		RandomFieldGeneration(firstPlayerGameField, shipCoordinates);
		break;
	}
	system("CLS");
	cout << "Теперь ваше игровое поле имеет вид:" << endl;
	PrintGameField(firstPlayerGameField);
	cout << "Поле, по которому вам предстоит наносить удары, имеет вид:" << endl;
	PrintGameField(firstPlayerFieldForAttack);


	


	for (int i = 0; i < FIELD_SIZE; i++)
		delete[]firstPlayerGameField[i];
	delete[]firstPlayerGameField;
	for (int i = 0; i < FIELD_SIZE; i++)
		delete[]secondPlayerGameField[i];
	delete[]secondPlayerGameField;
	for (int i = 0; i < FIELD_SIZE; i++)
		delete[]firstPlayerFieldForAttack[i];
	delete[]firstPlayerFieldForAttack;
	for (int i = 0; i < FIELD_SIZE; i++)
		delete[]secondPlayerFieldForAttack[i];
	delete[]secondPlayerFieldForAttack;
	for (int i = 0; i < 10; i++)
		delete[]shipCoordinates[i];
	delete[]shipCoordinates;
	system("pause");
	return 0;
}