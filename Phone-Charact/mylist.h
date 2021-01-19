#pragma once

#include "Phone.h"
#include "item.h"

class MyList
{

	Item* Head; //��������� �� ������ ������ 
public:
	MyList() :Head(NULL) {}; //����������� �� ��������� (Head = NULL)

	~MyList();//����������

	void AddToTop(Phone* st); // ���������� ������ � ������ ������ 
	void AddToEnd(Phone* st); // ���������� ������ � ����� ������ 
	void Show(); // ����� ������ �� �����
	void Clear(); // ������� ������ (�������� ���� ��.)
	void DeleteFromTheTop(Phone* st);
	void Amount();
	bool LoadToFile(char* file_name); // ���������� ������ � ����
	void BubbleSort(); //���������� �������
	void Find1();
	void Find2();

	bool ReadFromFile(char* file_name); // ������ �� ����� � ��� �� ������ 
	bool isEmpty()
	{
		if (Head == NULL) return true;

		else return false;
	}
};
