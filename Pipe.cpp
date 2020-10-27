#include "Pipe.h"
#include <iostream>
#include <fstream>


ostream& operator << (ostream& out, const Pipe& p)
{
	out << "¬веденные данные трубы:\n";
	out << "ƒиаметр: " << p.diametr << endl << "ƒлина: " << p.dlina << endl;
	return out;
}

istream& operator>>(istream& in, Pipe& p)
{
    while (1) {
        cout << "¬ведите диаметр\n";
        in >> p.diametr;
        cout << "¬ведите длину\n";
        in >> p.dlina;
        if (in.fail()) {
            in.clear();
            in.ignore(10000, '\n');
        }
        else if (p.diametr < 0 || p.dlina < 0) {
            continue;
        }
        else break;
    }
    p.remont = false;
    return in;
}

//ifstream& LoadPipe(ifstream& fin, Pipe&p)
//{
//    fin >> p.diametr >> p.dlina;
//}

void Pipe::LoadPipe(ifstream& fin)
{
    fin >> diametr >> dlina;
}


void Pipe::ChangeStatusPipe()
{
    remont = !remont;
}


void Pipe::SavePipe(ofstream& fout, const Pipe& t) {
    fout << t.diametr << endl << t.dlina << endl;
}

