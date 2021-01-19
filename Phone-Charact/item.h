#pragma once
#include "Phone.h"

//������� ������������ ������
struct Item {
	Phone data;

	Item* next;
	//�����������
	Item(Phone* st) {

		//�������� ���� �� ��������� st � ���� data
		strcpy_s(data.Manufacturer, st->Manufacturer);
		data.RAM = st->RAM;
		data.BatteryCapacity = st->BatteryCapacity;
		data.CameraResolution = st->CameraResolution;
		data.Price = st->Price;
		next = NULL;
	}
};
