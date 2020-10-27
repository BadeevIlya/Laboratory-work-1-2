// seminar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Pipe.h"
#include "KS.h"





using namespace std;

//truba createpipe () {
//    truba pipe;
//    cout << "���������� ������ �����" << endl << endl;
//    while (1) {
//        cout << "������� �������\n";
//        cin >> pipe.diametr;
//        cout << "������� �����\n";
//        cin >> pipe.dlina;
//        if (cin.fail()) {
//            cin.clear();
//            cin.ignore(10000, '\n');
//        }
//        else if (pipe.diametr < 0 || pipe.dlina < 0) {
//            continue;
//        }
//        else break;
//    }
//    pipe.id = "";
//    pipe.remont = false;
//    return pipe;
//}

void editpipe(Pipe & edit) { // �������, ������� ���������� �� ������ �����
    edit.ChangeStatusPipe(); 
}


void edit_w_count(KS& k) {
    k.ChangeW_Count();
}

int GetCorrectNumber(int min, int max) {
    int n;
    while ((cin>>n).fail()|| n<min || n>max) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "������� �������� (" << min << "-" << max << "):";        
    }
    return n;
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
        << "0. �����\n"
        << "�������� ��������: ";

}

Pipe loadpipe(ifstream& fin) {
    Pipe t;
    t.LoadPipe(fin);
    return t;
}

KS loadKS(ifstream& fin) {
    KS k;
    k.LoadKS(fin);
    return k;
}
Pipe& SelectPipe(vector<Pipe>& p) {
    cout << "������� �����: " << endl;
    unsigned int index = GetCorrectNumber(1, p.size());
    return p[index - 1];
}

KS& SelectKS(vector<KS>& k) {
    cout << "������� �����: " << endl;
    unsigned int index = GetCorrectNumber(1, k.size());
    return k[index - 1];
}

int main(){
    setlocale(LC_ALL, "rus");
    vector <Pipe> pipeline;
    vector <KS> ksgroup;
    int marker_p = 0;
    int marker_k = 0;
    while (1) {
        printMenu();
        switch (GetCorrectNumber(0,8)) {
            case 1:
            {
                Pipe p;
                cin >> p;
                pipeline.push_back(p);
                break;
            }
            case 2:
            {
                KS k;
                cin >> k;
                ksgroup.push_back(k);
                break;
            }
            case 3:
            {
                ifstream fin("D:\ results.txt");
                if (fin.is_open()) {
                    Pipe p;
                    int p_count, ks_count;
                    fin >> p_count >> ks_count;
                    marker_p = p_count;
                    marker_k = ks_count;
                    while (p_count--)
                        pipeline.push_back(loadpipe(fin));
                    while (ks_count--)
                        ksgroup.push_back(loadKS(fin));
                    fin.close();
                }
                
                break;
            }
            case 4:
            {
                ofstream fout;
                fout.open("D:\ results.txt");
                if (fout.is_open()) {
                    fout << pipeline.size() << endl <<  ksgroup.size() << endl;
                    for (Pipe t : pipeline)
                        t.SavePipe(fout, t);
                    for (KS kk : ksgroup)
                        kk.SaveKS(fout, kk);
                    fout.close();
                }
                break;
            }
            case 5:
            {
                if (marker_p>0) {
                    editpipe(SelectPipe(pipeline)); // �������������� �������� "� �������"
                }
                else {
                    cout << "�������� ����� �� ������!\n";
                }
                
                break;
            }
            case 6:
            {
                if (marker_k > 0) {
                    edit_w_count(SelectKS(ksgroup));
                }
                else {
                    cout << "�������� �� �� ������!\n";
                }                
                break;
            }
            case 7:
            {
                if (marker_p > 0) {

                    cout << SelectPipe(pipeline); // ����� ������ ����� �� �������
                }
                else {
                    cout << "�������� ����� �� ������!\n";
                }
                break;
            }
            case 8:
            {
                if (marker_k > 0) {

                    cout << SelectKS(ksgroup); // ����� ������ �� �� �������
                }
                else {
                    cout << "�������� �� �� ������!\n";
                }
                break;
            }
            case 0:
            {
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
