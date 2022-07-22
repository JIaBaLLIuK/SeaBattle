#include "functions.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char** firstPlayerGameField = NULL;
	char** secondPlayerGameField = NULL;
	char** firstPlayerFieldForAttack = NULL;
	char** secondPlayerFieldForAttack = NULL;
	int** fistPlayerShipCoordinates = NULL;
	int** secondPlayerShipCoordinates = NULL;
	MemoryAllocation(&firstPlayerGameField, FIELD_SIZE, FIELD_SIZE);
	MemoryAllocation(&secondPlayerGameField, FIELD_SIZE, FIELD_SIZE);
	MemoryAllocation(&firstPlayerFieldForAttack, FIELD_SIZE, FIELD_SIZE);
	MemoryAllocation(&secondPlayerFieldForAttack, FIELD_SIZE, FIELD_SIZE);
	MemoryAllocation(&fistPlayerShipCoordinates, 10, 4);
	MemoryAllocation(&secondPlayerShipCoordinates, 10, 4);
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

	
	RandomFieldGeneration(secondPlayerGameField, secondPlayerShipCoordinates);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << secondPlayerShipCoordinates[i][j] << " ";
		cout << endl;
	}
	while (true)
	{
		cout << "======test======" << endl;
		PrintGameField(secondPlayerGameField);
		PlayerAttack(secondPlayerGameField, firstPlayerFieldForAttack, secondPlayerShipCoordinates);
	}


	MemoryDelete(&firstPlayerGameField, FIELD_SIZE, FIELD_SIZE);
	MemoryDelete(&secondPlayerGameField, FIELD_SIZE, FIELD_SIZE);
	MemoryDelete(&firstPlayerFieldForAttack, FIELD_SIZE, FIELD_SIZE);
	MemoryDelete(&secondPlayerFieldForAttack, FIELD_SIZE, FIELD_SIZE);
	MemoryDelete(&fistPlayerShipCoordinates, 10, 4);
	MemoryDelete(&secondPlayerShipCoordinates, 10, 4);
	system("pause");
	return 0;
}