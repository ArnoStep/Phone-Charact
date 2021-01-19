#include <iostream>
#include <fstream>
#include <string.h>
#include <map>

#include <stdlib.h>
#include <iomanip>

#include "item.h"
#include "mylist.h"
#include "Phone.h"

using namespace std;

//���������� ������ List

MyList::~MyList()
{
    Clear();

}

//���������� ���������; ������� �3 �� �� 6
void MyList::BubbleSort()
{
    int tmp;
    for (Item* i = Head; i != NULL; i = i->next)
    {
        for (Item* j = Head; j != NULL; j = j->next)
        {
            if (j->next != NULL && j->data.Price < j->next->data.Price)
            {
                swap(j->data.Manufacturer, j->next->data.Manufacturer);
                swap(j->data.RAM, j->next->data.RAM);
                swap(j->data.BatteryCapacity, j->next->data.BatteryCapacity);
                swap(j->data.CameraResolution, j->next->data.CameraResolution);
                swap(j->data.Price, j->next->data.Price);
            }
        }
    }
}

//	������� ������ (�������� ���� ��.) 
void MyList::Clear()
{
    while (Head != NULL) //���� �� ������ ���� ���� ���-��

    {
        Item* temp = Head->next; //����� �����. ��������� �� ����� ����. �������� ��������� 
        delete Head; //����������� ������ �� ����� ������ ������

        Head = temp; //������ ����� ������ ������
    }
    Head = NULL;

}

void MyList::DeleteFromTheTop(Phone* st)
{
    if (Head != NULL)
    {
        Item* temp = Head->next; //����� �����. ��������� �� ����� ����. �������� ��������� 
        delete Head; //����������� ������ �� ����� ������ ������

        Head = temp; //������ ����� ������ ������
    }
}

void MyList::Amount()
{
    system("cls"); // �������������
    map <string, int> count;

    Item* p = Head;
    for (int i = 0; p != NULL; ++i)
    {
        count[p->data.Manufacturer]++;
        p = p->next;
    }
    map <string, int>::iterator it = count.begin();
    for (int i = 0; it != count.end(); it++, i++) {  // ������� ��
        cout << i << ")  Key: " << it->first << ", Numbers " << it->second << endl;
    }
}

/*������� ���������� ����� ������ � ������ ������*/
void MyList::AddToTop(Phone* st) {

    Item* temp = new Item(st); //��������� ������ ��� ����� ������� 
    temp->next = Head; //���������, ��� ����� ���������� �������� ��� ������ ������ ������ 
    Head = temp; //����� ������ ������ ������

}

/*������� ���������� ����� ������ � ����� ������*/
void MyList::AddToEnd(Phone* st)

{
    Item* tmpNewItem = new Item(st); //��������� ������ ��� ����� �������

    //���� ������ ������, �� ����� ��. ��� ������ ������ 
    if (Head == NULL) {
        Head = tmpNewItem;

        return;
    }

    //���� ������ �� ������, �� ��������� �� ��������� ��. � ��������� � ����� 
    Item* p = Head;
    while (p->next != NULL) {

        p = p->next;
    }

    //������ p ��������� �� ��������� ��-� 
    p->next = tmpNewItem; //��������� ����� ��-� � �����
}

/*����� ������ �� �����*/
void MyList::Show()

{

    Item* temp = Head; //��������� ���������, �� ��������� �� ������ 
    system("cls"); // �������������

    cout << setw(20) << "Manufacturer" << setw(10) << "RAM" << setw(20) << "BatteryCapacity" << setw(20) << "CameraResolution" << setw(10) << "Price"; // �������������� 

    cout << endl << "______________________________________________________________________________" << endl << endl;

    while (temp != NULL) //���� �� ������ �� ������ ���� ������
    {

        //������� ��� �������� ���������
        cout << endl;
        cout << setw(20) << temp->data.Manufacturer; //����� �������������
        cout << setw(10) << temp->data.RAM; //����� ����������� ������
        cout << setw(20) << temp->data.BatteryCapacity; //����� ������� ������������ 
        cout << setw(20) << temp->data.CameraResolution; //����� ���������� ������ 
        cout << setw(10) << temp->data.Price; //����� ���� ���������
        cout << endl;
        //��������� �� ��������� ����� �� ������
        temp = temp->next;

    }

    cout << endl << "______________________________________________________________________________" << endl << endl;

}

void MyList::Find1()
{
    int key, q = 0;
    system("cls");
    cout << "Enter the key RAM ($) : ";
    cin >> key;
    for (Item* j = Head; j != NULL; j = j->next)
    {
        q++;
        if (j->data.RAM == key)
        {
            cout << endl << endl << "The number in the List of key RAM : " << q << endl << endl;

            cout << setw(20) << "Manufacturer" << setw(10) << "RAM" << setw(20) << "BatteryCapacity" << setw(20) << "CameraResolution" << setw(10) << "Price"; // �������������� 

            cout << endl << "______________________________________________________________________________" << endl << endl;
            cout << endl;
            cout << setw(20) << j->data.Manufacturer; //����� �������������
            cout << setw(10) << j->data.RAM; //����� ����������� ������
            cout << setw(20) << j->data.BatteryCapacity; //����� ������� ������������ 
            cout << setw(20) << j->data.CameraResolution; //����� ���������� ������ 
            cout << setw(10) << j->data.Price; //����� ���� ���������
            cout << endl << endl;
            break;
        }
        if (j->next == NULL)
        {
            cout << endl << endl << "There is no such RAM" << endl;
            break;
        }
    }
}

void MyList::Find2()
{
    string key;
    int q = 0;
    system("cls");
    cout << "Enter the key MANUFACTURER (ex. Apple) : ";
    cin >> key;
    for (Item* j = Head; j != NULL; j = j->next)
    {
        q++;
        if (j->data.Manufacturer == key)
        {

            cout << endl << endl << "The number in the List of key manufacturer : " << q << endl << endl;

            cout << setw(20) << "Manufacturer" << setw(10) << "RAM" << setw(20) << "BatteryCapacity" << setw(20) << "CameraResolution" << setw(10) << "Price"; // �������������� 

            cout << endl << "______________________________________________________________________________" << endl << endl;

            cout << setw(20) << j->data.Manufacturer; //����� �������������
            cout << setw(10) << j->data.RAM; //����� ����������� ������
            cout << setw(20) << j->data.BatteryCapacity; //����� ������� ������������ 
            cout << setw(20) << j->data.CameraResolution; //����� ���������� ������ 
            cout << setw(10) << j->data.Price; //����� ���� ���������
            cout << endl << endl;
            break;
        }
        if (j->next == NULL)
        {
            cout << endl << endl << "There is no such MANUFACTURER" << endl;
            break;
        }
    }
}

//	������ �� ����� � ��� �� ������

//	������ ������� ���������
bool MyList::ReadFromFile(char* file_name)
{

    //���� ��� ����� �����������
    if (file_name == NULL) return false;

    ifstream fin;
    fin.open(file_name, ios::binary | ios::in);
    //���� ���� �� ������

    if (!fin) return false;

    //	����� ���� ������ ------------------

    Clear();  // ������� ������ ��������

    //� ����� ������ �� ����� � ��������� � ����� ������ 
    Phone tmpStud;
    bool isOk;

    while (!fin.eof()) {
        if (fin.peek() != EOF) {
            isOk = tmpStud.read(&fin);

            if (!isOk) {
                fin.close(); //��������� ����
                return false;

            }
            AddToEnd(&tmpStud);
        }

    }

    fin.close(); //��������� ����

    return true;
}


bool MyList::LoadToFile(char* file_name)
{

    //���� ��� ����� �����������
    if (file_name == NULL) return false;

    ofstream fout(file_name, ios::binary | ios::out); //���� ���� �� ������

    if (!fout) return false;

    Item* temp = Head; //��������� ���������, �� ��������� �� ������ ������ 
    while (temp != NULL) //���� �� ������ �� ������ ���� ������
    {
        temp->data.write(&fout);

        temp = temp->next; //��������� �� ��������� ����� �� ������ 
        if (!fout.good()) {
            fout.close();

            return false; //���� ������ ������
        }
    }

    fout.close();
    return true;
}
