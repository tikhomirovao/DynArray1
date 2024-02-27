#pragma once
#include <iostream>
#include <windows.h> //в каждом методе, где есть ввод-вывод символов
//нужно уставнавливать соответсвующую кодировку
#include <stdlib.h>
#include <time.h>
#include <initializer_list> //класс для инициализации путем перечисления значений(унифицированной спосочной инициализации)
#include <assert.h> //макрос assert - выводит на экран консоли системное сообщение об ошибке и прерывает работу программы
#include <malloc.h> //библиотека с функцииями для работы с памятью
#include <limits>


using namespace std;

//класс описывающий динамический одномерный массив элементов типа данных int
class DynArray
{
	//private:
		//int size = 0; //кол-во элементов
		//unsigned int size = 0; //кол-во элементов
	size_t size = (size_t)0; //кол-во элементов
	int* array = nullptr; //указатель на элементы типа данных int
public:
	DynArray(char) = delete; //оключаем конструктор с char в качестве аргумента
	DynArray() = default; //default - просьба компилятору добавить уавтоматическую реализацию конструткора
	//DynArray(){cout<<"Сработал конструктор по умолчанию для объекта "<<this<<endl; } //для теста!
	//Конструктор с параметрами
	explicit DynArray(size_t); //explicit DynArray(unsigned int);
	//конструктор копирования
	DynArray(const DynArray&); //принемает константную lvalue ссылку
	//конструктор перемещения
	DynArray(DynArray&&); //rvalue ссылка в качестве параметра принимает временный безымянный rvalue объект класса DynArray
	//конструктор перемещения служит для извлечения содержимого из одного объекта(временного безымянного) класса DynArray
	//в другой(новый постоянный именованный) объект класса DynArray при его создании 
	//конструктор списочной инициализации
	DynArray(const initializer_list<int>&); //константная ссылка на объект шаблонного класса initializer_list, с типом данных int внутри
	//Деструктор
	~DynArray();
	//сеттеры:
	//Метод заполнения массива случайными числами от указанного до указанного числа
	//Нужно сдвинуть генератор случайных чисел!
	void Randomize(int, int);
	//метод изменения размера массива внутри объекта класса DynArray
	void ReSize(size_t); //void ReSize(unsigned int);
	//геттеры:
	//Метод получения текущего размера массива(кол-ва элементов)
	size_t Size()const; //unsigned int Size()const;

	// прототип метода сортировки массива
	void Sort();

	//перегрузка операторов как методов класса:
	//перегрузка оператора индексирования []
	int& operator[](int); //как сеттер и геттер для переменных(обычных) объектов класса DynArray(для массива переменнхы типа данных int)
	//константная перегрузка оператора индексирования []
	const int operator[](int)const; //как геттер для константных объектов класса DynArray(для массива констант типа данных int)
	//перегрузка оператора копирующего присваивания
	DynArray& operator=(const DynArray&);
	//перегрузка оператора перемещающего присваивания
	DynArray& operator=(DynArray&&); //rvalue ссылка в качестве параметра принимает временный безымянный rvalue объект класса DynArray
	//оператор перемещающего присваивания служит для извлечения содержимого из одного объекта(временного безымянного) класса DynArray
	//в другой(постоянный именованный) объект класса DynArray при присваивании в него
	//перегрузка оператора провреки на равенство ==
	bool operator==(const DynArray&)const; //при сравнении не может быть изменено содержимое сравниваемых объектов
	//перегрузка оператора провреки на равенство !=
	bool operator!=(const DynArray&)const; //при сравнении не может быть изменено содержимое сравниваемых объектов

	//перегрузка операторов работы с динамической памятью
	void* operator new(size_t); //size_t - или unsigned int или unsigned long long
	void operator delete(void*);
	void* operator new[](size_t);
	void operator delete[](void*);

	//перегрузка оператора сложения для ситуации DynArray+int
	DynArray operator+(int Digit);
	//перегрузка оператора вычитания для ситуации DynArray-int
	DynArray operator-(int Digit);
	//перегрузка оператора умножения для ситуации DynArray*int
	DynArray operator*(int Digit);
	//перегрузка оператора деления для ситуации DynArray/int
	DynArray operator/(int Digit);


	//дружественная перегрузка оператора сложения для ситуации int + DynArray
	friend DynArray operator+(int Digit, const DynArray&);
	//дружественная перегрузка оператора вычитания для ситуации int - DynArray
	friend DynArray operator-(int Digit, const DynArray&);
	//дружественная перегрузка оператора умножения для ситуации int * DynArray
	friend DynArray operator*(int Digit, const DynArray&);
	//дружественная перегрузка оператора деления для ситуации int / DynArray
	friend DynArray operator/(int Digit, const DynArray&);

	//дружественная перегрузка операторов:
	//перегрузка оператора вывода
	friend ostream& operator<<(ostream&, const DynArray&);
	//перегрузка оператора ввода
	friend istream& operator>>(istream&, DynArray&);
};
//прототип глобальной перегрузки оператора сложения + (сложение массивов поэлементно)
DynArray operator+(const DynArray&, const DynArray&); //возвращает значение временного безымянного объекта
//шаблон функции обработки исключений
template<typename T> inline void SetValue(T& Value)
{
#ifdef max //проверяем есть ли define max
#undef max //если есть - отключаем
#define MAX //define для обозначения, что отключен max()
#endif

	cin.exceptions(istream::badbit | istream::failbit); //включаем обработку исключений для класса istream, через объект cin
	//cout.exceptions(ostream::badbit | ostream::failbit); //включаем обработку исключений для класса ostream, через объект cout

	try //в него помещаем код, где будем ожидать генерацию исключения
	{
		cin >> Value; //throw istream::failure;
		//cin.operator>>(Value);
		//если после числа введен символ 5t или при вводе символа введены лишние символы
		//cin.ignore(32767,'\n'); //очистка потока(игнорирование) до 32767значений, пока не найден \n
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //очистка(игнорирование) всего потока до его макимальной длины
	}
	//catch (const istream::failure& exp) //сюда будет пойман объект класса istream::failure
	catch (const istream::failure&)
	{
		//catch сработает только кода оператор >> вызванный для объекта cin
		//сгенерирует исключение вида throw istream::failure;
		//cout << exp.what() << endl;
		//cout << exp.code() << endl;

		//считываем  текущую кодировку на вывод текста
		int OCP = GetConsoleOutputCP();
		//если не подходит меняем на нужную
		if (OCP != 1251)SetConsoleOutputCP(1251);
		cout << "Некорректный ввод!" << endl;

		if (cin.fail()) //если поток перешел в состояние fail
		{
			cin.clear(); //возвращает поток в "рабочий" режим
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //очистка(игнорирование) всего потока до его макимальной длины
		}
		cout << "Попробуйте ещё раз!" << endl;
		//вовзвращаем кодировку, если изменяли
		if (OCP != 1251)SetConsoleOutputCP(OCP);
		SetValue(Value);//рекурсию можно заменить итерацией(бесконечным циклом)
	}
#ifdef MAX
#define max(a,b) (((a) > (b)) ? (a) : (b))
#undef MAX
#endif
};
