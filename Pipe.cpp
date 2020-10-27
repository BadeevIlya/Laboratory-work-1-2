#include "Pipe.h"
#include <iostream>
#include <fstream>


ostream& operator << (ostream& out, const Pipe& p)
{
	out << "��������� ������ �����:\n";
	out << "�������: " << p.diametr << endl << "�����: " << p.dlina << endl;
	return out;
}

istream& operator>>(istream& in, Pipe& p)
{
    while (1) {
        cout << "������� �������\n";
        in >> p.diametr;
        cout << "������� �����\n";
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

