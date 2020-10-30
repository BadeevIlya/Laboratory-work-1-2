#include "KS.h"
#include <iostream>
#include <fstream>
#include "utils.h"

int KS::MaxID = 0;

KS::KS() {
    id = MaxID++;
}

ostream& operator<<(ostream& out, const KS& k)
{
    out << "�� "<<k.id <<endl;
    out << "��������:" << k.name << endl << "���������� �����:" << k.count << endl << "���������� ������� �����: " << k.w_count << endl
        << "�������������:" << k.effect << endl;
    return out;
}

istream& operator>>(istream& in, KS& k)
{
    cout << "������� �������� ��:  ";
    in.get();
    getline(in, k.name);
    k.count = GetCorrectNumber("������� ���������� �����", 0, 10000);
    k.w_count = GetCorrectNumber("������� ���������� ������� �����", 0, k.count);;
    k.effect = GetCorrectNumber("������� ������������ �� 0 �� 10", 0 , 10);    
    return in;
}
