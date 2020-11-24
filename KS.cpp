#include "KS.h"
#include <iostream>
#include <fstream>
#include "utils.h"
#include <map>


int KS::MaxID;

ostream& operator<<(ostream& out, const KS& k)
{
    out << "КС id "<<k.id <<endl;
    out << "Название:" << k.name << endl << "Количество цехов:" << k.count << endl << "Количество рабочих цехов: " << k.w_count << endl
        << "Эффективность:" << k.effect << endl;
    return out;
}

istream& operator>>(istream& in, KS& k)
{
    k.id = k.MaxID++;
    cout << "Введите название КС:  ";
    in.get();
    getline(in, k.name);
    k.count = GetCorrectNumber("Введите количество цехов", 1, 10000);
    k.w_count = GetCorrectNumber("Введите количество рабочих цехов", 0, k.count);;
    k.effect = GetCorrectNumber("Введите эффективноть от 1 до 10", 1 , 10);    
    return in;
}

void KS:: ChangeW_Count(KS& k) // функция для изменения количества рабочих цехов
{
    k.w_count = GetCorrectNumber("Введите новое количество рабочих цехов", 0, k.count);
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
        int id = GetCorrectNumber("Введите id", 0, 10000);
        for (auto& k : ksgroup) {
            if (k.second.id == id)
                return i;
            i++;
        }
        cout << "Такого id не существует" << endl;
        i = 0;
    }
}
