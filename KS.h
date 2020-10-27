#pragma once
#include <string>
using namespace std;
class KS
{
    string id; // идентификатор КС
    string name; // имя
    int count; // количество цехов
    int w_count; // количество рабочих цехов
    int effect; // эффективноть 
public:
    friend ostream& operator << (ostream& out, const KS& k);
    friend istream& operator >> (istream& in, KS& k);
    void ChangeW_Count();
    void SaveKS(ofstream& fout, const KS& k);
    void LoadKS(ifstream& fin);
};

