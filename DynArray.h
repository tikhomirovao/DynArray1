#pragma once
#include <iostream>
#include <windows.h> //� ������ ������, ��� ���� ����-����� ��������
//����� �������������� �������������� ���������
#include <stdlib.h>
#include <time.h>
#include <initializer_list> //����� ��� ������������� ����� ������������ ��������(��������������� ��������� �������������)
#include <assert.h> //������ assert - ������� �� ����� ������� ��������� ��������� �� ������ � ��������� ������ ���������
#include <malloc.h> //���������� � ���������� ��� ������ � �������
#include <limits>


using namespace std;

//����� ����������� ������������ ���������� ������ ��������� ���� ������ int
class DynArray
{
	//private:
		//int size = 0; //���-�� ���������
		//unsigned int size = 0; //���-�� ���������
	size_t size = (size_t)0; //���-�� ���������
	int* array = nullptr; //��������� �� �������� ���� ������ int
public:
	DynArray(char) = delete; //�������� ����������� � char � �������� ���������
	DynArray() = default; //default - ������� ����������� �������� ��������������� ���������� ������������
	//DynArray(){cout<<"�������� ����������� �� ��������� ��� ������� "<<this<<endl; } //��� �����!
	//����������� � �����������
	explicit DynArray(size_t); //explicit DynArray(unsigned int);
	//����������� �����������
	DynArray(const DynArray&); //��������� ����������� lvalue ������
	//����������� �����������
	DynArray(DynArray&&); //rvalue ������ � �������� ��������� ��������� ��������� ���������� rvalue ������ ������ DynArray
	//����������� ����������� ������ ��� ���������� ����������� �� ������ �������(���������� �����������) ������ DynArray
	//� ������(����� ���������� �����������) ������ ������ DynArray ��� ��� �������� 
	//����������� ��������� �������������
	DynArray(const initializer_list<int>&); //����������� ������ �� ������ ���������� ������ initializer_list, � ����� ������ int ������
	//����������
	~DynArray();
	//�������:
	//����� ���������� ������� ���������� ������� �� ���������� �� ���������� �����
	//����� �������� ��������� ��������� �����!
	void Randomize(int, int);
	//����� ��������� ������� ������� ������ ������� ������ DynArray
	void ReSize(size_t); //void ReSize(unsigned int);
	//�������:
	//����� ��������� �������� ������� �������(���-�� ���������)
	size_t Size()const; //unsigned int Size()const;

	// �������� ������ ���������� �������
	void Sort();

	//���������� ���������� ��� ������� ������:
	//���������� ��������� �������������� []
	int& operator[](int); //��� ������ � ������ ��� ����������(�������) �������� ������ DynArray(��� ������� ���������� ���� ������ int)
	//����������� ���������� ��������� �������������� []
	const int operator[](int)const; //��� ������ ��� ����������� �������� ������ DynArray(��� ������� �������� ���� ������ int)
	//���������� ��������� ����������� ������������
	DynArray& operator=(const DynArray&);
	//���������� ��������� ������������� ������������
	DynArray& operator=(DynArray&&); //rvalue ������ � �������� ��������� ��������� ��������� ���������� rvalue ������ ������ DynArray
	//�������� ������������� ������������ ������ ��� ���������� ����������� �� ������ �������(���������� �����������) ������ DynArray
	//� ������(���������� �����������) ������ ������ DynArray ��� ������������ � ����
	//���������� ��������� �������� �� ��������� ==
	bool operator==(const DynArray&)const; //��� ��������� �� ����� ���� �������� ���������� ������������ ��������
	//���������� ��������� �������� �� ��������� !=
	bool operator!=(const DynArray&)const; //��� ��������� �� ����� ���� �������� ���������� ������������ ��������

	//���������� ���������� ������ � ������������ �������
	void* operator new(size_t); //size_t - ��� unsigned int ��� unsigned long long
	void operator delete(void*);
	void* operator new[](size_t);
	void operator delete[](void*);

	//���������� ��������� �������� ��� �������� DynArray+int
	DynArray operator+(int Digit);
	//���������� ��������� ��������� ��� �������� DynArray-int
	DynArray operator-(int Digit);
	//���������� ��������� ��������� ��� �������� DynArray*int
	DynArray operator*(int Digit);
	//���������� ��������� ������� ��� �������� DynArray/int
	DynArray operator/(int Digit);


	//������������� ���������� ��������� �������� ��� �������� int + DynArray
	friend DynArray operator+(int Digit, const DynArray&);
	//������������� ���������� ��������� ��������� ��� �������� int - DynArray
	friend DynArray operator-(int Digit, const DynArray&);
	//������������� ���������� ��������� ��������� ��� �������� int * DynArray
	friend DynArray operator*(int Digit, const DynArray&);
	//������������� ���������� ��������� ������� ��� �������� int / DynArray
	friend DynArray operator/(int Digit, const DynArray&);

	//������������� ���������� ����������:
	//���������� ��������� ������
	friend ostream& operator<<(ostream&, const DynArray&);
	//���������� ��������� �����
	friend istream& operator>>(istream&, DynArray&);
};
//�������� ���������� ���������� ��������� �������� + (�������� �������� �����������)
DynArray operator+(const DynArray&, const DynArray&); //���������� �������� ���������� ����������� �������
//������ ������� ��������� ����������
template<typename T> inline void SetValue(T& Value)
{
#ifdef max //��������� ���� �� define max
#undef max //���� ���� - ���������
#define MAX //define ��� �����������, ��� �������� max()
#endif

	cin.exceptions(istream::badbit | istream::failbit); //�������� ��������� ���������� ��� ������ istream, ����� ������ cin
	//cout.exceptions(ostream::badbit | ostream::failbit); //�������� ��������� ���������� ��� ������ ostream, ����� ������ cout

	try //� ���� �������� ���, ��� ����� ������� ��������� ����������
	{
		cin >> Value; //throw istream::failure;
		//cin.operator>>(Value);
		//���� ����� ����� ������ ������ 5t ��� ��� ����� ������� ������� ������ �������
		//cin.ignore(32767,'\n'); //������� ������(�������������) �� 32767��������, ���� �� ������ \n
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //�������(�������������) ����� ������ �� ��� ����������� �����
	}
	//catch (const istream::failure& exp) //���� ����� ������ ������ ������ istream::failure
	catch (const istream::failure&)
	{
		//catch ��������� ������ ���� �������� >> ��������� ��� ������� cin
		//����������� ���������� ���� throw istream::failure;
		//cout << exp.what() << endl;
		//cout << exp.code() << endl;

		//���������  ������� ��������� �� ����� ������
		int OCP = GetConsoleOutputCP();
		//���� �� �������� ������ �� ������
		if (OCP != 1251)SetConsoleOutputCP(1251);
		cout << "������������ ����!" << endl;

		if (cin.fail()) //���� ����� ������� � ��������� fail
		{
			cin.clear(); //���������� ����� � "�������" �����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //�������(�������������) ����� ������ �� ��� ����������� �����
		}
		cout << "���������� ��� ���!" << endl;
		//����������� ���������, ���� ��������
		if (OCP != 1251)SetConsoleOutputCP(OCP);
		SetValue(Value);//�������� ����� �������� ���������(����������� ������)
	}
#ifdef MAX
#define max(a,b) (((a) > (b)) ? (a) : (b))
#undef MAX
#endif
};
