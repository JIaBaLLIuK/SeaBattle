#include "functions.h"
// функция, реализующая атаку игрока
bool PlayerAttack(char** fieldForAttack, char** fieldForShowAttack, int** shipCoordinates, int player)
{
	bool isHitted = false;
	static int firstPlayerHitsToShip = 0;
	static int secondPlayerHitsToShip = 0;
	do
	{
		bool isForbiddenCell = false;
		int columnNumber, rowNumber;
		do
		{
			if (IsWinner(fieldForAttack))
			{
				cout << "Вы победили! Поздравляю!" << endl;
				return true;
			}
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
				cout << "Вы не можете сюда ударить! Введите координаты заново." << endl;
			}
			else
				isForbiddenCell = false;
		} while (isForbiddenCell);
		if (fieldForAttack[rowNumber][columnNumber] == SHIP)
		{
			switch (player)
			{
			case 1:
				if (!IsDestroyedShip(shipCoordinates, rowNumber, columnNumber, firstPlayerHitsToShip, fieldForAttack, fieldForShowAttack))
					cout << "Вы попали! Вы должны повторить атаку." << endl;
				else
					cout << "Вы потопили корабль! Вы должны повторить атаку." << endl;
				break;
			case 2:
				if (!IsDestroyedShip(shipCoordinates, rowNumber, columnNumber, secondPlayerHitsToShip, fieldForAttack, fieldForShowAttack))
					cout << "Вы попали! Вы должны повторить атаку." << endl;
				else
					cout << "Вы потопили корабль! Вы должны повторить атаку." << endl;
				break;
			}
			isHitted = true;
			fieldForAttack[rowNumber][columnNumber] = HIT;
			fieldForShowAttack[rowNumber][columnNumber] = HIT;
		}
		else if (fieldForAttack[rowNumber][columnNumber] == SEA)
		{
			cout << "Вы промахнулись! Ход переходит сопернику." << endl;
			isHitted = false;
			fieldForAttack[rowNumber][columnNumber] = MISS;
			fieldForShowAttack[rowNumber][columnNumber] = MISS;
		}
		cout << "После атака поле соперника выглядит следующим образом:" << endl;
		PrintGameField(fieldForShowAttack);
	} while (isHitted);
	return false;
}
// функция, проверяющая, уничтожен ли корабль соперника
bool IsDestroyedShip(int** shipCoordinates, int hitRow, int hitColumn, int& hitsToShip, char** gameField, char** fieldForShowAttack)
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
						DrawAroundShip(gameField, fieldForShowAttack, startRowCoordinate, startColumnCoordinate, direction, size);
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
						DrawAroundShip(gameField, fieldForShowAttack, startRowCoordinate, startColumnCoordinate, direction, size);
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
						DrawAroundShip(gameField, fieldForShowAttack, startRowCoordinate, startColumnCoordinate, direction, size);
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
						DrawAroundShip(gameField, fieldForShowAttack, startRowCoordinate, startColumnCoordinate, direction, size);
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