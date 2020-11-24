#pragma once
#include <string>
#include <map>


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

    friend ostream& operator << (ostream& out, const Pipe& p);
    friend istream& operator >> (istream& in, Pipe& p);
    void ChangeStatusPipe(Pipe& p);
    void SavePipe(ofstream& fout, const Pipe& p);
    Pipe LoadPipe(ifstream& fin);
    int GetPipeID(map< int, Pipe>& p);
};




