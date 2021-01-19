#pragma once

/*структура телефон*/

#include <fstream>

struct Phone
{
	char Manufacturer[30]; // производитель
	int RAM; // оперативная память
	int BatteryCapacity; // емкость аккумулятора
	int CameraResolution; //разрешение  камеры
	int Price; //стоимость

	//метод записи данных в файл

	//поток должен быть уже открыт
	bool write(std::ofstream* fout);

	//метод чтения данных из файла

	//поток должен быть уже открыт
	bool read(std::ifstream* fin);
};
