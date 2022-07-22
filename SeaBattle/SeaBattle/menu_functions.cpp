#include "functions.h"

void ShipPlacementMenu(char** gameField, int** shipCoordinates)
{
	ResetGameField(gameField);
	cout << "������ ������� ���� ����� ���:" << endl;
	PrintGameField(gameField);
	cout << "����� ������� �� ������ ���������� ������� �� ����?\n1 - �������\n2 - ��������" << endl;
	int typeOfFieldInput = InputIntValue(1, 2);
	switch (typeOfFieldInput)
	{
	case 1:
		InputShipCoordinates(gameField, shipCoordinates);
		break;
	case 2:
		RandomFieldGeneration(gameField, shipCoordinates);
		break;
	}
	system("CLS");
	cout << "������ ���� ������� ���� ����� ���:" << endl;
	PrintGameField(gameField);
	system("pause");
	system("CLS");
}
// ������� ��������, ���� �� ����������
bool IsWinner(char** gameField)
{
	int shipCells = BOAT_SIZE * 4 + DESTROYER_SIZE * 3 + CRUISER_SIZE * 2 + BATTLESHIP_SIZE;
	for (int i = 0; i < FIELD_SIZE; i++)
		for (int j = 0; j < FIELD_SIZE; j++)
			if (gameField[i][j] == HIT)
				shipCells--;
	if (!shipCells)
		return true;
	else
		return false;
}