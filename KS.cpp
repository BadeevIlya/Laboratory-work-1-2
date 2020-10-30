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
    out << "КС "<<k.id <<endl;
    out << "Название:" << k.name << endl << "Количество цехов:" << k.count << endl << "Количество рабочих цехов: " << k.w_count << endl
        << "Эффективность:" << k.effect << endl;
    return out;
}

istream& operator>>(istream& in, KS& k)
{
    cout << "Введите название КС:  ";
    in.get();
    getline(in, k.name);
    k.count = GetCorrectNumber("Введите количество цехов", 0, 10000);
    k.w_count = GetCorrectNumber("Введите количество рабочих цехов", 0, k.count);;
    k.effect = GetCorrectNumber("Введите эффективноть от 0 до 10", 0 , 10);    
    return in;
}
