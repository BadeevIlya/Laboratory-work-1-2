#pragma once
#include <string>
using namespace std;
class KS
{
    
public:
    int id; // ������������� ��
    string name; // ���
    int count; // ���������� �����
    int w_count; // ���������� ������� �����
    static int MaxID;
    int effect; // ������������ 

    friend ostream& operator << (ostream& out, const KS& k);
    friend istream& operator >> (istream& in, KS& k);
};

