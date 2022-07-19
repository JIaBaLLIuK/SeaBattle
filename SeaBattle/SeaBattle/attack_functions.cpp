#include "functions.h"
// �������, ����������� ����� ������
void PlayerAttack(char** fieldForAttack, char** fieldForShowAttack)
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
					cout << "�� ������! �� ������ ������ ��������� �����." << endl;
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

bool isKilled()
{

	return true;
}