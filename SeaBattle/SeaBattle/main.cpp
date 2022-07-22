#include "functions.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char** firstPlayerGameField = NULL;
	char** secondPlayerGameField = NULL;
	char** firstPlayerFieldForAttack = NULL;
	char** secondPlayerFieldForAttack = NULL;
	int** firstPlayerShipCoordinates = NULL;
	int** secondPlayerShipCoordinates = NULL;
	// выделение памяти под все массивы
	MemoryAllocation(&firstPlayerGameField, FIELD_SIZE, FIELD_SIZE);
	MemoryAllocation(&secondPlayerGameField, FIELD_SIZE, FIELD_SIZE);
	MemoryAllocation(&firstPlayerFieldForAttack, FIELD_SIZE, FIELD_SIZE);
	MemoryAllocation(&secondPlayerFieldForAttack, FIELD_SIZE, FIELD_SIZE);
	MemoryAllocation(&firstPlayerShipCoordinates, 10, 4);
	MemoryAllocation(&secondPlayerShipCoordinates, 10, 4);
	ResetGameField(firstPlayerFieldForAttack);
	ResetGameField(secondPlayerFieldForAttack);
	// расстановка кораблей игроками
	cout << "Расставление кораблей на поле. Очередь первого игрока." << endl;
	ShipPlacementMenu(firstPlayerGameField, firstPlayerShipCoordinates);
	cout << "Расставление кораблей на поле. Очередь второго игрока." << endl;
	ShipPlacementMenu(secondPlayerGameField, secondPlayerShipCoordinates);
	// цикл ходов игроков
	bool isWinner = false;
	do
	{
		cout << "Теперь поле первого игрока имеет вид:" << endl;
		PrintGameField(firstPlayerGameField);
		cout << "Ход первого игрока. Поле, по которому вам предстоит наносить удары, имеет вид:" << endl;
		PrintGameField(firstPlayerFieldForAttack);
		isWinner = PlayerAttack(secondPlayerGameField, firstPlayerFieldForAttack, secondPlayerShipCoordinates);
		if (isWinner)
			break;
		system("pause");
		system("CLS");
		cout << "Теперь поле второго игрока имеет вид:" << endl;
		PrintGameField(secondPlayerGameField);
		cout << "Ход второго игрока. Поле, по которому вам предстоит наносить удары, имеет вид:" << endl;
		PrintGameField(secondPlayerFieldForAttack);
		isWinner = PlayerAttack(firstPlayerGameField, secondPlayerFieldForAttack, secondPlayerShipCoordinates);
		system("pause");
		system("CLS");
	} while (!isWinner);







	// очистка выделенной памяти
	MemoryDelete(&firstPlayerGameField, FIELD_SIZE, FIELD_SIZE);
	MemoryDelete(&secondPlayerGameField, FIELD_SIZE, FIELD_SIZE);
	MemoryDelete(&firstPlayerFieldForAttack, FIELD_SIZE, FIELD_SIZE);
	MemoryDelete(&secondPlayerFieldForAttack, FIELD_SIZE, FIELD_SIZE);
	MemoryDelete(&firstPlayerShipCoordinates, 10, 4);
	MemoryDelete(&secondPlayerShipCoordinates, 10, 4);
	return 0;
}