#include "functions.h"

void ShipPlacementMenu(char** gameField, int** shipCoordinates)
{
	ResetGameField(gameField);
	cout << "Пустое игровое поле имеет вид:" << endl;
	PrintGameField(gameField);
	cout << "Каким образом вы хотите разместить корабли на поле?\n1 - вручную\n2 - случайно" << endl;
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
	cout << "Теперь ваше игровое поле имеет вид:" << endl;
	PrintGameField(gameField);
	system("pause");
	system("CLS");
}
// функция проверки, есть ли победитель
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