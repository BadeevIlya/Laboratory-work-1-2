#include "KS.h"
#include <iostream>
#include <fstream>
#include "utils.h"

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
