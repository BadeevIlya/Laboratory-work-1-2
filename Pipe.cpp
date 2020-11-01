#include "Pipe.h"
#include <iostream>
#include "utils.h"
#include <fstream>

int Pipe::MaxID;

ostream& operator << (ostream& out, const Pipe& p)
{
	out << "����� id " <<p.id<< endl;
    out << "�������: " << p.diametr << endl << "�����: " << p.dlina << endl;
	return out;
}

istream& operator>>(istream& in, Pipe& p)
{
    p.id = Pipe::MaxID++;
    p.diametr = GetCorrectNumber("������� �������", 1, 10000);
    p.dlina = GetCorrectNumber("������� �����", 1.0, 10000.0);
    p.remont = false;
    return in;
}





