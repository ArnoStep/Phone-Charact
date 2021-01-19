#include "Phone.h"

using namespace std;

//������ ��������� Phone -------------------------
bool Phone::write(ofstream* fout) {

    //���� ���� �� ������
    if (!fout) return false;
    //����������

    fout->write((char*)this, sizeof(Phone));
    if (fout->good())
        return true;

    //else
    return false;
}

//����� ������ ������ �� �����
//����� ������ ���� ��� ������

bool Phone::read(ifstream* fin) {
    //���� ���� �� ������
    if (!fin) return false;

    if (fin->peek() == EOF) return false;
    fin->read((char*)this, sizeof(Phone));
    if (fin->good())

        return true;

    //else

    return false;
}
