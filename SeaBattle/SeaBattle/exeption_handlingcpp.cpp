#include "functions.h"
// ������� �������� ����� ����� �� �������� ���������
int InputIntValue(int minValue, int maxValue)
{
	int number;
	cin >> number;
	while (number < minValue || number > maxValue || cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������. ��������� ����:" << endl;
		cin >> number;
	}
	return number;
}
// ������� �������� ��������� ��� �������  CheckShipPosition()
bool CheckCurrentCoordinates(char** gameField, int rowNumber, int columnNumber)
{
	if (rowNumber > 0 && gameField[rowNumber - 1][columnNumber] != SEA || rowNumber < FIELD_SIZE - 1 && gameField[rowNumber + 1][columnNumber] != SEA)
		return false;
	if (columnNumber > 0 && gameField[rowNumber][columnNumber - 1] != SEA || columnNumber < FIELD_SIZE - 1 && gameField[rowNumber][columnNumber + 1] != SEA)
		return false;
	if (rowNumber < FIELD_SIZE - 1 && columnNumber < FIELD_SIZE - 1 && gameField[rowNumber + 1][columnNumber + 1] != SEA)
		return false;
	if (rowNumber > 0 && columnNumber > 0 && gameField[rowNumber - 1][columnNumber - 1] != SEA)
		return false;
	if (rowNumber < FIELD_SIZE - 1 && columnNumber > 0 && gameField[rowNumber + 1][columnNumber - 1] != SEA)
		return false;
	if (columnNumber < FIELD_SIZE - 1 && rowNumber > 0 && gameField[rowNumber - 1][columnNumber + 1] != SEA)
		return false;
	if (gameField[rowNumber][columnNumber] != SEA)
		return false;
	return true;
}
// ������� �������� ��������� ���������
bool CheckShipPosition(char** gameField, int rowNumber, int columnNumber, int direction, int size)
{
	switch (direction)
	{
	case TOP:
		for (int i = rowNumber; i > rowNumber - size; i--)
			if (!CheckCurrentCoordinates(gameField, i, columnNumber))
				return false;
		break;
	case BOTTOM:
		for (int i = rowNumber; i < rowNumber + size; i++)
			if (!CheckCurrentCoordinates(gameField, i, columnNumber))
				return false;
		break;
	case LEFT:
		for (int i = columnNumber; i > columnNumber - size; i--)
			if (!CheckCurrentCoordinates(gameField, rowNumber, i))
				return false;
		break;
	case RIGHT:
		for (int i = columnNumber; i < columnNumber + size; i++)
			if (!CheckCurrentCoordinates(gameField, rowNumber, i))
				return false;
		break;
	}
	return true;
}
