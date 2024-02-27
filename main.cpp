#include <iostream>
#include "DynArray.h"

using namespace std;

//������� �������� � ���������� ������� ���������� �������
DynArray CreateArray(size_t Size)
{
	DynArray TMP(Size); //������� ��������� lvalue ������ �������, ���������� �������
	TMP.Randomize(-99, 99); //��������� ������ ���������� ������� �� -99 �� 99 ������������
	return TMP;
}
// ���� ������ �� ������
bool Answer()
{
	char A;
	while (true)
	{
		SetValue(A);
		switch (A)
		{
		case 'Y':
		case 'y':
			return true;
		case 'N':
		case 'n':
			return false;
		case '�':
		case '�':
		case '�':
		case '�':
			cout << "����������� ��������� ���������� �� ���������� � ���������� ��� ���!" << endl;
			break;
		default:
			cout << "������������ �����! ���������� ��� ���!" << endl;
			break;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(nullptr));

	int I = 0;
	DynArray Massiv = CreateArray(20);
	cout << "������: " << Massiv << endl;
	cout << Massiv[19];
	cout << endl;
	cout << "����� �������� �������� �� ������!" << endl;
	while (true)
	{
		try
		{
			cout << "������� ����� ��������: " << endl;
			SetValue(I);
			cout << Massiv[I - 1] << endl;
			cout << "���������� ����� Y/N? ";
			if (!Answer())break; //���� � �������� ������		
		}
		catch (int I)//������� ����� ���������� ���� ������ int
		{
			if (I<1 || I> Massiv.Size())
			{
				cout << "����� �� ������� �������!" << endl;
				cout << "���������� ��� ���!" << endl;
			}
			Sleep(1500);
		}
		catch (const char* str) //������� ����� ���������� ���� ������ const char*
		{
			cout << str << endl;
			Sleep(1500);
		}
		catch (...) //������������� catch ������� ���������� ������ ���� ������
		{
			cout << "������������� ������! ���������� � ������ ����������� ���������!" << endl;
			Sleep(1000);
			return -1; //����� �� ������� main
		}
	}
	cout << "�� ����� ������!" << endl;
	Sleep(1000);
}