#include "KS.h"
#include <iostream>
#include <fstream>
#include "utils.h"

int KS::MaxID;

ostream& operator<<(ostream& out, const KS& k)
{
    out << "�� id "<<k.id <<endl;
    out << "��������:" << k.name << endl << "���������� �����:" << k.count << endl << "���������� ������� �����: " << k.w_count << endl
        << "�������������:" << k.effect << endl;
    return out;
}

istream& operator>>(istream& in, KS& k)
{
    k.id = k.MaxID++;
    cout << "������� �������� ��:  ";
    in.get();
    getline(in, k.name);
    k.count = GetCorrectNumber("������� ���������� �����", 1, 10000);
    k.w_count = GetCorrectNumber("������� ���������� ������� �����", 0, k.count);;
    k.effect = GetCorrectNumber("������� ������������ �� 1 �� 10", 1 , 10);    
    return in;
}
