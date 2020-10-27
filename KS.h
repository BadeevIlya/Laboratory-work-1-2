#pragma once
#include <string>
using namespace std;
class KS
{
    string id; // ������������� ��
    string name; // ���
    int count; // ���������� �����
    int w_count; // ���������� ������� �����
    int effect; // ������������ 
public:
    friend ostream& operator << (ostream& out, const KS& k);
    friend istream& operator >> (istream& in, KS& k);
    void ChangeW_Count();
    void SaveKS(ofstream& fout, const KS& k);
    void LoadKS(ifstream& fin);
};

