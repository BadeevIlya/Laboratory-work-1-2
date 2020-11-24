#include "KS.h"
#include <iostream>
#include <fstream>
#include "utils.h"
#include <map>


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

void KS:: ChangeW_Count(KS& k) // ������� ��� ��������� ���������� ������� �����
{
    k.w_count = GetCorrectNumber("������� ����� ���������� ������� �����", 0, k.count);
}

void KS:: SaveKS(ofstream& fout, const KS& k) {
    fout << k.id << endl << k.name << endl << k.count << endl << k.w_count << endl << k.effect << endl;
}

KS KS:: LoadKS(ifstream& fin) {
    KS k;
    fin >> k.id >> k.name >> k.count >> k.w_count >> k.effect;
    return k;
}

int KS::GetKS_ID(map< int, KS>& ksgroup) {
    int i = 0;
    while (1) {
        int id = GetCorrectNumber("������� id", 0, 10000);
        for (auto& k : ksgroup) {
            if (k.second.id == id)
                return i;
            i++;
        }
        cout << "������ id �� ����������" << endl;
        i = 0;
    }
}
