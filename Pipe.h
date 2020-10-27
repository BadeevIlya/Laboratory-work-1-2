#pragma once
#include <string>
using namespace std;

class Pipe
{
    string id; // идентификатор трубы
    double dlina; // длина 
    int diametr; // диаметр
    bool remont; // признак "в ремонте"

public: 
    friend ostream& operator << (ostream& out, const Pipe& p);
    friend istream& operator >> (istream& in, Pipe& p);
    void ChangeStatusPipe();
    void LoadPipe(ifstream& fin);
    void SavePipe(ofstream& fout, const Pipe& t);
    //friend ifstream& LoadPipe(ifstream& fin, Pipe&p);
};

