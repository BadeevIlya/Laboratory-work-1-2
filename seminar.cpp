

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Pipe.h"
#include "KS.h"
#include "utils.h"
#include <map>

using namespace std;

int LoadMaxID() { // ������� ��������� �� ����� ������������ ID
    ifstream fin("D:\ MaxID.txt");
    if (fin.is_open())
        fin >> Pipe::MaxID >> KS::MaxID;
    fin.close();
    return 0;
}

void SaveMaxID() { // ������� ��� ���������� ������������� ID
    ofstream fout("D:\ MaxID.txt");
    if (fout.is_open())
        fout << Pipe::MaxID << endl << KS::MaxID;
    fout.close();
}


void DeletePipe(map<int, Pipe>& pipeline) {
    Pipe p;
    pipeline.erase(p.GetPipeID(pipeline));
}


void DeleteKS(map<int, KS>& ksgroup) {
    KS k;
    ksgroup.erase(k.GetKS_ID(ksgroup));
}


bool CheckStatusRemont(const Pipe& p, bool parametr) { //�������-������ ��� ���������� ���� ���� �� �������
    return p.remont == parametr;
}

bool CheckNameKS(const KS& k, string parametr) { //�������-������ ��� ���������� �� �� �����
    return k.name == parametr;
}

bool CheckUnworkKS(const KS& k, double parametr) { //�������-������ ��� ���������� �� �� ��������� �������� ������� �����
    double i = (1 - (double)k.w_count/(double)k.count)*100 ;
    return i == parametr;
}

bool CheckPipeId(const Pipe& p, int parametr) { // �������-������ ��� ���������� ����� �� id 
    return p.id == parametr;
}

string GetFileName() {
    string file;
    cout << " ������� �������� �����: " << endl;
    cin.get();
    getline(cin, file);
    return file;
}



void printMenu() {
    cout << "1. ������� �����\n"
        << "2. ������� ��\n"
        << "3. ������� ������ �� �����\n"
        << "4. ������ ������ � ����\n"
        << "5. ��������� ����� �� ������\n"
        << "6. ������ ����� ���������� ������� �����\n"
        << "7. ����� ������ �����\n"
        << "8. ����� ������ ��\n"
        << "9. ������� �����\n"
        << "10. ������� ��\n"
        << "11. ������ ���� �� id\n"
        << "12. �������� ����� �� �������\n"
        << "13. ����� �� �� ��������\n"
        << "14. ����� �� �� �������� ������� �����\n"
        << "15. �������� ��������������\n"
        << "0. �����\n"
        << "�������� ��������";
}

int main(){
    setlocale(LC_ALL, "rus");
  //  vector <Pipe> pipeline;
//    vector <KS> ksgroup;
    map <int, Pipe> pipeline;
    map <int, KS> ksgroup;
    int p_index = 1;
    int k_index = 1;
    LoadMaxID();
    while (1) {
        printMenu();
        switch (GetCorrectNumber("", 0,15)) {
        case 1:
        {
            Pipe p;
            cin >> p;
            pipeline.emplace(p_index, p);
            p_index++;
            break;
        }
        case 2: {
            KS k;
            cin >> k;
            ksgroup.emplace(k_index, k);
            k_index++;
            break;
        }
        case 3: {
            ifstream fin("D:\ results.txt");
            Pipe p;
            KS k;
            if (fin.is_open()) {
                pipeline.clear();
                ksgroup.clear();
                int p_count, ks_count;
                fin >> p_count >> ks_count;
                while (p_count--) {
                    pipeline.emplace(p_index, p.LoadPipe(fin));
                    p_index++;
                }
                while (ks_count--){
                    ksgroup.emplace(k_index, k.LoadKS(fin));
                    k_index++;
                }
                fin.close();
            }
            break;
        }
        case 4: {
            if (!pipeline.empty() & !ksgroup.empty()) {
                //GetFileName();
                ofstream fout("D:\ results.txt");
                Pipe p;
                KS k;
                if (fout.is_open()) {
                    fout << pipeline.size() << endl << ksgroup.size() << endl;
                    for (auto t : pipeline) {
                        p.SavePipe(fout, t.second);
                        p_index++;
                    }
                    for (auto kk : ksgroup) {
                        k.SaveKS(fout, kk.second);
                        k_index++;
                    }
                    fout.close();
                }
            }
            else
                cout << "������� ����� ��� ��!\n";
            break;
        }
        case 5: {
            Pipe p;
            if (!pipeline.empty()) {
                p.ChangeStatusPipe(pipeline[p.GetPipeID(pipeline)]);
            }
            else {
                cout << "�������� ����� �� ������!\n";
            }
            break;
        }
        case 6: {
            KS k;
            if (!ksgroup.empty()) {
                k.ChangeW_Count(ksgroup[k.GetKS_ID(ksgroup)]);
            }
            else {
                cout << "�������� �� �� ������!\n";
            }
            break;
        }
        case 7: {
            if (!pipeline.empty()) {
                for (auto& p : pipeline)
                    cout << p.second; // ����� ������ ���� �� ������� 
            }
            else {
                cout << "�������� ����� �� ������!\n";
            }
            break;
        }
        case 8: {
            if (!ksgroup.empty()) {
                for (auto& k : ksgroup)
                    cout << k.second;// ����� ������ �� �� �������
            }
            else {
                cout << "�������� �� �� ������!\n";
            }
            break;
        }
        case 9: {
            if (!pipeline.empty()) {

                DeletePipe(pipeline);
            }
            else {
                cout << "�������� ����� �� ������!\n";
            }
            break;
        }
        case 10: {
            if (!ksgroup.empty()) {
                DeleteKS(ksgroup);
            }
            else {
                cout << "�������� �� �� ������!\n";
            }
            break;
        }
        case 11: {
            if (!pipeline.empty()) {
                int i = GetCorrectNumber("������� id �����", 0, 1111);
                if (i == 1) {

                }
                for (int index : UsingFilterForPipe(pipeline, CheckPipeId, i))
                    cout << pipeline[index];
            }
            else {
                cout << "�������� �� �� ������!\n";
            }
            break;
        }
        case 12: {
            if (!pipeline.empty()) {
                for (int index : UsingFilterForPipe(pipeline, CheckStatusRemont, true))
                    cout << pipeline[index];
            }
            else {
                cout << "�������� �� �� ������!\n";
            }
            break;
        }
        case 13: {
            if (!ksgroup.empty()) {
                string name;
                cout << "�������� ��:  ";
                cin.get();
                getline(cin, name);
                for (int index : UsingFilterForKS(ksgroup, CheckNameKS, name))
                    cout << ksgroup[index];
            }
            else {
                cout << "�������� �� �� ������!\n";
            }
            break;
        }
        case 14: {
            if (!ksgroup.empty()) {
                double i = GetCorrectNumber("������� ������� �������", 0.0, 100.0);
                for (int index : UsingFilterForKS(ksgroup, CheckUnworkKS, i))
                    cout << ksgroup[index];
            }
            else {
                cout << "�������� �� �� ������!\n";
            }
            break;
        }
        case 15: {
            if (!pipeline.empty()) {
                Pipe p;
                cout << "1 - ��������� ��� ����� �� ������;" << endl << "2 - ������� ����� ��� �������� �� ������;" << endl;
                int Choice = GetCorrectNumber(" ", 1, 2);
                if (Choice == 1) {
                    for (auto& pp : UsingFilterForPipe(pipeline, CheckStatusRemont, false))
                        p.ChangeStatusPipe(pipeline[pp]);
                }
                else {
                    cout << "��� ������ ������� 0, ��� ����������� 1" << endl;
                    while (1) {
                        int i = p.GetPipeID(pipeline);
                        if (!pipeline[i].remont)
                            p.ChangeStatusPipe(pipeline[i]);
                        int answer = GetCorrectNumber("�����? ", 0, 1);
                        if (answer == 1)
                            break;
                    }
                }
            }
            else {
                cout << "�������� ����� �� ������!\n";
            }
            break;
        }
        case 0: 
        {
            SaveMaxID();
            return 0;
        }
        default: {
            cout << "������ �����!\n";
        }
        }
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
