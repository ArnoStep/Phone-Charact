#pragma once

#include "Phone.h"
#include "item.h"

class MyList
{

	Item* Head; //Указатель на начало списка 
public:
	MyList() :Head(NULL) {}; //Конструктор по умолчанию (Head = NULL)

	~MyList();//Деструктор

	void AddToTop(Phone* st); // добавление записи в начало списка 
	void AddToEnd(Phone* st); // добавление записи в конец списка 
	void Show(); // вывод списка на экран
	void Clear(); // очистка списка (удаление всех эл.)
	void DeleteFromTheTop(Phone* st);
	void Amount();
	bool LoadToFile(char* file_name); // сохранение списка в файл
	void BubbleSort(); //сортировка выбором
	void Find1();
	void Find2();

	bool ReadFromFile(char* file_name); // чтение из файла в тот же список 
	bool isEmpty()
	{
		if (Head == NULL) return true;

		else return false;
	}
};
