#include "KS.h"
#include <iostream>
#include <fstream>


ostream& operator<<(ostream& out, const KS& k)
{
    out << "Введенные данные КС: \n";
    out << "Название:" << k.name << endl << "Количество цехов:" << k.count << endl << "Количество рабочих цехов: " << k.w_count << endl
        << "Эффективность:" << k.effect << endl;
    return out;
}

istream& operator>>(istream& in, KS& k)
{
    cout << "Введите название\n";
    in.get();
    getline(in, k.name);

    while (1) {
        cout << "Введите количество цехов\n";
        in >> k.count;
        cout << "Введите количество рабочих цехов\n";
        in >> k.w_count;
        cout << "Введите эффективноть от 0 до 10\n";
        in >> k.effect;
        if (in.fail()) {
            in.clear();
            in.ignore(10000, '\n');
        }
        else if (k.w_count < 0 || k.w_count>k.count) {
            continue;
        }
        else break;
    }
    k.id = "";
    return in;
}

void KS::ChangeW_Count()
{
    while (1) {
        cout << "Введите новое количество рабочих цехов: \n";
        cin >> w_count;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (w_count > count || w_count < 0) {
            continue;
        }
        else break;
    }
}

void KS:: LoadKS(ifstream& fin) {
    fin >> count >> w_count >> name >> effect;
}


void KS:: SaveKS(ofstream& fout, const KS& k) {
    fout << k.count << endl << k.w_count << endl << k.name << endl << k.effect << endl;
}
