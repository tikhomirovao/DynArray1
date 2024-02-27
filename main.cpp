#include <iostream>
#include "DynArray.h"

using namespace std;

//функция создания и заполнение массива случайными числами
DynArray CreateArray(size_t Size)
{
	DynArray TMP(Size); //создает локальный lvalue объект функции, указанного размера
	TMP.Randomize(-99, 99); //заполняет объект случайными числами от -99 до 99 включительно
	return TMP;
}
// ввод ответа на вопрос
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
		case 'Н':
		case 'н':
		case 'Т':
		case 'т':
			cout << "Переключите раскладку клавиатуры на английскую и попробуйте ещё раз!" << endl;
			break;
		default:
			cout << "Некорректный ответ! Попробуйте ещё раз!" << endl;
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
	cout << "Массив: " << Massiv << endl;
	cout << Massiv[19];
	cout << endl;
	cout << "Поиск значения элемента по номеру!" << endl;
	while (true)
	{
		try
		{
			cout << "Введите номер элемента: " << endl;
			SetValue(I);
			cout << Massiv[I - 1] << endl;
			cout << "Продолжить поиск Y/N? ";
			if (!Answer())break; //ввод и проверка ответа		
		}
		catch (int I)//поймает любое исключение типа данных int
		{
			if (I<1 || I> Massiv.Size())
			{
				cout << "Выход за пределы массива!" << endl;
				cout << "Попробуйте ещё раз!" << endl;
			}
			Sleep(1500);
		}
		catch (const char* str) //поймает любое исключение типа данных const char*
		{
			cout << str << endl;
			Sleep(1500);
		}
		catch (...) //универсальный catch поймает исключение любого типа данных
		{
			cout << "Непревиденная ошибка! Обратитесь в службу технической поддержки!" << endl;
			Sleep(1000);
			return -1; //выход из функции main
		}
	}
	cout << "До новых встреч!" << endl;
	Sleep(1000);
}