#include <iostream>
#include <fstream>

#include <string.h>

#include <stdlib.h>

#include <iomanip>
#include <ctime>

#include "mylist.h"

using namespace std;

//---------------------	прототипы	функций -------------------------
//реализация пункта	меню "1: Read from the file"
void ReadListFromFile(MyList* lst);
//реализация пункта	меню "3: Add subject"
void AddManufacturerToTheTopOfList(MyList* lst);
void AddManufacturerToTheEndOfList(MyList* lst);
//реализация пункта	меню "4: Save to the file"
void LoadListToFile(MyList* lst);
//реализация пункта	меню "5: Delete subject"
void DeleteManufacturerFromTheTopOfList(MyList* lst);

int main()
{

    cout.setf(ios::left); // выравнивание по левому краю 
    bool flag = true; // флаг продолжения работы
    int choice;	// выбор пользователя
    Phone phone;	// переменная типа телефон
    MyList spisok; // переменная типа Список
    while (flag)

    {
        system("cls"); // очисткаэкрана
        cout << "	MENU" << endl;

        cout << "_____________________" << endl;
        cout << "1: Read from the file" << endl;
        cout << "2: Show list" << endl;
        cout << "3: Add manufacturer to the TOP of List" << endl;
        cout << "4: Add manufacturer to the END of List" << endl;
        cout << "5: Save to the file" << endl;
        cout << "6: Delete the last record from the TOP of List" << endl;
        cout << "7: Clear all List" << endl;
        cout << "8: Show the amount of every manufacturer" << endl;
        cout << "9: Sort the List by Price" << endl;
        cout << "10: Find the key Manufacturer" << endl;
        cout << "11: Find the key RAM" << endl;
        cout << "0: EXIT" << endl;
        cout << "_____________________" << endl << endl;
        cout << "Make your choice (0-11): ";

        cin >> choice;
        switch (choice)
        {

        case 1: ReadListFromFile(&spisok); system("PAUSE"); break;
        case 2: spisok.Show(); system("PAUSE"); break;
        case 3: AddManufacturerToTheTopOfList(&spisok); break;
        case 4: AddManufacturerToTheEndOfList(&spisok); break;
        case 5: LoadListToFile(&spisok); break;
        case 6: DeleteManufacturerFromTheTopOfList(&spisok); break;
        case 7: spisok.Clear(); system("PAUSE"); break;
        case 8: spisok.Amount(); system("PAUSE"); break;
        case 9: spisok.BubbleSort(); system("PAUSE"); break;
        case 10: spisok.Find2(); system("PAUSE"); break;
        case 11: spisok.Find1(); system("PAUSE"); break;
        case 0: flag = false; break;
        default: cout << "You are wrong. " << endl; flag = false; break;

        }
    }
    system("PAUSE");

    return 0;
}

void ReadListFromFile(MyList* lst) {
    if (lst == NULL) {

        cout << "Wrong list!!" << endl;
        return;

    }

    char file_name[30]; // если имя файла задается пользователем

    ifstream fin("student.dat", ios::binary | ios::in);
    cout << "Input file name: ";

    cin >> file_name;
    if (!lst->ReadFromFile(file_name))
        cout << "Wrong File\n";

    else
        cout << "Data is received\n";

}


void AddManufacturerToTheTopOfList(MyList* lst) {
    if (lst == NULL) {
        cout << "Wrong list!!" << endl;

        return;
    }

    Phone	st;
    system("cls"); // Очистка экрана

    cin.ignore(); //Игнорируем символ
    cout << "Manufacturer:	"; cin.getline(st.Manufacturer, 30); //Ввод производителя
    cout << "RAM (gigabytes) :	"; cin >> st.RAM; //Ввод оперативной памяти
    cout << "BatteryCapacity (mAh) :	"; cin >> st.BatteryCapacity; //Ввод емкости аккумулятора 
    cout << "CameraResolution (megapixels) :	"; cin >> st.CameraResolution; //Ввод разрешения камеры 
    cout << "Price ($) :	"; cin >> st.Price; //Ввод стоимости
    lst->AddToTop(&st);

}

void AddManufacturerToTheEndOfList(MyList* lst) {
    if (lst == NULL) {
        cout << "Wrong list!!" << endl;

        return;
    }

    Phone	st;
    system("cls"); // Очистка экрана

    cin.ignore(); //Игнорируем символ
    cout << "Manufacturer:	"; cin.getline(st.Manufacturer, 30); //Ввод производителя
    cout << "RAM (gigabytes) :	"; cin >> st.RAM; //Ввод оперативной памяти
    cout << "BatteryCapacity (mAh) :	"; cin >> st.BatteryCapacity; //Ввод емкости аккумулятора 
    cout << "CameraResolution (megapixels) :	"; cin >> st.CameraResolution; //Ввод разрешения камеры 
    cout << "Price ($) :	"; cin >> st.Price; //Ввод стоимости

    lst->AddToEnd(&st);
}

void DeleteManufacturerFromTheTopOfList(MyList* lst) {
    system("cls"); // Очистка экрана

    cin.ignore(); //Игнорируем символ
    Phone	st;
    lst->DeleteFromTheTop(&st);

}

void LoadListToFile(MyList* lst)
{
    if (lst == NULL)
    {
        cout << "Wrong list!!" << endl;

        return;
    }

    char file_name[30];
    system("cls");

    cout << "Input file name: ";
    cin >> file_name;
    cout << "Begin writing...\n";

    if (lst->LoadToFile(file_name)) //Если открытие файла прошло успешно
    {
        cout << "File created\n";

    }
    else cout << "File is not create\n";
    system("pause");
}
