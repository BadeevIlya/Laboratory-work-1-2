#pragma once
#include <string>

using namespace std;


class Pipe
{
   
public:
    int id; // ������������� �����
    double dlina; // ����� 
    int diametr; // �������
    bool remont; // ������� "� �������"
    string name;
    static int MaxID; //


    Pipe();
    friend ostream& operator << (ostream& out, const Pipe& p);
    friend istream& operator >> (istream& in, Pipe& p);
};




