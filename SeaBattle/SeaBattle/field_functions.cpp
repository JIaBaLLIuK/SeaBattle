#include "functions.h"
// функция сброса поля
void ResetGameField(char** gameField)
{
	for (int i = 0; i < FIELD_SIZE; i++)
		for (int j = 0; j < FIELD_SIZE; j++)
			gameField[i][j] = SEA;
}
// функция отображения поля на экране
void PrintGameField(char** gameField)
{
	for (int i = 1; i <= FIELD_SIZE; i++)
		cout << "   " << i;
	int asciiCode = 65;  // код английсокй буквы A
	cout << "\n |---|---|---|---|---|---|---|---|---|---|" << endl;
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			if (j == 0)
				cout << (char)asciiCode++;
			cout << "| ";
			if (gameField[i][j] == SHIP)
				cout << "\033[34m" << SHIP << "\033[0m";
			else if (gameField[i][j] == MISS)
				cout << "\033[32m" << MISS << "\033[0m";
			else if (gameField[i][j] == HIT)
				cout << "\033[31m" << HIT << "\033[0m";
			else
				cout << gameField[i][j];
			cout << " ";
			if (j == FIELD_SIZE - 1)
				cout << "|" << endl;
		}
		cout << " |---|---|---|---|---|---|---|---|---|---|" << endl;
	}
}
// функция ввода координат для отдельно взятого кораблая
void InputCurrentShipCoordinates(char** gameField, int size, int** shipCoordinates)
{
	char row;
	int rowNumber, columnNumber, direction;
	bool isCorrectPosition;
	do
	{
		cout << "Введите букву, соответсвующую строке игрового поля:" << endl;
		rewind(stdin);
		row = getchar();
		while (row < 'A' || row > 'J')
		{
			cout << "Ошибка. Повторите ввод:" << endl;
			rewind(stdin);
			row = getchar();
		}
		cout << "Введите цифру, соответсвующую номеру столбца игрового поля:" << endl;
		columnNumber = InputIntValue(1, 10);
		rowNumber = int(row) - 65;
		columnNumber--;
		if (size > 1)
		{
			cout << "Введите направление корабля (1 - верх, 2 - низ, 3 - лево, 4 - право):" << endl;
			direction = InputIntValue(1, 4);
		}
		else
			direction = 1;
		isCorrectPosition = CheckShipPosition(gameField, rowNumber, columnNumber, direction, size);
		if (!isCorrectPosition)
			cout << "При вводе координат вы совершили ошибку. Ввод будет повторен!" << endl;
	} while (!isCorrectPosition);
	static int shipNumber;
	shipCoordinates[shipNumber][0] = rowNumber;
	shipCoordinates[shipNumber][1] = columnNumber;
	shipCoordinates[shipNumber][2] = direction;
	shipCoordinates[shipNumber++][3] = size;
	if (shipNumber == 10)
		shipNumber = 0;
	DrawShip(gameField, rowNumber, columnNumber, direction, size);
}
// функция ввода координат корабля
void InputShipCoordinates(char** gameField, int** shipCoordinates)
{
	cout << "Ввод координат для 4-хпалубного корабля (осталась 1 штука)." << endl;
	InputCurrentShipCoordinates(gameField, BATTLESHIP_SIZE, shipCoordinates);
	system("CLS");
	cout << "Теперь игровое поле имеет вид:" << endl;
	PrintGameField(gameField);
	for (int i = 2; i >= 1; i--)
	{
		cout << "Ввод координат для 3-хпалубного корабля (осталась " << i << " штука(штуки))." << endl;
		InputCurrentShipCoordinates(gameField, CRUISER_SIZE, shipCoordinates);
		system("CLS");
		cout << "Теперь игровое поле имеет вид:" << endl;
		PrintGameField(gameField);
	}
	for (int i = 3; i >= 1; i--)
	{
		cout << "Ввод координат для 2-хпалубного корабля (осталась " << i << " штука(штуки))." << endl;
		InputCurrentShipCoordinates(gameField, DESTROYER_SIZE, shipCoordinates);
		system("CLS");
		cout << "Теперь игровое поле имеет вид:" << endl;
		PrintGameField(gameField);
	}
	for (int i = 4; i >= 1; i--)
	{
		cout << "Ввод координат для 1-палубного корабля (осталась " << i << " штука(штуки))." << endl;
		InputCurrentShipCoordinates(gameField, BOAT_SIZE, shipCoordinates);
		system("CLS");
		cout << "Теперь игровое поле имеет вид:" << endl;
		PrintGameField(gameField);
	}
}
// функция отображения кораблей на игровом поле
void DrawShip(char** gameField, int rowNumber, int columnNumber, int direction, int size)
{
	switch (direction)
	{
	case TOP:
		for (int i = rowNumber; i > rowNumber - size; i--)
			gameField[i][columnNumber] = SHIP;
		break;
	case BOTTOM:
		for (int i = rowNumber; i < rowNumber + size; i++)
			gameField[i][columnNumber] = SHIP;
		break;
	case LEFT:
		for (int i = columnNumber; i > columnNumber - size; i--)
			gameField[rowNumber][i] = SHIP;
		break;
	case RIGHT:
		for (int i = columnNumber; i < columnNumber + size; i++)
			gameField[rowNumber][i] = SHIP;
		break;
	}
}
// функиця случайной генерации координат кораблая
void RandomShipGeneration(char** gameField, int** shipCoordinates, int size)
{
	srand(time(NULL));
	int rowNumber, columnNumber, direction;
	do
	{
		rowNumber = rand() % 10;
		columnNumber = rand() % 10;
		if (size > 1)
			direction = 1 + rand() % 4;
		else
			direction = 1;
	} while (!CheckShipPosition(gameField, rowNumber, columnNumber, direction, size));
	static int shipNumber;
	shipCoordinates[shipNumber][0] = rowNumber;
	shipCoordinates[shipNumber][1] = columnNumber;
	shipCoordinates[shipNumber][2] = direction;
	shipCoordinates[shipNumber++][3] = size;
	if (shipNumber == 10)
		shipNumber = 0;
	DrawShip(gameField, rowNumber, columnNumber, direction, size);
}
// функция случайной генерации игрового поля
void RandomFieldGeneration(char** gameField, int** shipCoordinates)
{
	RandomShipGeneration(gameField, shipCoordinates, BATTLESHIP_SIZE);
	for (int i = 0; i < 2; i++)
		RandomShipGeneration(gameField, shipCoordinates, CRUISER_SIZE);
	for (int i = 0; i < 3; i++)
		RandomShipGeneration(gameField, shipCoordinates, DESTROYER_SIZE);
	for (int i = 0; i < 4; i++)
		RandomShipGeneration(gameField, shipCoordinates, BOAT_SIZE);
}
