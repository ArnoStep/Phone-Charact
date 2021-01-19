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

//Деструктор класса List

MyList::~MyList()
{
    Clear();

}

//сортировка пузырьком; Задание №3 из ЛР 6
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

//	очистка списка (удаление всех эл.) 
void MyList::Clear()
{
    while (Head != NULL) //Пока по адресу есть хоть что-то

    {
        Item* temp = Head->next; //Сразу запом. указатель на адрес след. элемента структуры 
        delete Head; //Освобождаем память по месту начала списка

        Head = temp; //Меняем адрес начала списка
    }
    Head = NULL;

}

void MyList::DeleteFromTheTop(Phone* st)
{
    if (Head != NULL)
    {
        Item* temp = Head->next; //Сразу запом. указатель на адрес след. элемента структуры 
        delete Head; //Освобождаем память по месту начала списка

        Head = temp; //Меняем адрес начала списка
    }
}

void MyList::Amount()
{
    system("cls"); // очисткаэкрана
    map <string, int> count;

    Item* p = Head;
    for (int i = 0; p != NULL; ++i)
    {
        count[p->data.Manufacturer]++;
        p = p->next;
    }
    map <string, int>::iterator it = count.begin();
    for (int i = 0; it != count.end(); it++, i++) {  // выводим их
        cout << i << ")  Key: " << it->first << ", Numbers " << it->second << endl;
    }
}

/*функция добавления новой записи в начало списка*/
void MyList::AddToTop(Phone* st) {

    Item* temp = new Item(st); //Выделение памяти под новый элемент 
    temp->next = Head; //Указываем, что адрес следующего элемента это старое начало списка 
    Head = temp; //Смена адреса начала списка

}

/*функция добавления новой записи в конец списка*/
void MyList::AddToEnd(Phone* st)

{
    Item* tmpNewItem = new Item(st); //Выделение памяти под новый элемент

    //если список пустой, то новый эл. это голова списка 
    if (Head == NULL) {
        Head = tmpNewItem;

        return;
    }

    //если список не пустой, то переходим на последний эл. и добавляем в конец 
    Item* p = Head;
    while (p->next != NULL) {

        p = p->next;
    }

    //теперь p указывает на последний эл-т 
    p->next = tmpNewItem; //добавляем новый эл-т в конец
}

/*вывод списка на экран*/
void MyList::Show()

{

    Item* temp = Head; //Объявляем указатель, он указывает на начало 
    system("cls"); // очисткаэкрана

    cout << setw(20) << "Manufacturer" << setw(10) << "RAM" << setw(20) << "BatteryCapacity" << setw(20) << "CameraResolution" << setw(10) << "Price"; // выводзаголовка 

    cout << endl << "______________________________________________________________________________" << endl << endl;

    while (temp != NULL) //Пока по адресу на начало есть данные
    {

        //Выводим все элементы структуры
        cout << endl;
        cout << setw(20) << temp->data.Manufacturer; //Вывод производителя
        cout << setw(10) << temp->data.RAM; //Вывод оперативной памяти
        cout << setw(20) << temp->data.BatteryCapacity; //Вывод емкости аккумулятора 
        cout << setw(20) << temp->data.CameraResolution; //Вывод разрешения камеры 
        cout << setw(10) << temp->data.Price; //Вывод Ввод стоимости
        cout << endl;
        //Переходим на следующий адрес из списка
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

            cout << setw(20) << "Manufacturer" << setw(10) << "RAM" << setw(20) << "BatteryCapacity" << setw(20) << "CameraResolution" << setw(10) << "Price"; // выводзаголовка 

            cout << endl << "______________________________________________________________________________" << endl << endl;
            cout << endl;
            cout << setw(20) << j->data.Manufacturer; //Вывод производителя
            cout << setw(10) << j->data.RAM; //Вывод оперативной памяти
            cout << setw(20) << j->data.BatteryCapacity; //Вывод емкости аккумулятора 
            cout << setw(20) << j->data.CameraResolution; //Вывод разрешения камеры 
            cout << setw(10) << j->data.Price; //Вывод Ввод стоимости
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

            cout << setw(20) << "Manufacturer" << setw(10) << "RAM" << setw(20) << "BatteryCapacity" << setw(20) << "CameraResolution" << setw(10) << "Price"; // выводзаголовка 

            cout << endl << "______________________________________________________________________________" << endl << endl;

            cout << setw(20) << j->data.Manufacturer; //Вывод производителя
            cout << setw(10) << j->data.RAM; //Вывод оперативной памяти
            cout << setw(20) << j->data.BatteryCapacity; //Вывод емкости аккумулятора 
            cout << setw(20) << j->data.CameraResolution; //Вывод разрешения камеры 
            cout << setw(10) << j->data.Price; //Вывод Ввод стоимости
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

//	чтение из файла в тот же список

//	старые элеметы удаляются
bool MyList::ReadFromFile(char* file_name)
{

    //если имя файла отсутствует
    if (file_name == NULL) return false;

    ifstream fin;
    fin.open(file_name, ios::binary | ios::in);
    //Если файл не открыт

    if (!fin) return false;

    //	когда файл открыт ------------------

    Clear();  // удаляем старые элементы

    //в цикле читаем из файла и добавляем в конец списка 
    Phone tmpStud;
    bool isOk;

    while (!fin.eof()) {
        if (fin.peek() != EOF) {
            isOk = tmpStud.read(&fin);

            if (!isOk) {
                fin.close(); //Закрываем файл
                return false;

            }
            AddToEnd(&tmpStud);
        }

    }

    fin.close(); //Закрываем файл

    return true;
}


bool MyList::LoadToFile(char* file_name)
{

    //если имя файла отсутствует
    if (file_name == NULL) return false;

    ofstream fout(file_name, ios::binary | ios::out); //Если файл не открыт

    if (!fout) return false;

    Item* temp = Head; //Объявляем указатель, он указывает на начало списка 
    while (temp != NULL) //Пока по адресу на начало есть данные
    {
        temp->data.write(&fout);

        temp = temp->next; //переходим на следующий адрес из списка 
        if (!fout.good()) {
            fout.close();

            return false; //если ошибка записи
        }
    }

    fout.close();
    return true;
}
