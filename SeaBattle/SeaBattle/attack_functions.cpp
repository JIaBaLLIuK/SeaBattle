#include "functions.h"
// функция, реализующая атаку игрока
void PlayerAttack(char** fieldForAttack, char** fieldForShowAttack)
{
	bool isHitted = false;
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
					cout << "Вы попали! Вы должны будете повторить атаку." << endl;
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
		}
		cout << "После атака поле соперника выглядит следующим образом:" << endl;
		PrintGameField(fieldForShowAttack);
		
	} while (isHitted);
}

bool isKilled()
{

	return true;
}