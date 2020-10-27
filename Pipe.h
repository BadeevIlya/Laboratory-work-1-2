#pragma once
#include <string>
using namespace std;

class Pipe
{
    string id; // ������������� �����
    double dlina; // ����� 
    int diametr; // �������
    bool remont; // ������� "� �������"

public: 
    friend ostream& operator << (ostream& out, const Pipe& p);
    friend istream& operator >> (istream& in, Pipe& p);
    void ChangeStatusPipe();
    void LoadPipe(ifstream& fin);
    void SavePipe(ofstream& fout, const Pipe& t);
    //friend ifstream& LoadPipe(ifstream& fin, Pipe&p);
};

