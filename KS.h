#pragma once
#include <string>
#include <map>

using namespace std;
class KS
{
    
public:
    int id; // идентификатор КС
    string name; // имя
    int count; // количество цехов
    int w_count; // количество рабочих цехов
    static int MaxID;
    int effect; // эффективноть 

    friend ostream& operator << (ostream& out, const KS& k);
    friend istream& operator >> (istream& in, KS& k);

    void ChangeW_Count(KS& k);
    void SaveKS(ofstream& fout, const KS& k);
    KS LoadKS(ifstream& fin);
    int GetKS_ID(map< int, KS>& ksgroup);
};

