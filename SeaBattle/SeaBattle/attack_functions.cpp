#include "functions.h"
// �������, ����������� ����� ������
void PlayerAttack(char** fieldForAttack, char** fieldForShowAttack, int** shipCoordinates)
{
	bool isHitted = false;
	do
	{
		bool isForbiddenCell = false;
		int columnNumber, rowNumber;
		do
		{
			cout << "������� �����, �������������� ������ �������� ����:" << endl;
			rewind(stdin);
			char row = getchar();
			while (row < 'A' || row > 'J')
			{
				rewind(stdin);
				cout << "������. ��������� ����:" << endl;
				row = getchar();
			}
			cout << "������� �����, �������������� ������ ������� �������� ����:" << endl;
			columnNumber = InputIntValue(1, 10);
			rowNumber = (int)row - 65;
			columnNumber--;
			if (fieldForAttack[rowNumber][columnNumber] != SEA && fieldForAttack[rowNumber][columnNumber] != SHIP)
			{
				isForbiddenCell = true;
				cout << "�� �� ������ ���� �������! ������� ���������� ������" << endl;
			}
		} while (isForbiddenCell);
		for (int i = 0; i < FIELD_SIZE; i++)
		{
			for (int j = 0; j < FIELD_SIZE; j++)
			{
				if (fieldForAttack[rowNumber][columnNumber] == SHIP)
				{
					if (!IsDestroyedShip(shipCoordinates, rowNumber, columnNumber))
						cout << "�� ������! �� ������ ������ ��������� �����." << endl;
					else 
						cout << "�� �������� �������! �� ������ ������ ��������� �����." << endl;
					isHitted = true;
					fieldForAttack[rowNumber][columnNumber] = HIT;
					fieldForShowAttack[rowNumber][columnNumber] = HIT;
					break;
				}
				else if (fieldForAttack[rowNumber][columnNumber] == SEA)
				{
					cout << "�� ������������! ��� ��������� ���������." << endl;
					isHitted = false;
					fieldForAttack[rowNumber][columnNumber] = MISS;
					fieldForShowAttack[rowNumber][columnNumber] = MISS;
					break;
				}
			}
		}
		cout << "����� ����� ���� ��������� �������� ��������� �������:" << endl;
		PrintGameField(fieldForShowAttack);
	} while (isHitted);
}
// �������, �����������, ��������� �� ������� ���������
bool IsDestroyedShip(int** shipCoordinates, int hitRow, int hitColumn)
{
	int hitsToShip = 0;
	bool isDestroyed = false;
	for (int i = 0; i < 10; i++)
	{
		int startRowCoordinate = shipCoordinates[i][0];
		int startcolumnCoordinate = shipCoordinates[i][1];
		int direction = shipCoordinates[i][2];
		int size = shipCoordinates[i][3];
		switch (direction)
		{
		case TOP:
			for (int i = startRowCoordinate; i > startRowCoordinate - size; i--)
			{
				if (i == hitRow)
				{
					hitsToShip++;
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
				if (i == hitRow)
				{
					hitsToShip++;
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
			for (int i = startcolumnCoordinate; i > startcolumnCoordinate - size; i--)
			{
				if (i == hitColumn)
				{
					hitsToShip++;
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
			for (int i = startcolumnCoordinate; i < startcolumnCoordinate + size; i++)
			{
				if (i == hitColumn)
				{
					hitsToShip++;
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
	}
	return isDestroyed;
}