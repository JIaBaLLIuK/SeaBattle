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
	int asciiCode = 65;  // код английсокй буквы A
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
// функция ввода координат для отдельно взятого кораблая
void InputCurrentShipCoordinates(char** gameField, int size)
{
	char row;
	int rowNumber, columnNumber, direction;
	bool isCorrectPosition;
	do
	{
		cout << "Введите букву, соответсвующуую строке игрового поля:" << endl;
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
		cout << "Введите направление корабля (1 - верх, 2 - низ, 3 - лево, 4 - право):" << endl;
		direction = InputIntValue(1, 4);
		isCorrectPosition = CheckShipPosition(gameField, rowNumber, columnNumber, direction, size);
		if (!isCorrectPosition)
			cout << "При вводе координат вы совершили ошибку. Ввод будет повторен!" << endl;
	} while (!isCorrectPosition);
	DrawShip(gameField, rowNumber, columnNumber, direction, size);
}
// функция ввода координат корабля
void InputShipCoordinates(char** gameField)
{
	cout << "Ввод координат для 4-хпалубного корабля (осталась 1 штука)." << endl;
	InputCurrentShipCoordinates(gameField, BATTLESHIP_SIZE);
	system("CLS");
	cout << "Теперь игровое поле имеет вид:" << endl;
	PrintGameField(gameField);
	for (int i = 2; i >= 1; i--)
	{
		cout << "Ввод координат для 3-хпалубного корабля (осталась " << i << " штука(штуки))." << endl;
		InputCurrentShipCoordinates(gameField, CRUISER_SIZE);
		system("CLS");
		cout << "Теперь игровое поле имеет вид:" << endl;
		PrintGameField(gameField);
	}
	for (int i = 3; i >= 1; i--)
	{
		cout << "Ввод координат для 2-хпалубного корабля (осталась " << i << " штука(штуки))." << endl;
		InputCurrentShipCoordinates(gameField, DESTROYER_SIZE);
		system("CLS");
		cout << "Теперь игровое поле имеет вид:" << endl;
		PrintGameField(gameField);
	}
	for (int i = 4; i >= 1; i--)
	{
		cout << "Ввод координат для 1-палубного корабля (осталась " << i << " штука(штуки))." << endl;
		InputCurrentShipCoordinates(gameField, BOAT_SIZE);
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
// функция случайной генерации игрового поля
void RandomFieldGeneration(char** gameField)
{
	srand(time(NULL));
	int rowNumber;
	int columnNumber;
	int direction;
	do
	{
		rowNumber = rand() % 10;
		columnNumber = rand() % 10;
		direction = 1 + rand() % 4;
	} while (!CheckShipPosition(gameField, rowNumber, columnNumber, direction, BATTLESHIP_SIZE));
	DrawShip(gameField, rowNumber, columnNumber, direction, BATTLESHIP_SIZE);
	for (int i = 0; i < 2; i++)
	{
		do
		{
			rowNumber = rand() % 10;
			columnNumber = rand() % 10;
			direction = 1 + rand() % 4;
		} while (!CheckShipPosition(gameField, rowNumber, columnNumber, direction, CRUISER_SIZE));
		DrawShip(gameField, rowNumber, columnNumber, direction, CRUISER_SIZE);
	}
	for (int i = 0; i < 3; i++)
	{
		do
		{
			rowNumber = rand() % 10;
			columnNumber = rand() % 10;
			direction = 1 + rand() % 4;
		} while (!CheckShipPosition(gameField, rowNumber, columnNumber, direction, DESTROYER_SIZE));
		DrawShip(gameField, rowNumber, columnNumber, direction, DESTROYER_SIZE);
	}
	for (int i = 0; i < 4; i++)
	{
		do
		{
			rowNumber = rand() % 10;
			columnNumber = rand() % 10;
			direction = 1 + rand() % 4;
		} while (!CheckShipPosition(gameField, rowNumber, columnNumber, direction, DESTROYER_SIZE));
		DrawShip(gameField, rowNumber, columnNumber, direction, BOAT_SIZE);
	}
}