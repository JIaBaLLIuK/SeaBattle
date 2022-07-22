#include "functions.h"
// функция, реализующая атаку игрока
void PlayerAttack(char** fieldForAttack, char** fieldForShowAttack, int** shipCoordinates)
{
	bool isHitted = false;
	static int hitsToShip = 0;
	do
	{
		bool isForbiddenCell = false;
		int columnNumber, rowNumber;
		do
		{
			cout << "Введите букву, соответсвующую строке игрового поля:" << endl;
			rewind(stdin);
			char row = getchar();
			while (row < 'A' || row > 'J')
			{
				rewind(stdin);
				cout << "Ошибка. Повторите ввод:" << endl;
				row = getchar();
			}
			cout << "Введите цифру, соответсвующую номеру столбца игрового поля:" << endl;
			columnNumber = InputIntValue(1, 10);
			rowNumber = (int)row - 65;
			columnNumber--;
			if (fieldForAttack[rowNumber][columnNumber] != SEA && fieldForAttack[rowNumber][columnNumber] != SHIP)
			{
				isForbiddenCell = true;
				cout << "Вы не можете сюда ударить! Введите координаты заново" << endl;
			}
		} while (isForbiddenCell);
		for (int i = 0; i < FIELD_SIZE; i++)
		{
			for (int j = 0; j < FIELD_SIZE; j++)
			{
				if (fieldForAttack[rowNumber][columnNumber] == SHIP)
				{
					if (!IsDestroyedShip(shipCoordinates, rowNumber, columnNumber, hitsToShip))
						cout << "Вы попали! Вы будете должны повторить атаку." << endl;
					else
						cout << "Вы потопили корабль! Вы будете должны повторить атаку." << endl;
					isHitted = true;
					fieldForAttack[rowNumber][columnNumber] = HIT;
					fieldForShowAttack[rowNumber][columnNumber] = HIT;
					break;
				}
				else if (fieldForAttack[rowNumber][columnNumber] == SEA)
				{
					cout << "Вы промахнулись! Ход переходит сопернику." << endl;
					isHitted = false;
					fieldForAttack[rowNumber][columnNumber] = MISS;
					fieldForShowAttack[rowNumber][columnNumber] = MISS;
					break;
				}
			}
			if (isHitted)
				break;
		}
		cout << "После атака поле соперника выглядит следующим образом:" << endl;
		PrintGameField(fieldForShowAttack);
	} while (isHitted);
}
// функция, проверяющая, уничтожен ли корабль соперника
bool IsDestroyedShip(int** shipCoordinates, int hitRow, int hitColumn, int& hitsToShip)
{
	bool isDestroyed = false;
	int startRowCoordinate, startColumnCoordinate, direction, size;
	for (int i = 0; i < 10; i++)
	{
		startRowCoordinate = shipCoordinates[i][0];
		startColumnCoordinate = shipCoordinates[i][1];
		direction = shipCoordinates[i][2];
		size = shipCoordinates[i][3];
		bool checkBreak = false;
		switch (direction)
		{
		case TOP:
			for (int i = startRowCoordinate; i > startRowCoordinate - size; i--)
			{
				if (i == hitRow && startColumnCoordinate == hitColumn)
				{
					hitsToShip++;
					checkBreak = true;
					if (hitsToShip == size)
					{
						isDestroyed = true;
						hitsToShip = 0;
					}
					break;
				}
			}
			break;
		case BOTTOM:
			for (int i = startRowCoordinate; i < startRowCoordinate + size; i++)
			{
				if (i == hitRow && startColumnCoordinate == hitColumn)
				{
					hitsToShip++;
					checkBreak = true;
					if (hitsToShip == size)
					{
						isDestroyed = true;
						hitsToShip = 0;
					}
					break;
				}
			}
			break;
		case LEFT:
			for (int i = startColumnCoordinate; i > startColumnCoordinate - size; i--)
			{
				if (i == hitColumn && startRowCoordinate == hitRow)
				{
					hitsToShip++;
					checkBreak = true;
					if (hitsToShip == size)
					{
						isDestroyed = true;
						hitsToShip = 0;
					}
					break;
				}
			}
			break;
		case RIGHT:
			for (int i = startColumnCoordinate; i < startColumnCoordinate + size; i++)
			{
				if (i == hitColumn && startRowCoordinate == hitRow)
				{
					hitsToShip++;
					checkBreak = true;
					if (hitsToShip == size)
					{
						isDestroyed = true;
						hitsToShip = 0;
					}
					break;
				}
			}
			break;
		}
		if (checkBreak)
			break;
	}
	return isDestroyed;
}