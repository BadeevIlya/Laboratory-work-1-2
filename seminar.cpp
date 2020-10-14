// seminar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct truba {
    string id; // ������������� �����
    int dlina; // ����� 
    int diametr; // �������
    bool remont; // ������� "� �������"
};

struct KS {
    string id; // ������������� ��
    string name; // ���
    int vol; // ���������� �����
    int workvol; // ���������� ������� �����
    int effect; // ������������ 
};

truba createpipe () {
    truba pipe;
    cout << "���������� ������ �����" << endl << endl;
    while (1) {
        cout << "������� �������\n";
        cin >> pipe.diametr;
        cout << "������� �����\n";
        cin >> pipe.dlina;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (pipe.diametr < 0 || pipe.dlina < 0) {
            continue;
        }
        else break;
    }
    pipe.id = "";
    pipe.remont = false;
    return pipe;
}

void editpipe(truba&edit) { // �������, ������� ���������� �� ������ �����
    edit.remont = !edit.remont;
}



void loadpipe(ifstream&fin , truba & t) {
    fin >> t.diametr >> t.dlina;
}

void loadKS(ifstream& fin, KS& k) {
    fin  >> k.vol >> k.workvol >> k.name >> k.effect;
}

void outpipe(truba t) {
    cout << "��������� ������ �����:\n";
    cout << "�������: "<< t.diametr << endl <<"�����: "<< t.dlina << endl;
    
}

void outKS(KS k) {
    cout << "��������� ������ ��: \n";
    cout << "��������:" << k.name << endl << "���������� �����:" << k.vol << endl << "���������� ������� �����: " << k.workvol << endl 
        << "�������������:" << k.effect << endl ;
}

//bool CorrectTypeKS(int a, int b) { // ������� �������� �� ������������ �����
//   // return a and b >= 0;
//}

KS createKS() {
    KS ks;
    cout << "���������� ������ ��\n\n" ;
    cout << "������� ��������\n";
    cin.get();
    getline(cin, ks.name);
    while (1) {
        cout << "������� ���������� �����\n";
        cin >> ks.vol;
        cout << "������� ���������� ������� �����\n";
        cin >> ks.workvol;
        cout << "������� ������������ �� 0 �� 10\n";
        cin >> ks.effect;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');   
        }    
        else if ( ks.workvol < 0 || ks.workvol>ks.vol || ks.effect <0 || ks.effect>10) {
            continue;
        }
        else break;
    }
    ks.id = "";
    return ks;
}



void savepipe(ofstream&fout, truba t){
    fout << t.diametr << endl << t.dlina << endl;
}

void saveKS(ofstream& fout, KS k) {
    fout << k.vol << endl << k.workvol << endl << k.name << endl << k.effect << endl;
}

void editworkvol(KS& k) {
    while (1) {
        cout << "������� ����� ���������� ������� �����: \n";
        cin >> k.workvol;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (k.workvol > k.vol || k.workvol < 0) {
            continue;
        }
        else break;
    } 
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
        << "0. �����\n";

}

int main(){
    setlocale(LC_ALL, "rus");
    truba crpipe;
    KS crKS;
    bool p=false; // ������ ��� �����
    bool k=false; // ������ ��� ��
    while (1) {
        printMenu();
        int i = 0;
        while (1) {
            cin >> i;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else break;
        }
        switch (i) {
            case 1:
            {
                p = true;
                crpipe = createpipe(); // ������ ������ ����� � �������� �� � ���������� crpipe
                break;
            }
            case 2:
            {
                k = true;
                crKS = createKS();
                break;
            }
            case 3:
            {
                ifstream fin("D:\ results.txt");
                if (fin.is_open()) {
                    fin >> p >> k;
                    if (p) {
                        loadpipe(fin, crpipe);
                    }
                    if (k) {
                        loadKS(fin, crKS);
                    }
                    fin.close();
                }
                
                break;
            }
            case 4:
            {
                ofstream fout;
                fout.open("D:\ results.txt");
                if (fout.is_open()) {
                    fout << p << endl <<  k << endl;
                    if (p) {
                        savepipe(fout, crpipe);
                    }
                    if (k) {
                        saveKS(fout, crKS);
                    }
                    fout.close();
                }
                break;
            }
            case 5:
            {
                if (p == true) {
                    editpipe(crpipe); // �������������� �������� "� �������"
                }
                else {
                    cout << "�������� ����� �� ������!\n";
                }
                
                break;
            }
            case 6:
            {
                if (k == true) {
                    editworkvol(crKS);
                }
                else {
                    cout << "�������� �� �� ������!\n";
                }                
                break;
            }
            case 7:
            {
                if (p) {
                    outpipe(crpipe); // ����� ������ ����� �� �������
                }
                else {
                    cout << "�������� ����� �� ������!\n";
                }
                break;
            }
            case 8:
            {
                if (k) {
                    outKS(crKS); // ����� ������ �� �� �������
                }
                else {
                    cout << "�������� ����� �� ������!\n";
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

    
    
    
   
    
    
    /*KS crKS;
    bool k = true;
    while (1) {
        printMenuKS();
        int i = 0;       
        cin >> i;
        switch (i) {
            case 1: {
                bool k = true;
                crKS = createKS();
                break;
            }
            case 2: {
                increateKS(crKS);
                break;
            }
            case 3: {
                if (k == true) {
                    savecreateKS(crKS);
                }
                else {
                    cout << "�� �� �������!\n";
                }
                
                break;
            }
            case 4: {
                if (k == true) {
                    editworkvol(crKS);
                }
                else {
                    cout << "�� �� �������!\n";
                }               
                break;
            }
            case 5: {
                if (k == true) {
                    outcreateKS(crKS);                   
                }
                else {
                    cout << "�� �� �������!\n";
                }               
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                cout << "������ �����!\n";
            }
        
        
        }*/
        
    
    
    
    
    
    
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
