#include "Phone.h"

using namespace std;

//методы структуры Phone -------------------------
bool Phone::write(ofstream* fout) {

    //Если файл не открыт
    if (!fout) return false;
    //записываем

    fout->write((char*)this, sizeof(Phone));
    if (fout->good())
        return true;

    //else
    return false;
}

//метод чтения данных из файла
//поток должен быть уже открыт

bool Phone::read(ifstream* fin) {
    //Если файл не открыт
    if (!fin) return false;

    if (fin->peek() == EOF) return false;
    fin->read((char*)this, sizeof(Phone));
    if (fin->good())

        return true;

    //else

    return false;
}
