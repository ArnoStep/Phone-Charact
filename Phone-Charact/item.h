#pragma once
#include "Phone.h"

//Элемент односвязного списка
struct Item {
	Phone data;

	Item* next;
	//конструктор
	Item(Phone* st) {

		//копируем поля из параметра st в поле data
		strcpy_s(data.Manufacturer, st->Manufacturer);
		data.RAM = st->RAM;
		data.BatteryCapacity = st->BatteryCapacity;
		data.CameraResolution = st->CameraResolution;
		data.Price = st->Price;
		next = NULL;
	}
};
