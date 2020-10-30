#pragma once
#include <string>

using namespace std;


class Pipe
{
   
public:
    int id; // идентификатор трубы
    double dlina; // длина 
    int diametr; // диаметр
    bool remont; // признак "в ремонте"
    string name;
    static int MaxID; //


    Pipe();
    friend ostream& operator << (ostream& out, const Pipe& p);
    friend istream& operator >> (istream& in, Pipe& p);
};




