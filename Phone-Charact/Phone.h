#pragma once

/*��������� �������*/

#include <fstream>

struct Phone
{
	char Manufacturer[30]; // �������������
	int RAM; // ����������� ������
	int BatteryCapacity; // ������� ������������
	int CameraResolution; //����������  ������
	int Price; //���������

	//����� ������ ������ � ����

	//����� ������ ���� ��� ������
	bool write(std::ofstream* fout);

	//����� ������ ������ �� �����

	//����� ������ ���� ��� ������
	bool read(std::ifstream* fin);
};
