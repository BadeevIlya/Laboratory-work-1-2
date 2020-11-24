#include "Pipe.h"
#include <iostream>
#include "utils.h"
#include <fstream>
#include <map>


int Pipe::MaxID;

ostream& operator << (ostream& out, const Pipe& p)
{
	out << "Труба id " <<p.id<< endl;
    out << "Диаметр: " << p.diametr << endl << "Длина: " << p.dlina << endl <<"Статус ремонта[0,1]: " << p.remont<<endl;
	return out;
}

istream& operator>>(istream& in, Pipe& p)
{
    p.id = Pipe::MaxID++;
    p.diametr = GetCorrectNumber("Введите диаметр", 1, 10000);
    p.dlina = GetCorrectNumber("Введите длину", 1.0, 10000.0);
    p.remont = false;
    return in;
}

void Pipe:: ChangeStatusPipe(Pipe& p) // функция для отправки трубы на ремонт
{
    p.remont = !p.remont;
}

void Pipe:: SavePipe(ofstream& fout, const Pipe& p) {
    fout << p.id << endl << p.diametr << endl << p.dlina << endl << p.remont << endl;
}

Pipe Pipe:: LoadPipe(ifstream& fin) {
    Pipe p;
    fin >> p.id >> p.diametr >> p.dlina >> p.remont;
    return p;
}

int Pipe:: GetPipeID(map< int, Pipe>& pipeline) {
    int i = 1;
    while (1) {
        int id = GetCorrectNumber("Введите id", 0, 10000);
        for (auto& p : pipeline) {
            if (p.second.id == id)
                return i;
            i++;
        }
        cout << "Такого id не существует" << endl;
        i = 1;
    }
}


