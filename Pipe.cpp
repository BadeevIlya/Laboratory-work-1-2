#include "Pipe.h"
#include <iostream>
#include "utils.h"
#include <fstream>

int Pipe::MaxID = 0 ;

Pipe::Pipe() {
    id = MaxID++;
    remont = false;

}

ostream& operator << (ostream& out, const Pipe& p)
{
	out << "Труба " <<p.id<< endl;
    out << "Диаметр: " << p.diametr << endl << "Длина: " << p.dlina << endl;
	return out;
}

istream& operator>>(istream& in, Pipe& p)
{
    p.diametr = GetCorrectNumber("Введите диаметр", 0, 10000);
    p.dlina = GetCorrectNumber("Введите длину", 0.0, 10000.0);
    return in;
}





