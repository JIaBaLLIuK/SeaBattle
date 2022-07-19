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
	int** fistPlayerShipCoordinates = new int* [10];  // массив, каждая строка которого хранит стартовую позицию кораблая, направление и размер
	for (int i = 0; i < 10; i++)
		fistPlayerShipCoordinates[i] = new int[4];
	int** secondPlayerShipCoordinates = new int* [10];  // массив, каждая строка которого хранит стартовую позицию кораблая, направление и размер
	for (int i = 0; i < 10; i++)
		secondPlayerShipCoordinates[i] = new int[4];
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
		InputShipCoordinates(firstPlayerGameField, fistPlayerShipCoordinates);
		break;
	case 2:
		RandomFieldGeneration(firstPlayerGameField, fistPlayerShipCoordinates);
		break;
	}
	system("CLS");
	cout << "Теперь ваше игровое поле имеет вид:" << endl;
	PrintGameField(firstPlayerGameField);
	cout << "Поле, по которому вам предстоит наносить удары, имеет вид:" << endl;
	PrintGameField(firstPlayerFieldForAttack);

	
	//RandomFieldGeneration(secondPlayerGameField, secondPlayerShipCoordinates);
	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//		cout << secondPlayerShipCoordinates[i][j] << " ";
	//	cout << endl;
	//}
	//while (true)
	//{
	//	cout << "======test======" << endl;
	//	PrintGameField(secondPlayerGameField);
	//	PlayerAttack(secondPlayerGameField, firstPlayerFieldForAttack, secondPlayerShipCoordinates);
	//}


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
		delete[]fistPlayerShipCoordinates[i];
	delete[]fistPlayerShipCoordinates;
	for (int i = 0; i < 10; i++)
		delete[]secondPlayerShipCoordinates[i];
	delete[]secondPlayerShipCoordinates;
	system("pause");
	return 0;
}